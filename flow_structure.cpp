# include<iostream>
#include<ctime>
int main()
{   int a =0;
    while (a<10){
        std::cout <<a<<std::endl;
        ++a;
    }
    //添加随机数种子
    srand((unsigned int)time(NULL) );
    int num = rand()%100+1;
    int guess = 0;
    std::cout <<num<<std::endl;
    while (guess!=num)
    {
        if (num>guess)
        {
            std::cout<<"猜小了"<<std::endl;
            std::cin>>guess;
        }
        else if(num<guess)
        {
            std::cout<<"猜大了"<<std::endl;
            std::cin>>guess;
        }
        else{
            std::cout<<"对了"<<std::endl;
            break;
        }
    }
    return 0;
}