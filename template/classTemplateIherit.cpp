#include<iostream>
template <typename T>
class Person
{
    public:
        T name;
        Person(T n):name(n){}
        void show()
        {
            std::cout<<name<<std::endl;
        }
};
class Child:public Person<int>
{
    public:
        Child(int n):Person(n){}
};
//
template <typename T,typename C>
class Child1:public Person<T>
{
    public:
        Child1(T n,C c):Person<T>(n)
        {
            a =c;
        }
        C a;
        void showChild()
        {
            std::cout<<a<<std::endl;
        }
};
int main()
{
   
    Child1<int,char> c(10,'a');
    c.show();
    c.showChild();
    return 0;
}