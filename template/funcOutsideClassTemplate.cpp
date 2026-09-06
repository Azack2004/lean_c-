#include<iostream>
template<typename T1,typename T2>
class Person
{   
    public:
        Person(T1 n,T2 c);
        
        T1 name;
        T2 age;
        void show();
};
template<typename T1,typename T2>
Person<T1 ,T2>::Person(T1 n,T2 c)
{
    name = n;
    age = c;
      
}
//成员函数的类外实现
template<typename T1,typename T2>
void  Person<T1,T2>::show()
{
    std::cout<<name<<std::endl;
    std::cout<<age<<std::endl;
}
int main()
{
    Person<int ,char> p(10,'c');
    p.show();
    return 0;
}