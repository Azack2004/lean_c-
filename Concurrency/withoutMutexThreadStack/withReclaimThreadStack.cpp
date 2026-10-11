#include<thread>
#include<atomic>
#include<memory>
#include<iostream>
#include<mutex>
#include<assert.h>
std::mutex log_mtx;
template<typename T>
class lock_free_stack
{
    private:
        struct node
    {
        std::shared_ptr<T> data; // 1 指针获取数据
        node* next;
        node(T const& data_):data(std::make_shared<T>(data_)){} // 2 让std::shared_ptr指向新分配出来的T
        
    };    
        std::atomic<node*> head{nullptr};
        
        std::atomic<unsigned> threads_in_pop{0}; // 1 原子变量
        std::atomic<node*> to_be_deleted{nullptr};
        
        bool view = false;
        static void delete_nodes(node* nodes,bool view)
        {
            
            while(nodes)
            {
                node * temp = nodes->next;
                if(view)
                {
                std::lock_guard<std::mutex> lock(log_mtx);
                std::cout << "  [🧹 回收内存] 节点 " << nodes 
                          << " (值: " << (nodes->data ? *nodes->data : -1) 
                          << ") 被真正 delete 销毁！" << std::endl;
                }
                delete nodes;
                nodes =  temp;
            }
        };
        void try_reclaim(node* old_head){
            // 关键防护：如果 old_head 为空，直接处理计数器并返回，防止解引用空指针
            if (!old_head)
            {
                --threads_in_pop;
                return;
            }
        
            if(threads_in_pop==1)
            {
                // 1. 原子操作：把待回收链表整体“打包抢走”，同时把全局指针置空！
                node* nodes_to_delete=to_be_deleted.exchange(nullptr);
                
                if (nodes_to_delete) {//view
                std::lock_guard<std::mutex> lock(log_mtx);
                std::cout << "  [💥 独占拿走] 线程 " << std::this_thread::get_id() 
                          << " 成功打包拿走待回收链表！" << std::endl;
                }
                if(!--threads_in_pop)
                {
                    delete_nodes(nodes_to_delete,view);
                }
                else if(nodes_to_delete)
                {
                    if(1)//view
                    {
                    std::lock_guard<std::mutex> lock(log_mtx);
                    std::cout << "  [⚠️ 撤回动作] 抢占后发现有新线程插队，重新挂回待回收链表！" << std::endl;
                    }
                    // 💥 发现有新线程插队进来了！放弃删除，重新挂回去！
                    chain_pending_nodes(nodes_to_delete); 
                }
                if(view)
                {
                std::lock_guard<std::mutex> lock(log_mtx);
                std::cout << "  [🧹 回收内存] 节点 " << old_head 
                          << " (值: " << (old_head->data ? *old_head->data : -1) 
                          << ") 被真正 delete 销毁！" << std::endl;
                }
                delete old_head; // 安全释放当前节点
            }
            else
            {
                chain_pending_node(old_head);
                --threads_in_pop;
            }          
        };
        void chain_pending_nodes(node* nodes)
        {
            node* last=nodes;
            //nodes头节点
            while(node* const next=last->next)
            {
                last = next;
            }
            //last是尾节点
            chain_pending_nodes(nodes,last);
        };
        void chain_pending_nodes(node* first,node* last)
        {
            last->next = to_be_deleted;
            while(!to_be_deleted.compare_exchange_weak(last->next,first));
             // CAS 成功后再打印日志
            if(view)
            {
            std::lock_guard<std::mutex> lock(log_mtx);
            std::cout << "  [📌 挂载待回收] 线程 " << std::this_thread::get_id()
                    << " 将节点段 [" << first << " ... " << last << "]"
                    << " 挂入 to_be_deleted 链表！" << std::endl;
            }
        };
        void chain_pending_node(node* n)
        {
            chain_pending_nodes(n,n);
        }
    public:
        lock_free_stack()=default;
         ~lock_free_stack()
        {   
            if(view)
            {
                std::lock_guard<std::mutex> lock(log_mtx);
                std::cout << "\n=== 析构函数触发：清扫剩余内存 ===" << std::endl;
            }
            delete_nodes(head.load(),view);
            delete_nodes(to_be_deleted.load(),view);
        }
        void push(T const& data)
        {
            node* const new_node=new node(data);
            new_node->next=head.load();
            while(!head.compare_exchange_weak(new_node->next,new_node));
        }
        std::shared_ptr<T> pop()
        {
            ++threads_in_pop; // 2 在做事之前，计数值加1
            node* old_head=head.load();
            while(old_head && !head.compare_exchange_weak(old_head,old_head->next)); 
            std::shared_ptr<T> res;
            if(old_head)
            {
                res.swap(old_head->data); // 3 弹出数据
            }
            try_reclaim(old_head); // 4 将空node壳子挂回删除列表
            return res;
        }
};
int main()
{
   
    lock_free_stack<int> stack;
    int ToTal = 1000000;
    int part = 45000;
    long long sum1 = 0;
    long long sum2 = 0;
    long long popsum1 = 0;
    long long popsum2=0;
    long long popsum3=0;
    std::thread t([&stack,ToTal,&sum1](){
        for(int i=0;i<ToTal;i++)
        {
            stack.push(i);
            sum1+=i;
        }
    });
    std::thread t3([&stack,ToTal,&sum2](){
        for(int i=0;i<ToTal;i++)
        {
            stack.push(i);
            sum2+=i;
        }
    });
    std::thread t1([&stack,ToTal,part,&popsum1](){
         std::shared_ptr<int> upr;
         int count = 0;
         while (count < 2 * (ToTal - part)) {
            upr = stack.pop();
            if (upr) {
                popsum1 += *upr;
                count++;
            } else {
                // 如果暂时为空，可以稍微让出CPU，避免过度自旋
                std::this_thread::yield();
            }
        }
    });
    std::thread t2([&stack,part,&popsum2](){
        std::shared_ptr<int> upr;
        int count = 0;
        while (count < part) {
            upr = stack.pop();
            if (upr) {
                popsum2 += *upr;
                count++;
            } else {
                std::this_thread::yield();
            }       
        }
    });
    std::thread t4([&stack,part,&popsum3](){
        std::shared_ptr<int> upr;
        int count = 0;
        while (count < part) {
            upr = stack.pop();
            if (upr) {
                popsum3 += *upr;
                count++;
            } else {
                std::this_thread::yield();
            }       
        }
    });
    t.join();
    t3.join();
    t1.join();
    t2.join();
    t4.join();
    
    
    std::cout<<sum1+sum2<<std::endl;
    std::cout<<popsum1+popsum2+popsum3<<std::endl;
    assert((sum1+sum2)==(popsum1+popsum2+popsum3));
    return 0;
}