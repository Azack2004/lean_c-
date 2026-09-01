#include<iostream>
#include<fstream>
//二进制文件 写文件
class Person
{
    public:
        char name[64];
        int age;

};
int main()
{
    //写文件
    std::ofstream ofs("fileOperator/person.txt",std::ios::out |  std::ios::binary);
    //ofs.open("fileOperator/test.txt",std::ios::out |  std::ios::binary);
    Person p = {.name="张三",.age=19 };
   
    ofs.write((const char*)&p,sizeof(p));
    ofs.close();

    //读文件
    std::ifstream ifs("fileOperator/person.txt",std::ios::in |  std::ios::binary);
    if(!ifs.is_open())
    {
        return 0;
    }
    Person p1;
    ifs.read((char*)&p1,sizeof(p));
     std::cout<<p1.name<<std::endl;
    std::cout<<p1.age<<std::endl;
    ifs.close();
    return 0;
}