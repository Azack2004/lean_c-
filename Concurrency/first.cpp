#include<iostream>
#include<thread>
#include<chrono>
class Print
{
    public:
        int& i;
        
        Print(int &a):i(a){};
        void operator()()
        {
            for(int a=0;a<100;a++)
            {
                std::cout<<i+1;
            }
        
        } 
};

int main()
{
    int a =10;
    Print p(a);
    std::thread t(p);
    t.detach();
    for(int a=0;a<100;a++)
            {
                std::cout<<a+1;
            }
    std::this_thread::sleep_for(std::chrono::seconds(1));
    return 0;
}