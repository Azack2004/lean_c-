#include<iostream>

#include"Person.hpp"
int main()
{
    Person<int ,std::string > p(19,"hello");
    p.show();
    return 0;
}