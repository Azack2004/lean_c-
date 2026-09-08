#include<iostream>
#include<algorithm>
#include<vector>

int main()
{
    std::vector<std::vector<int>> vlist;
    std::vector<int> v1;
    std::vector<int> v2;
    std::vector<int> v3;
    std::vector<int> v4;
    for(int i=0;i<16;i++)
    {
        if(i/4 ==0)
        {
            v1.push_back(i);
        }
        if(i/4==1)
        {
            v2.push_back(i);
        }
        if(i/4==2)
        {
            v3.push_back(i);
        }
        if(i/4==3)
        {
            v4.push_back(i);
        }
        
    }
    vlist.push_back(v1);
    vlist.push_back(v2);
    vlist.push_back(v3);
    vlist.push_back(v4);
    //通过大容器把所有的数据遍历
    for(std::vector<std::vector<int>>::iterator itBig = vlist.begin();itBig!=vlist.end();itBig++)
    {
        for(std::vector<int>::iterator it = (*itBig).begin();it!=(*itBig).end();it++)
        {
            std::cout<<(*it)<<" ";
        }
        std::cout<<std::endl;
    }
    return 0;
}