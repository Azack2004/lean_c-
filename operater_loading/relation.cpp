#include<iostream>
#include<string>
class Person
{
    public:
        int age;
        std::string name;
        bool operator==(const Person & p)
        {
            return (this->age == p.age)&& (this->name==p.name);
        }
        bool operator>(const Person & p)
        {
            return this->age>p.age;
        }
        Person(int a,std::string s):age(a),name(s){}
        bool operator!=(const Person & p)
        {
            return ! (*this==p);
        }
};
int main()
{   
    Person p1(2,"n");
    Person p2(1,"p");
    Person p3(1,"p");
    std::cout<<(p3!=p2)<<std::endl;
    std::cout<<(p1>p2)<<std::endl;
    return 0;
}