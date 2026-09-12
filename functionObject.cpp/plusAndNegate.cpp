#include<iostream>
#include<functional>
#include<vector>
#include<algorithm>
//negate取反仿函数
//plus加法仿函数
int main()
{
    std::negate<int> n;
    std::cout<<n(50)<<std::endl;
    std::plus<int> p;
    std::cout<<p(10,20)<<std::endl;
    std::greater<int> g;
    std::cout<<g(201,21)<<std::endl;
    std::vector<int> v;
    for(int i=0;i<10;i++)
    {
        v.push_back(i);
    }
    //std::sort(v.begin(),v.end(),g);
    std::sort(v.begin(),v.end(),std::greater<int>());
    for(auto it = v.begin();it!=v.end();it++)
    {
        std::cout<<*it<<" ";
    }
    std::cout<<std::endl;

    return 0;
}