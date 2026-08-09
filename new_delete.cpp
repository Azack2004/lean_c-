#include<iostream>
int * test();
int * test2();
int main()
{
    int * p = test();
    std::cout<<*p<<std::endl;
    delete p;//释放

    std::cout<<*p<<std::endl;
    int * parr = test2();
    for(int i=0;i<10;i++)
    {
        std::cout<<parr[i]<<std::endl;
    }
    delete[] parr;//释放数组
    for(int i=0;i<10;i++)
    {
        std::cout<<parr[i]<<std::endl;
    }
    return 0;
}
int * test()
{
    int * p = new int(100);
    return p;
}
int * test2()
{
    int * arr = new int[10];
    for(int i=0;i<10;i++)
    {
        arr[i]=0;
    }
    return arr;
}