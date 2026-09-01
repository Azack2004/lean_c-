#include<iostream>
#include<string>
class Phone
{
    public:
        Phone(std::string n):name(n){
            std::cout<<"phone构造"<<std::endl;
        }
        std::string name ;
        ~Phone(){
            std::cout<<"phone析构"<<std::endl;
        }
};
class Person
{
    public:
        Person(std::string n,std::string pn):name(n),b(pn){
            std::cout<<"person构造"<<std::endl;
        }//Phone b = pn
        std::string name;
        Phone  b;
        
        void showinfo()
        {
            std::cout<<name<<std::endl;
            std::cout<<b.name<<std::endl;
        }
        ~Person(){
            std::cout<<"person析构"<<std::endl;
        }
};
int main()
{
    Person a("人类","apple");
    a.showinfo();
    std::cout<<a.b.name<<std::endl;
    return 0;
}