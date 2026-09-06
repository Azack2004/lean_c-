#include<iostream>
class Person
{
    public:
        int age;
        std::string name;
    Person(int age,std::string name){
            this->age=age;
            this->name = name;
    }
    // bool operator==(Person &p)
    // {
    //     if(this->age==p.age&&this->name==p.name)
    //     {
    //         return true;
    //     }
    //     return false;
    // }

};
template<typename T>
T show(T a ,int len)
{
    for(int i =0;i<len;i++)
    {
        auto b = a[i];
        std::cout<<b<<" ";
    }
    std::cout<<std::endl;
    return 0;
}
//模版的局限性
//有些特殊的数据类型，需要特殊的处理
template<class T>
bool same(T &a,T &b)
{
    if(a==b){
        return true;
    }
    return false;
}
//利用具体化的Person的版本实现代码，具体化优先调用
template<> bool same(Person &p1,Person &p2)
{
    if(p1.age==p2.age&&p1.name==p2.name)
        {
            return true;
        }
        return false;
    
}
int main()
{
    int a[9]={0,2,43,78,4,5,7};
    show(a,sizeof(a)/sizeof(a[0]));
    int c =0;
    int b = 0;
    std::cout<<same(c,b)<<std::endl;
    Person p1(10,"2");
    Person p2(10,"2");
    
    std::cout<<same(p1,p2)<<std::endl;
    return 0;
}