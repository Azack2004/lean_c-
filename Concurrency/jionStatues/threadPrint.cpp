#include<thread>
#include<iostream>
#include<mutex>
#include<condition_variable>
static int status = 0;
std::condition_variable cv_a;
std::condition_variable cv_b;
std::condition_variable cv_c;
std::mutex mtx;
void printA()
{
    std::cout<<std::this_thread::get_id()<<std::endl;
    std::unique_lock lock(mtx);
    cv_a.wait(lock ,[](){
        return status==0;
    });
    std::cout<<"a"<<std::endl;
    status++;
    cv_b.notify_one();
}
void printB()
{
    std::cout<<std::this_thread::get_id()<<std::endl;
    std::unique_lock lock(mtx);
    cv_b.wait(lock ,[](){
        return status==1;
    });
    std::cout<<"b"<<std::endl;
    status++;
    cv_c.notify_one();
}
void printC()
{
    std::cout<<std::this_thread::get_id()<<std::endl;
    std::unique_lock lock(mtx);
    cv_c.wait(lock ,[](){
        return status==2;
    });
    std::cout<<"c"<<std::endl;
    status =0;
    cv_a.notify_one();
}
int main()
{
    std::thread ta(printA);

    std::thread tb(printB);
    std::thread tc(printC);
    tb.join();
    tc.join();
    ta.join();

    return 0;
}