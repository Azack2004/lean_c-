#include<iostream>
/*
常量定义
1.#define 宏常量
2.const
*/
#define Day 7
int main()
{
    const int hours = 24;
    std::cout << "一周有"<<Day<<"天。"<< std::endl;
    std::cout << "一天有"<<hours<<"小时。"<< std::endl;
    return 0;
}