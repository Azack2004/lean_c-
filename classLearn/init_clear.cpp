#include<iostream>
//对象的初始化和清理
//1.构造函数
//2.清理函数
class Person
{   
  
    public:
         int id ;
        std::string name ;
        Person(){
            std::cout<<"无参构造函数"<<std::endl;
        }
        Person(const int & a,const std::string n)
        {
            id = a ;
            name = n;
            std::cout<<"有参构造函数"<<std::endl;
        }
        Person(const Person & p){
            id = p.id;
            name = p.name;
            std::cout<<"拷贝构造函数"<<std::endl;
        }
        ~Person()
        {
            //对象销毁前调用。
            std::cout<<"析构函数"<<std::endl;
        }
};
void test()
{
    Person p;

}
void copyFunc(Person p)
{
    std::cout<<p.id<<std::endl;
}
Person func()
{
    Person p1(10,"");
    std::cout<<&p1<<std::endl;
    return p1;
}
int main()
{   
   //1.默认构造调用
//    Person p1;
//    Person p2={1,"你好"};
//    Person p3(1,"人类");
//    Person p4(p3);
//     //2.显示构造
//     Person p5 = Person(1,"hell");//匿名对象，当前行执行完，匿名对象被系统回收
//     Person p6 = Person(p3);
//     Person(1,"a");
//     std::cout<<"aaa"<<std::endl;
//     Person p10 = {12,"haleo"};
//     Person p11 = p10;
    Person p11(10,"");
    copyFunc(p11);
    Person p20 = func();
    std::cout<<&p20<<std::endl;
    return 0;
}