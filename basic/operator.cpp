#include<iostream>
#include<string>
int main()
{
    int a = 10;
    std::cout << a-- ;//9
    std::cout << a <<std::endl;
    float f1 = 3.14f;
    float f2 = 12.7f;
    std::cout << f2/f1 << std::endl;
    int c = 3;
    std::cout << (--a)%c << std::endl;
    //a-- 是用旧值进行运算，在减一。
    std::cout << a <<std::endl;
    std::cout << !((!a)&&c) << std::endl;
    std::cout << ((!a)||c) << std::endl;
    std::cout << !!a << std::endl;
    return 0;
}