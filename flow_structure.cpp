#include<iostream>
#include<ctime>
#include<cmath>
int main()
{  
    for(int j=1;j<10;j++)
    {
        for(int i=1; i<=j;i++)
        {
            std::cout <<i<<"*"<<j<<"="<<j*i;
            if(j*i>9){
                std::cout<<"   ";
            }
            else{
                std::cout<<"    ";
            }
            
        }
        std::cout <<std::endl;
    }
    
    
    return 0;
}