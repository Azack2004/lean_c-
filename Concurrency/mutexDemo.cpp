#include<iostream>
#include<thread>
#include<mutex>
 std::mutex mtx;//  全局锁
void func(int &a)
{  
    while(true)
    {   
        {
            std::lock_guard<std::mutex> guard(mtx);
            if(a>=10)
            {
                std::cout<<"reach max"<<std::endl;
                return ;
            }
            a+=1;
            std::cout<<"id:"<<std::this_thread::get_id()<<" - "<<a<<std::endl;   
            
        }
    }
    
}
int main()
{
    
    int a = 0;
    std::thread t(&func,std::ref(a));
    std::thread t1(&func,std::ref(a));
    t.join();
    t1.join();
    return 0;
}