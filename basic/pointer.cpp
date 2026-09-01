#include<iostream>
int sum(const int * a,const int * b);
void bubble_sort(int nums[],int len);
int main()
{
    int a=10;
    int* p=&a;
    int** p2=&p;
    std::cout<<"a的地址为:"<<&a<<std::endl;
    std::cout<<"p的值为:"<<p<<std::endl;
    std::cout<<"p指向的内存中的值为:"<<*p<<std::endl;

    *p=100;
    std::cout<<"a的值为:"<<a<<std::endl;
    std::cout<<"p的内存大小为:"<<sizeof(p)<<std::endl;
    **p2 = 1000;
    std::cout<<"a的值为:"<<a<<std::endl;

    std::string* p1 = NULL;
    std::string p1_string = "hello world";
    p1 = &p1_string;
    *p1 = "你好。";
    std::cout<<"p1_string的值为:"<<p1_string<<std::endl;
    //常量指针
    int b = 20;
    const int * cp = &a;
    std::cout <<"a:"<<a<<std::endl;
    cp = &b;
    std::cout<<"b:"<<*cp<<std::endl;
    int * const pc = &b;
    *pc =a;
    std::cout<<"*pc:"<<*pc<<std::endl;
    std::cout<<"*cp:"<<*cp<<std::endl;

    int num[][2]={1,19,2,3,4,5,6,7,7,8,-1};
    int * np = num[0];
    int i = 0;
    while (*np!=-1)
    {   
        std::cout<<"num"<<i<<"="<<*np<<" ";
        i++;
        if(i==2)
        {
            i=0;
            std::cout<<std::endl;
        }
      np++;
    }
    std::cout<<"sum="<<sum(&a,&b)<<std::endl;
    int nums[10]={100,203,405,9,4,6,7093,80};
    int len =sizeof(nums)/sizeof(nums[0]);
    for(int i=0;i<sizeof(nums)/sizeof(nums[0]);i++)
    {
        std::cout<<nums[i]<<std::endl;
    }
    bubble_sort(nums,len);
    std::cout<<"--------"<<std::endl;
    for(int i=0;i<sizeof(nums)/sizeof(nums[0]);i++)
    {
        std::cout<<nums[i]<<std::endl;
    }
    return 0;
}
int sum(const int * a,const int * b)
{
    return *a + *b;
}
void bubble_sort(int * nums,int len)
{
    int * p1= nullptr;
    int * p2 = nullptr;
    
    for(int j=0;j<len-1;j++)
    {
        for(int i=0;i<len-1-j;i++)
        {
            p1=&nums[i];
            p2=&nums[i+1];
            if(*p1>*p2)
                {
                    int c = *p1;
                    *p1 = *p2;
                    *p2 = c; 
                } 
        }
     
    }
}