#include<iostream>
#include<atomic>
//设置结构体1字节对齐
//#pragma pack(push,1)
class Demo
{
   
    int a;
    char c;
};
int main()
{
    std::atomic<Demo> a;
    std::cout<<sizeof(a)<<std::endl;
    std::cout<<a.is_lock_free()<<std::endl;
    return 0;
}