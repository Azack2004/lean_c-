#include<iostream>
#include<ctime>
#include<cmath>
int main()
{   for(int i=1;i<101;i++)
    {
        if(i/10==7||i%10==7||i%7==0)
        {
        std::cout << i<<std::endl;
        }
    }
    
    return 0;
}