#include<iostream>
#include<set>
class MyCompare
{
    public:
        bool operator()(int v1,int v2)
        const{
            return v1>v2;
        }
};
class Person
{
    public:
        int age;
        std::string name;
        Person(int a,std::string n):age(a),name(n){};

};
class PersonCompare
{
    public:
        bool operator()(const Person &p1,const Person&p2)
        const{
            return p1.age>p2.age;
        }
};

void print(const std::set<int> &st)
{
    for(std::set<int>::const_iterator it=st.begin();it!=st.end();it++)
    {
        std::cout<<*it<<" ";
    }
    std::cout<<std::endl;
}
void print(const std::set<int,MyCompare> &st)
{
    for(std::set<int,MyCompare>::const_iterator it=st.begin();it!=st.end();it++)
    {
        std::cout<<*it<<" ";
    }
    std::cout<<std::endl;
}
void print(const std::set<Person,PersonCompare> &st)
{
    for(std::set<Person,PersonCompare>::const_iterator it=st.begin();it!=st.end();it++)
    {
        std::cout<<it->age<<" ";
        std::cout<<it->name<<" ";
    }
    std::cout<<std::endl;
}
int main()
{
    //只能在创建时候改变排序规则
    std::set<int> st;
    st.insert(100);
    st.insert(12);
    st.insert(15);
    st.insert(120);
    st.insert(121);
    print(st);

    std::set<int,MyCompare> st1;
    st1.insert(100);
    st1.insert(12);
    st1.insert(15);
    st1.insert(120);
    st1.insert(121);
    print(st1);
    //自定义的数据类型需要制定排序规则
    std::set<Person,PersonCompare> st3;
    Person p1(18,"ni");
    Person p2(12,"ni");
    Person p3(15,"ni");
    Person p4(19,"ni");
    Person p5(18,"niq");
    st3.insert(p1);
    st3.insert(p2);
    st3.insert(p3);
    st3.insert(p4);
    st3.insert(p5);
    print(st3);
    return 0;
}