#include<iostream>
#include<thread>
#include<atomic>
#include<mutex>
std::mutex mtx;
void addAndReset(std::atomic<int> &counter)
{
    for(int i=0;i<100;i++)
    {
        int old_value = counter.load();
        int new_value ;
        do
        {
            new_value = (old_value==20)? 0: old_value+1;
        } while (!counter.compare_exchange_weak(old_value,new_value)); 
    std::lock_guard lock(mtx);
    std::cout<<counter<<std::endl;
    std::cout<<std::this_thread::get_id()<<std::endl;
    }
}
int main()
{
    std::atomic<int> counter(0);
    std::thread t(addAndReset,std::ref(counter));
    std::thread t1(addAndReset,std::ref(counter));
    t.join();
    t1.join();
    std::cout<<counter.is_lock_free()<<std::endl;
    return 0;
}