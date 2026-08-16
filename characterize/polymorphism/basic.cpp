#include<iostream>
class  Animal
{
    public:
        virtual void speak()//多个指针
        const{
            std::cout<<"动物在说话"<<std::endl;
        }
};
class Cat :public Animal
{
     public:
        void speak()
        const override
        {
            std::cout<<"猫在说话"<<std::endl;
        }
};
class Dog :public Animal
{
    public:
        void speak()
        const override   {
            std::cout<<"狗在说话"<<std::endl;
        }
};
//地址早绑定，在编译阶段就绑定Animal了

void dospeak(const Animal & a)
{
    a.speak();
}
//如果执行猫说话，地址不能在编译阶段绑定，地址晚绑定
int main()
{
    Cat c;
    dospeak(c);
    Animal a;
    std::cout<<sizeof(a)<<std::endl;
    std::cout<<sizeof(c)<<std::endl;
    Dog d;
    dospeak(d);
    return 0;
}