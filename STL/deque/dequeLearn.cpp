#include<iostream>
#include<deque>
#include<algorithm>
void print(std::deque<int> &dq)
{
    for(int i=0;i<dq.size();i++)
    {
        std::cout<<dq[i]<<" ";

    }
    std::cout<<std::endl;
}
void printf(const std::deque<int> &dq)
{
    for(std::deque<int>::const_iterator it=dq.begin();it!=dq.end();it++)
    {
        std::cout<<*it<<" ";
    }
    std::cout<<std::endl;
}
int main()
{
    std::deque<int> dq;
    for(int i=0;i<10;i++)
    {
        dq.push_front(i);
    }
    //print(dq);
    std::deque<int> dq1(dq.begin()+1,dq.end()-1);
    //printf(dq1);
    std::deque<int> dq2(10,11);
    printf(dq2);
    dq2.assign(dq.begin()+2,dq.end()-2);
    printf(dq2);
    std::cout<<dq2.size()<<std::endl;
    std::cout<<dq2.empty()<<std::endl;
    dq2.pop_front();
    print(dq2);//无返回值
    dq2.insert(dq2.begin()+1,dq1.begin(),dq1.end());
    print(dq2);
    dq2.erase(dq2.begin());
    print(dq2);
    // dq2.erase(dq2.begin()+1,dq2.end());
    // print(dq2);
    std::cout<<dq2.front()<<std::endl;
     std::cout<<dq2.back()<<std::endl;
     for(int i=0;i<dq2.size();i++)
     {
        std::cout<<dq2.at(i)<<" ";
     }
     std::cout<<std::endl;
     //对于支持随机访问的容器，都可以使用sort进行排序。deque，vector
     std::sort(dq2.begin(),dq2.end());
     print(dq2);

    return 0;
}