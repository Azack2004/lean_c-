#include<iostream>
//深拷贝和浅拷贝
class Person
{
    public:
    Person()
    {
        std::cout<<"无参构造函数"<<std::endl;
    }
    Person(const int &n,int h)
    {
        id = n;
        height = new int(h);
       
        std::cout<<"有参构造函数"<<std::endl;
    }
    //浅拷贝
    // Person(const Person & p)
    // {
    //     id = p.id;
    //     height = p.height;
    //     std::cout<<"拷贝构造函数"<<std::endl;
    // }
    //深拷贝
    Person(const Person & p)
    {
        id = p.id;
        height = new int(*p.height);
    }
    ~Person()
    {   
        //堆区开辟的数据释放
        if(height!=nullptr)
        {
            delete height; 
            height = nullptr;
        }
       
        std::cout<<"析构函数"<<std::endl;
    }
    int id = 0;
    int * height = nullptr;
};
void test()
{
    Person p1(18,200);
    std::cout<<p1.id<<"--"<<*p1.height<<std::endl;
    std::cout<<p1.height<<std::endl;
    Person p2(p1);
    p2.id =20;
    std::cout<<p2.height<<std::endl;
    std::cout<<p2.id<<"--"<<*p2.height<<std::endl;
    std::cout<<p1.height<<std::endl;
    std::cout<<p2.height<<std::endl;
    std::cout<<p1.id<<std::endl;
}
int main()
{
    test();
    return 0;
}