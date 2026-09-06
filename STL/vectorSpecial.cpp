#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
class Person
{
    public:
        std::string name;
        int id;
        Person(){};
        Person(std::string n,int i):name(n),id(i){};

};
int main()
{
    std::vector<Person> plist;
    Person p1("hello",10);
    Person p2;
    plist.push_back(p1);
    plist.push_back(p2);
    for(std::vector<Person> ::iterator it = plist.begin();it!=plist.end();it++)
    {
        std::cout<<it->name<<std::endl;
    }
    std::vector<Person*> plist_p;
    plist_p.push_back(&p1);
    plist_p.push_back(&p2);
     for(std::vector<Person*> ::iterator it = plist_p.begin();it!=plist_p.end();it++)
    {
        std::cout<<(*it)->name<<std::endl;
    }

    return 0;
}