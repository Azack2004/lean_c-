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
    std::vector<int > v;//默认构造
    for(int i=0;i<10;i++)
    {
        v.push_back(i);
    }
    //print(v);
    //通过区间构造
    std::vector<int> v2(v.begin(),v.end());
    //print(v2);
    std::vector<int> v3(10,20);
    //print(v3);
    std::vector<int> v4(v3);
    print(v4);
    return 0;
}