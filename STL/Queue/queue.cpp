#include<iostream>
#include<queue>
class Person
{
    public:
        int age;
        Person(){};
        Person(int a):age(a){};
};
std::ostream & operator<<(std::ostream & c,const Person & a)
{
    c<<a.age;
    return c;
}
int main()
{
    std::queue<Person> que;
    for(int i =0 ;i<5;i++)
    {
        Person p(i);
        que.push(p);
    }
    std::cout<<que.size()<<std::endl;
    // for(int i =0 ;i<5;i++)
    //  {
    //     std::cout<<que.front()<<" ";
    //     que.pop();
    //  }
    while(!que.empty())
    {
        std::cout<<que.front()<<std::endl;
        que.pop();
    }
    std::cout<<que.size()<<std::endl;
    return 0;
}