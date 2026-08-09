#include<iostream>
#include<string>
int & func(int &a,int &b);
void func2(const int & a);
int main()
{
    std::string a = "hello";
    std::string & b = a;
    std::cout<<a<<std::endl;
    std::string c = "nihao";
    b = "world";
    std::cout<<a<<std::endl;
    b =c;//是赋值，不是引用，改对应内存中的值
    std::cout<<a<<std::endl;
    int e = 100;
    int f = 99;
    std::cout<<e<<std::endl;
    std::cout<<f<<std::endl;
    int & g = func(e,f);
    std::cout<<e<<std::endl;//99
    std::cout<<f<<std::endl;//100
    func(e,f) = 100;
    std::cout<<g<<std::endl;
    std::cout<<"-------"<<std::endl;
    std::cout<<e<<std::endl;//99
    std::cout<<f<<std::endl;//100
  
    std::cout<<g<<std::endl;
    f = 1000;
    func2(g);

    int && h = 10;//右值引用
    std::cout<<h<<std::endl;
    h =1009;
    std::cout<<h<<std::endl;
    return 0;
}
int & func(int &a,int &b)
{
    int c = a;
    a = b;
    b = c;
    return b;
}

void func2(const int & a)
{
    std::cout<<a<<std::endl;
}