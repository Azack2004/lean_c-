#include<iostream>
#include<fstream>
//写文件
void test()
{
    std::ofstream ofs;
    ofs.open("fileOperator/test.txt",std::ios::out);
    ofs<<"你好"<<std::endl<<"我是人类.";
    ofs.close();

}
int main()
{
    test();
    return 0;
}