#include<iostream>
#include<thread>
#include<condition_variable>
#include<mutex>
#include<queue>
#include<chrono>
std::mutex mtx;
std::condition_variable cv_not_empty;
std::queue<int> q;

void push(int a)
{   int b=0;
    while(b<5)
    {
        std::cout<<std::this_thread::get_id()<<std::endl;
        std::unique_lock qmtx(mtx);
        q.push(a);
        std::cout<<"add:"<<a<<std::endl;
        qmtx.unlock();
        a++;
        cv_not_empty.notify_one();
        b++;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    
}
void pop()
{
    int a=0;
    while(a<5)
    {
        std::cout<<std::this_thread::get_id()<<std::endl;
        std::unique_lock qmtx(mtx);
        cv_not_empty.wait(qmtx,[](){
            return !q.empty();
        });
        std::cout<<q.front()<<std::endl;
        q.pop();
        a++;
    }
    
}
int main()
{
    std::thread t(push,10);
    pop();
    t.join();
    std::cout<<"main:"<<std::this_thread::get_id()<<std::endl;
    return 0;
}