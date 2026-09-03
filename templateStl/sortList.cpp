#include<iostream>

template <typename T>
void sortList(T &a,int len)
{
    for(int j=0;j<len;j++)
    {
        for(int i=0;i<len-1-j;i++)
        {
            if(a[i]>a[i+1])
            {
                auto b = a[i];
                a[i]=a[i+1];
                a[i+1]=b;
            }
        } 
    }
 
}
template <typename T>
void showList(T &a,int len)
{
    for(int i=0;i<len;i++)
    {
        std::cout<<a[i]<<"<";
    }
    std::cout<<std::endl;
}
int main()
{
    int a[]={10,22,3,1,6,90,20,4};
    double b[] ={0.1,20.3,98.3,1,2.3,4.01};
    sortList(a,sizeof(a)/sizeof(a[0]));
    showList(a,sizeof(a)/sizeof(a[0]));
    sortList(b,sizeof(b)/sizeof(b[0]));
    showList(b,sizeof(b)/sizeof(b[0]));
    return 0;
};