#include<iostream>
template<typename T1,typename T2>class Person;

template<typename T1,typename T2>
void show(const Person<T1,T2> & p);//函数模版的实现

template<typename T1,typename T2>
class Person
{
    //全局函数类内实现
    friend void showP(Person<T1,T2> &p)//类外普通函数
    {
       std::cout<<p.a<<p.b<<std::endl; 
    }
//    template<typename U1,typename U2>
//     friend void show(const Person<U1,U2> & p);//函数模版的声明
//    friend void show(const Person<T1,T2> & p);//普通函数的实现
    friend void show<>(const Person<T1,T2> & p);//函数模版的声明
    private:
        T1 a;
        T2 b;
    public:
        
        Person(const T1 &m_a,const T2 &m_b):a(m_a),b(m_b){}
        
};
//全局函数类外实现
template<typename T1,typename T2>
void show(const Person<T1,T2> & p)//函数模版的实现
{
    std::cout<<p.a<<p.b<<std::endl;
}
int main()
{
    Person<int,char> p(10,'c');
    show<int,char>(p);
    showP(p);
    return 0;
}