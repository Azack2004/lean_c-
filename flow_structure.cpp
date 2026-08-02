# include<iostream>
int main()
{
    int a = 1;
    std::cin>>a;
    if (a>600)
    {
         std::cout<<"大于600"<<std::endl;
         if(a>700)
         {
            std::cout<<"考上700"<<std::endl;
         }
         else{
            std::cout<<"没考到700"<<std::endl;
         }
    }
    else if(500<a&&a<600)//没有500<a<600
    {
        std::cout << "大于500小于600"<<std::endl;
    }
    else{
        std::cout<<"小于500"<<std::endl;
    };
    // if (!a)
    // {
    //     std::cout<<a<<std::endl;
    // }
    // else {
    //     std::cout<<a<<std::endl;
    // };

    int b = 0;
    int c=0;
    int d=0;
    std::cin>>b;
    std::cin>>c;
    std::cin>>d;

    if(b>c)
    {
        if(b>d){
            std::cout << "b最大"<<std::endl;
        }
        else{
            std::cout << "d最大"<<std::endl;
        }
    }
    else{
         if(c>d){
            std::cout << "c最大"<<std::endl;
        }
        else{
            std::cout << "d最大"<<std::endl;
        }
    }
    int f = b>c ? b:c;
    std::cout<<f<<std::endl;
    //在c++中，三目运算符返回的是变量
    (b>c ? b:c)=100;
    std::cout<<b<<" ---- "<<c<<std::endl;
    return 0;
}