#include<iostream>
#include<fstream>
#include<string>
void test()
{
    std::ifstream ifs;
    ifs.open("fileOperator/test.txt",std::ios::in);
    if(!ifs.is_open())
    {
        std::cout<<"文件打开失败"<<std::endl;
        return ;
    }
    //读数据
    //第一种
    // char b[1024]={0};
    // while ( ifs >> b)
    // {
    //     std::cout<<b<<std::endl;
    // }
    // ifs.close();
    // 第二种
    // while (ifs.getline(b,sizeof(b)))
    // {
    //     std::cout<<b<<std::endl;
    //     std::cout<<"--"<<std::endl;
    // }
    //第三种
    // std::string b;
    // while(getline(ifs,b))
    // {
    //     std::cout<<b<<std::endl;
    // }
    //第四种
    char c;
    while((c=ifs.get())!= EOF)//EOF end od file 
    {//linux下不行
        std::cout<<c;
    }
    ifs.close();
}
int main()
{
    test();
    return 0;
}