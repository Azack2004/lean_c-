#include <thread>
#include <atomic>
#include <memory>
#include <iostream>
#include <mutex>

std::mutex mtx;

template<typename T>
class lock_free_queue
{
private:
    struct Node
    {
        std::shared_ptr<T> data;
        std::atomic<Node*> next;
        
        // 默认构造函数（用来生成 dummy 节点）
        Node() : next(nullptr) {}
        
        // 带数据的构造函数（用来生成真正的数据节点）
        Node(const T& val) : data(std::make_shared<T>(val)), next(nullptr) {}
    };

    std::atomic<Node*> head;
    std::atomic<Node*> tail;

public:
    lock_free_queue()
    {
        // 初始化时，创建一个空的 dummy 节点，head 和 tail 都指向它
        Node* dummy = new Node();
        head.store(dummy);
        tail.store(dummy);
    }

    ~lock_free_queue()
    {
        // 简单的析构清理
        while(Node* old = head.load())
        {
            head.store(old->next);
            delete old;
        }
    }

    // 入队：在 tail 后面挂数据
    void push(const T& val)
    {
        Node* new_node = new Node(val);
        
        while(true)
        {
            Node* old_tail = tail.load();
            Node* next = old_tail->next.load();

            // 确保 old_tail 在读取 next 的过程中没有被其他线程改掉
            if(old_tail == tail.load())
            {
                if(next == nullptr) // 确认 tail 确实是最后一个节点
                {
                    // 尝试把新节点挂到 tail 的后面
                    Node* null_ptr = nullptr;
                    if(old_tail->next.compare_exchange_weak(null_ptr, new_node))
                    {
                        // 挂载成功！尝试把全局 tail 指针推进到新节点
                        tail.compare_exchange_strong(old_tail, new_node);
                        return;
                    }
                }
                else
                {
                    // 如果 tail 已经落后了（别的线程先挂了节点，但还没来得及更新 tail），
                    // 我们帮它把 tail 指针往前推一把，然后再重试
                    tail.compare_exchange_strong(old_tail, next);
                }
            }
        }
    }

    // 出队：从 head 弹出数据
    std::shared_ptr<T> pop()
    {
        while(true)
        {
            Node* old_head = head.load();
            Node* old_tail = tail.load();
            Node* next = old_head->next.load();

            if(old_head == head.load())
            {
                // 情况 1：head 和 tail 指向同一个节点
                if(old_head == old_tail)
                {
                    if(next == nullptr) 
                    {
                        return std::shared_ptr<T>(); // 队列真的为空
                    }
                    // tail 稍微落后了，帮它推进一下
                    tail.compare_exchange_strong(old_tail, next);
                }
                else // 情况 2：队列不为空，正常出队
                {
                    // 先把要取出的数据拿出来
                    std::shared_ptr<T> res = next->data;

                    // 尝试把 head 指向下一个节点（即把当前的 dummy 节点跨过去）
                    if(head.compare_exchange_weak(old_head, next))
                    {
                        // 成功弹出！
                        // 注意：这里暂时直接 delete 旧的 head（不考虑内存泄漏），
                        // 真实高并发下这里就是需要 Hazard Pointer 大显身手的地方。
                        delete old_head; 
                        return res;
                    }
                }
            }
        }
    }
};

int main()
{
    lock_free_queue<int> q;
    
    std::thread t([&q](){
        for(int i = 0; i < 1200; i++)
        {
            q.push(i);
        }
    });
    
    std::thread t1([&q](){
        std::shared_ptr<int> upr;
        int count = 0;
        while(count < 400)
        {
            upr = q.pop();
            if(upr)
            {
                std::lock_guard<std::mutex> lock(mtx);
                count++;
                std::cout <<std::this_thread::get_id()<<":"<< *upr << std::endl;
            }
        }
    });
    std::thread t2([&q](){
        std::shared_ptr<int> upr;
        int count = 0;
        while(count < 800)
        {
            upr = q.pop();
            if(upr)
            {
                std::lock_guard<std::mutex> lock(mtx);
                count++;
                std::cout <<std::this_thread::get_id()<<":"<< *upr << std::endl;
            }
        }
    });
    t.join();
    t1.join();
    t2.join();
    
    return 0;
}
