#include<iostream>
#include<vector>
#include<algorithm>
class MyAdd
{
    public:
    int count;
        MyAdd(){this->count=0;};
        int operator()(const int&a,const int &b )
        {
            count++;
            return a+b;
        }
};
class Great
{
    public:
        bool operator()(int v)
        {
            return v>5;
        }
};
class more
{
    public:
        bool operator()(int v,int v2)
        {
            return v>v2;
        }
};
int main()
{
    MyAdd a;
    std::cout<<a(10,29)<<std::endl;
    std::cout<<a.count<<std::endl;
    std::vector<int> v;
    for(int i=0;i<10;i++)
    {
        v.push_back(i);
    }
    //std::vector<int>::iterator it =  std::find_if(v.begin(),v.end(),Great());
    std::vector<int>::iterator it = std::find_if(v.begin(),v.end(),[](int v){return v>5; });
    if(it==v.end())
    {
        std::cout<<"没找到"<<std::endl;
    }
    else{
        std::cout<<*it<<std::endl;
    }
    //std::sort(v.begin(),v.end(),[](int v1,int v2){return v1>v2;});
    std::sort(v.begin(),v.end(),more());
    for(auto it = v.begin();it!=v.end();it++)
    {
        std::cout<<*it<<" ";
    }
    std::cout<<std::endl;
    return 0;
}