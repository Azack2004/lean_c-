#include<iostream>
#define MAX 100
struct Person
{
    std::string m_Name;
    int m_Sex;//1 男 ，2 女
    int m_Age;
    std::string m_Phone ;
    std::string m_Addr;
};
struct Addressbooks
{
    Person personArray[MAX];
    int m_Size;
};
void show_person(Addressbooks * aBook,int * person_num)
{   
    for(int i=0;i<*person_num;i++)
    {
       std::cout<<"姓名："
            << aBook->personArray[i].m_Name
            << "    "
            << "性别:"
            << aBook->personArray[i].m_Sex
            << "    "
            << "年龄:"
            << aBook->personArray[i].m_Age
            << "    "
            << "电话:"
            << aBook->personArray[i].m_Phone
            << "    "
            << "住址:"
            << aBook->personArray[i].m_Addr
            << "    "
            <<std::endl; 
    }
}