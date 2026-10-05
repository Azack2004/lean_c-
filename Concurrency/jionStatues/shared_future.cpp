#include<iostream>
#include<future>
#include<thread>
#include<vector>
void text(std::promise<int> p)
{
    std::cout<<"生成数据。。。"<<std::endl;
    p.set_value(100);
}
void deal(std::shared_future<int> s,int a,std::promise<int> p)
{
    int res = s.get();
    std::this_thread::sleep_for(std::chrono::seconds(1));
    p.set_value(res*a);

}
int main()
{
    std::promise<int> p;
    std::shared_future<int> sf =p.get_future().share();
    std::vector<std::thread> v;
    std::vector<std::future<int>> results;
    text(std::move(p));
    for(int i=0;i<3;i++)
    {
        std::promise<int> p1;
        std::future<int> s = p1.get_future();
        v.emplace_back(deal ,sf,i,std::move(p1));
        results.push_back(std::move(s));
    }
    for(auto &it :results)
    {
        std::cout<<it.get()<<std::endl;
    }
    for(auto &i:v)
    {
        i.join();
    }
    return 0;
}