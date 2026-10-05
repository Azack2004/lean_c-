#include<iostream>
#include<future>
void slep(std::promise<int> p)
{
   
}

int main()
{
    std::promise<int> p;
    std::future<int> f = p.get_future();
    std::thread t(slep,std::move(p));
    try{
        std::cout<<f.get()<<std::endl;
    }
    catch(const std::exception &e)
    {
        std::cout<<"异常:"<<e.what()<<std::endl;
    }
    t.join();
    return 0;
}