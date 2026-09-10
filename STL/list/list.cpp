#include<iostream>
#include<list>
#include<algorithm>
void print(const std::list<int> &l)
{
    for(std::list<int>::const_iterator it = l.begin();it!=l.end();it++)
    {
        std::cout<<(*it)<<" ";
    }
    std::cout<<std::endl;
}
bool compare(int v1 ,int v2)
{
    return v1>v2;
}
int main()
{
    std::list<int> lt;
    lt.push_back(10);
    lt.push_back(11);
    lt.push_back(12);
    lt.push_back(13);
   // print(lt);
    std::list<int> l(10,1);
    //print(l);
    //l = lt;
    lt.swap(l);
    //print(l);
    lt.resize(3,0);
    //print(lt);
    lt.push_back(100);
    print(lt);
    lt.push_front(101);
    lt.push_front(190);
    print(lt);
    lt.pop_front();
    print(lt);
    lt.insert(std::next(lt.begin(),2),1000);
    lt.push_front(1000);
    print(lt);
    lt.erase(std::prev(lt.end()));
    print(lt);
    lt.remove(1000);
    print(lt);
    std::cout<<lt.front()<<std::endl;
    std::cout<<lt.back()<<std::endl;
    lt.insert(std::prev(lt.begin()),1000);
    print(lt);
    lt.reverse();
    print(lt);
    lt.sort(compare);
    print(lt);
   
    return 0;
}