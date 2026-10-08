#include<iostream>
#include<memory>
#include<mutex>
#include<thread>
#include<condition_variable>

template <typename T>
class queue
{
    private:
        struct Node
        {
            std::shared_ptr<T> data;
            std::unique_ptr<Node> next;
            Node()=default;
            Node(T _data):data(std::make_shared<T>(std::move(_data))),next(nullptr){}
            ~Node()=default;
        };
        std::unique_ptr<Node> head;
        Node* tail;
        std::mutex head_mutex;
        std::mutex tail_mutex;
        Node* get_tail()
        {
            std::lock_guard tlock(tail_mutex);
            return tail;
        }
    public:
        queue(){
            head = std::make_unique<Node>();
            tail = head.get();
        }
        queue(const queue& q)=delete;
        queue& operator=(const queue&q)=delete;
        ~queue(){

        }
        void push(T data)
        {
            std::unique_ptr<Node> new_data = std::make_unique<Node>(std::move(data));
            Node* new_tail = new_data.get();
            std::lock_guard tlock(tail_mutex);
            tail->next = std::move(new_data);
            tail = new_tail;
        }
        std::shared_ptr<T> pop()
        {
            std::lock_guard hlock(head_mutex);
            if(head.get()==get_tail())
            {
                return std::shared_ptr<T>();
            }
            //1.取数据
            std::shared_ptr<T> res = head->next->data;

            // 2. 移除旧哨兵 head，让 head->next 成为新的哨兵！
            std::unique_ptr<Node> old_head = std::move(head);
            head = std::move(old_head->next); // 👈 这一步直接把链表接上了，没有断链！

            // 3. 把新哨兵里面的 data 置为空（让它变成纯粹的哨兵）
            head->data.reset();
            return res; 
        }  
     
};
void add(queue<int> &q,int n)
{
    for(int i=0;i<n;i++)
    {
        q.push(i);
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(1));
}
void pop(queue<int> &q, int expected_count)
{  
     int popped_count = 0;
     while (popped_count < expected_count) {
        auto upr = q.pop();
        if (upr) {
            std::cout << "[Thread " << std::this_thread::get_id() << "] Popped: " << *upr << std::endl;
            popped_count++;
        } else {
            // 如果没抢到数据，稍微让出 CPU 时间片，不要硬 CPU 100% 轮询
            std::this_thread::yield();
        }
    }
    
}
int main()
{
    queue<int> q;
    //===压力测试===
    std::thread t(add ,std::ref(q),100);
    std::thread t1(pop ,std::ref(q),54);
    std::thread t2(pop ,std::ref(q),46);
    t.join();
    t1.join();
    t2.join();
    return 0;
}