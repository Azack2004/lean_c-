#include<iostream>
#include<set>
void print(std::set<int> st)
{
    for(std::set<int>::iterator it=st.begin();it!=st.end();it++)
    {
        std::cout<<(*it)<<" ";
    }
    std::cout<<std::endl;

}
void print(std::multiset<int> st)
{
    for(std::multiset<int>::iterator it=st.begin();it!=st.end();it++)
    {
        std::cout<<(*it)<<" ";
    }
    std::cout<<std::endl;

}
int main()
{
    std::set<int> st;
    std::multiset<int> mst;
     //加入数据
    st.insert(101);
    st.insert(10);
    st.insert(103);
    st.insert(103);

    mst.insert(101);
    mst.insert(10);
    mst.insert(103);
    mst.insert(103);
    print(st);
    print(mst);
    std::cout<<st.size()<<std::endl;
    std::cout<<mst.size()<<std::endl;
    st.erase(103);
    //print(st);
    //st.erase(std::next(st.begin()));
    print(st);
    std::set<int>::iterator it = st.find(11);
    std::cout<<(it==st.begin())<<std::endl;
    if(it !=st.end())
    {
        std::cout<<*it<<std::endl;
    }
    std::multiset<int>::iterator mit = mst.find(103);
    if(mit != mst.end())
    {
        std::cout<<*mit<<std::endl;
    }
    
    return 0;
}