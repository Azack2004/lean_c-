#include<iostream>
#include<thread>
#include<queue>
#include<memory>
#include<condition_variable>
template<typename T>
class threadsafe_queue
{
    private:
        mutable std::mutex mut;
        std::queue<T> data_queue;
        std::condition_variable data_cond;
    public:
    threadsafe_queue()
    {}
    void push(T data)
    {
        std::lock_guard<std::mutex> lk(mut);
        data_queue.push(std::move(data));
        data_cond.notify_one(); // 1
    }
    void wait_and_pop(T& value) // 2
    {
        std::unique_lock<std::mutex> lk(mut);
        data_cond.wait(lk,[this]{return !data_queue.empty();});
        value=std::move(data_queue.front());
        data_queue.pop();
    }
    std::shared_ptr<T> wait_and_pop() // 3
    {
        std::unique_lock<std::mutex> lk(mut);
        data_cond.wait(lk,[this]{return !data_queue.empty();}); //
        std::shared_ptr<T> res(
        std::make_shared<T>(std::move(data_queue.front())));
        data_queue.pop();
        return res;
    }
    bool try_pop(T& value)
    {
        std::lock_guard<std::mutex> lk(mut);
        if(data_queue.empty())
        return false;
        value=std::move(data_queue.front());
        data_queue.pop();
        return true;
    }
    std::shared_ptr<T> try_pop()
    {
        std::lock_guard<std::mutex> lk(mut);
        if(data_queue.empty())
        return std::shared_ptr<T>(); // 5
        std::shared_ptr<T> res(
        std::make_shared<T>(std::move(data_queue.front())));
        data_queue.pop();
        return res;
    }
    bool empty() const
    {
        std::lock_guard<std::mutex> lk(mut);
        return data_queue.empty();
    }
};
void add(threadsafe_queue<int> &q,int n)
{
    
    for(int i=0;i<n;i++)
    {
        q.push(i);
    }
}
void pop(threadsafe_queue<int> &q)
{   
    int a;
    while(!q.empty())
    {
        q.wait_and_pop(a);
        std::cout<<std::this_thread::get_id()<<":"<<a<<std::endl;
    }
}
int main()
{
    threadsafe_queue<int> q;
    std::thread t(add ,std::ref(q),100);
    std::thread t1(pop ,std::ref(q));
    std::thread t2(pop,std::ref(q));
    t.join();
    t1.join();
    t2.join();
    return 0;
}