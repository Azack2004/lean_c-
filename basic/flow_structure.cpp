#include<iostream>
#include<ctime>
#include<cmath>
int main()
{  
   for(int i=0;i<10;i++)
   {
    if(i==7){
        goto FLAG;
    }
    std::cout<<i<<std::endl;
   }
    FLAG:
    std::cout<<"FLAG HERE"<<std::endl;;
    
    return 0;
}