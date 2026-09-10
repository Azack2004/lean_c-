#include<iostream>
#include<set>
int main()
{
    std::set<int> st;
    std::pair<std::set<int>::iterator ,bool> res = st.insert(1);
    if(res.second)
    {
        std::cout<<"成功"<<std::endl;
    }
    else{
        std::cout<<"失败"<<std::endl; 
    }
    std::cout<<*res.first<<std::endl;
    res = st.insert(1);
    if(res.second)
    {
        std::cout<<"成功"<<std::endl;
    }
    else{
        std::cout<<"失败"<<std::endl; 
    }
    std::multiset<int> ms;
    ms.insert(1);
    ms.insert(1);
    ms.insert(11);
    ms.insert(12);
    ms.insert(13);
    for(std::multiset<int>::iterator it=ms.begin();it!=ms.end();it++)
    {
        std::cout<<*it<<" ";
    }
    std::cout<<std::endl;
    return 0;
}