#include<iostream>
#include<thread>
#include<mutex>
#include<stack>
#include<condition_variable>
#include<memory>
template<typename T>
class ThreadSafeStack
{
    private:    
        std::stack<T> s;
        std::mutex mtx;
        std::condition_variable cv;
    public:
        explicit ThreadSafeStack()=default;
        void push(T a)
        {
            {
                std::unique_lock lock(this->mtx);

                s.push(a);
            }
            std::cout<<std::this_thread::get_id()
            <<":"<<a<<std::endl;
            cv.notify_one();
        }
        void try_pop(T & a)
        {
            std::unique_lock lock(this->mtx);
            cv.wait(lock,[this](){
                return !s.empty();
            });
            a = s.top();
            s.pop();
        }
        std::shared_ptr<T> wait_pop()
        {
            std::unique_lock lock(this->mtx);
            cv.wait(lock,[this](){
                return !s.empty();
            });
            std::shared_ptr<T> spr=std::make_shared<T>(s.top());
            s.pop();
            return spr; 
        }
};
template<typename T>
void add(ThreadSafeStack<T> &s)
{
    for(int i=0;i<50;i++)
    {
        s.push(i);
    }
}
template<typename T>
void shared_pop(ThreadSafeStack<T> &s)
{
    std::shared_ptr<int> spr;
    for(int i=0; i<25;i++)
    { 
        spr = s.wait_pop();
        std::cout<<"shared_pop:"<<*spr<<std::endl;
    }
}

int main()
{
    ThreadSafeStack<int> s;
    std::thread t(add<int>,std::ref(s));
    std::thread t2(shared_pop<int>,std::ref(s));
    
    for(int i=0; i<25;i++)
    {
        int a = 0;
        s.try_pop(a);
        std::cout<<"pop:"<<a<<std::endl;
    }
    t.join();
    t2.join();
    return 0;
}