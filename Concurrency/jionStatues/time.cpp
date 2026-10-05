#include<iostream>
#include<chrono>
#include<thread>
int main()
{
    auto start = std::chrono::system_clock::now();
    std::time_t t = std::chrono::system_clock::to_time_t(start);
    std::cout<<std::ctime(&t)<<std::endl;
    return 0;
}