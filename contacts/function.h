#include<iostream>
#include <limits>
#define MAX 2
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

void showMenu();
void show_status(Addressbooks * aBook,int * person_num);//打印状态信息
bool processSelect(int select,Addressbooks * aBook,int * person_num); // 让函数返回一个 bool 值，代表是否继续运行
bool addPerson(Addressbooks * aBook,int * person_num);//1.添加联系人
void showPerson(Addressbooks * aBook,int * person_num);//2.显示联系人
bool delPerson(Addressbooks * aBook,int * person_num);//3.删除联系人
int ifPersonExist(Addressbooks * aBook,int * person_num);//4.查找联系人
void mvPerson(Addressbooks * aBook,int * person_num,int i);//3.删除
void modifyPersion(Addressbooks * aBook,int i);//5.修改
void delAll(Addressbooks * aBook,int * person_num);//6.清空