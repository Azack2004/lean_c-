#include<iostream>
#include<ctime>
#include<cmath>
int main()
{   int a =100;
    do {
        int b=a/100;
        int c=(a%100)/10;
        int d=a%10;
        //std::cout<<b<<c<<d<<std::endl;
        if(((std::pow(b, 3)+std::pow(c, 3)+std::pow(d, 3))==a)?a:0)
        {
            std::cout<<a<<std::endl;
        }
        a++;
    }while (a<1000);
    
    return 0;
}