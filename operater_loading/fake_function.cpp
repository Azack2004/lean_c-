#include<iostream>
#include<string>
class Person
{
    public:
        std::string name;
        int age;
        Person(int a,std::string s):age(a),name(s){}
};
class MyPrint
{
    public:
        void operator()(const Person & p)
        const{
            std::cout<<p.name<<std::endl;
            std::cout<<p.age<<std::endl;
        }
        int operator()(const int & a,const int & b)
        const{
            return a+b;
        }
};
int main()
{
    Person p(10,"二逼");
    //伪函数
    MyPrint m;
    m(p);
    //匿名函数对象
    int s = MyPrint()(10,23);
    std::cout<<s<<std::endl;

    return 0;
}