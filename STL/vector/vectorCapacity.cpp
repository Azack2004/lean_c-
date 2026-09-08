#include<iostream>
#include<vector>

void print(std::vector<int> &v)
{
    for(std::vector<int>::iterator it = v.begin();it!=v.end();it++)
    {
        std::cout<<(*it)<<std::endl;
    }
}
int main()
{
    std::vector<int> v1;
   for(int i=0;i<10;i++)
    {
        v1.push_back(i);
    }
    if(!v1.empty())
    {
        print(v1);
        std::cout<<"Capacity:"<<v1.capacity()<<std::endl;
        std::cout<<"Size:"<<v1.size()<<std::endl;
        for(int i=0;i<10;i++)
        {
            v1.push_back(i);
        }
    }
    std::cout<<"Capacity:"<<v1.capacity()<<std::endl;
    std::cout<<"Size:"<<v1.size()<<std::endl;
    v1.resize(22,0);
    std::cout<<"Capacity:"<<v1.capacity()<<std::endl;
    std::cout<<"Size:"<<v1.size()<<std::endl;
    print(v1);
    std::vector<int> v2 = v1;
    v1.resize(6);
    std::cout<<"Capacity:"<<v1.capacity()<<std::endl;
    std::cout<<"Size:"<<v1.size()<<std::endl;
    print(v1);
    return 0;
}