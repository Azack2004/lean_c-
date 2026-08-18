#include<iostream>
#include<string>
class Animal
{
    public:
        Animal(){
            std::cout<<"Animal构造函数调用"<<std::endl;
        }
        virtual void speak()=0;
        // virtual ~Animal(){
        //     std::cout<<"Animal析构函数调用"<<std::endl;
        // }
        virtual ~Animal()=0;//需要声明，也需要实现，这是声明
};
Animal::~Animal()//这是实现
{
    std::cout<<"Animal纯虚析构函数调用"<<std::endl;
}
class Cat:public Animal
{
    public:
        Cat(const std::string & a){
            std::cout<<"Cat构造函数调用"<<std::endl;
            name = new std::string(a);
        }
        void speak()
        {
            std::cout<<*name<<"小猫在说话"<<std::endl;
        }
        std::string * name;
        ~Cat()
        {   
            std::cout<<"Cat析构函数调用"<<std::endl;
            if(name!=nullptr)
            {
                delete name;
                name = nullptr;
            }
        }
};
int main()
{
    Animal * a = new Cat("傻帽");
    a->speak();
    delete a ;
    return 0;
}