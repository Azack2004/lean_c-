#include<iostream>
#include<thread>
#include<chrono>
class thread_guard
{
    public:
        std::thread &t;
        thread_guard()=delete;
        thread_guard(std::thread& _t):t(_t){};
        ~thread_guard()
        {
            if(t.joinable())
            {
                t.join();
            }
        }
};
class Func
{
    public:
        int &a;
        Func(int &i):a(i){};
        void operator()()
        {
            add();
        }
        void add()
        {
            for(int i=0;i<100;i++)
            {
                this->a+=1;
            }
            std::cout<<std::endl;
        }
};

int main()
{

    int a = 10;
    Func f(a);
    {
    std::thread t(f);

    thread_guard tg(t);
    }
   
    std::cout<<"a:"<<a<<std::endl;

    return 0;
}