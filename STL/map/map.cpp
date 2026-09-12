#include<iostream>
#include<map>
class Compare
{
    public:
        bool operator()(const int&v1,const int &v2)
        const{
            return v1>v2;
        }
};//声明
class Person
{
    public:
        int age;
        std::string name;
        Person(int a,std::string n):age(a),name(n){};
};
class PeronsCompare
{
    public:
        bool operator()(const Person&p1,const Person&p2)const
        {
            return p1.age>p2.age;
        }
};
void print(const std::map<int,int,Compare>& map)
{
    for(std::map<int,int,Compare>::const_iterator it=map.begin();it!=map.end();it++)
    {
        std::cout<<(*it).first<<":"<<(*it).second<<" ";
    }
    std::cout<<std::endl;
}
void print(const std::map<Person,int,PeronsCompare>& map)
{
    for(std::map<Person,int,PeronsCompare>::const_iterator it=map.begin();it!=map.end();it++)
    {
        std::cout<<(*it).first.age<<"&"<<(*it).first.name<<":"<<(*it).second<<" ";
    }
    std::cout<<std::endl;
}
int main()
{
    std::map<int,int,Compare> map;
   
    map.insert(std::pair<int,int> (1,10));
    map.insert(std::pair<int,int> (2,20));
    map.insert(std::pair<int,int> (3,30));
    map.insert(std::pair<int,int> (5,50));
    map.insert(std::pair<int,int> (4,40));
    print(map);
    std::cout<<map.size()<<std::endl;
    map.erase(std::next(map.begin()));
    print(map);
    map.insert(std::make_pair(2,20));
    print(map);
    map.insert(std::map<int,int>::value_type(6,170));
    print(map);
    map[7]=10;
    print(map);
    std::cout<<map[8]<<std::endl;
    map.erase(8);
    print(map);
    std::map<int,int>::iterator it= map.find(3);
    if(it!=map.end())
    {
        std::cout<<(*it).second<<std::endl;
    }
    std::map<Person,int,PeronsCompare> m;
    for(int i =0;i<5;i++)
    {
        Person p(i," ");
        m.insert(std::pair(p,i));
    }
    print(m);
    return 0;
}