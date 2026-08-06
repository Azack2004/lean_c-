#include <iostream>
#include <string>
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

void showMenu();
bool processSelect(int select,Addressbooks * aBook,int * person_num); // 让函数返回一个 bool 值，代表是否继续运行
bool addPerson(Addressbooks * aBook,int * person_num);//1.添加联系人
void show_person(Addressbooks * aBook,int * person_num);//2.显示联系人

int main()
{   
    int select = -1; // 局部变量，更安全
    Addressbooks aBook;
    aBook.m_Size=0;
    int person_num =0;//personArray的数组下标

    while (true)
    {
        showMenu();
        std::cin >> select;
        
        // 如果处理函数返回 false，说明用户选了退出，直接跳出 while 循环
        if (!processSelect(select,&aBook,&person_num))
        {
            break; 
        }
    }
    
    return 0;
}

void showMenu()
{
    std::cout << "1.添加联系人" << std::endl;
    std::cout << "2.显示联系人" << std::endl;
    std::cout << "3.删除联系人" << std::endl;
    std::cout << "4.查找联系人" << std::endl;
    std::cout << "5.修改联系人" << std::endl;
    std::cout << "6.清空联系人" << std::endl;
    std::cout << "0.退出通讯录" << std::endl;
}

bool processSelect(int select,Addressbooks * aBook,int * person_num)
{
    switch (select)
    {
    case 1:
        // 添加联系人逻辑
        if(addPerson(aBook,person_num))
        {
            std::cout<<"添加成功！"<<std::endl;
            std::cout<<"添加成功！姓名："
            << aBook->personArray[*person_num].m_Name
            << "    "
            << "性别:"
            << aBook->personArray[*person_num].m_Sex
            << "    "
            << "年龄:"
            << aBook->personArray[*person_num].m_Age
            << "    "
            << "电话:"
            << aBook->personArray[*person_num].m_Phone
            << "    "
            << "住址:"
            << aBook->personArray[*person_num].m_Addr
            << "    "
            <<std::endl;
            aBook->m_Size++;
            *person_num+=1;
        }
        break;
    case 2:
        // 显示联系人逻辑
        show_person(aBook,person_num);
        break;
    case 3:
        break;
    case 4:
        break;
    case 5:
        break;
    case 6:
        break;
    case 0:
        std::cout << "欢迎下次使用" << std::endl;
        return false; // 返回 false，告诉 main 函数该退出循环了！
    default:
        std::cout << "请输入正确的数字" << std::endl;
        break;
    }
    return true; // 继续运行
}

bool addPerson(Addressbooks * aBook,int * person_num)
{   //性别用临时变量
    int sex = 0;
    if(aBook->m_Size>=MAX || *person_num >=MAX)
    {
        std::cout<<"已达到通讯录最大值，添加失败。"<<std::endl;
        return false;
    }
    //姓名
    std::cout<<"姓名:"<<std::endl;
    std::cin >> aBook->personArray[*person_num].m_Name;
    //性别
    
    do{
        std::cout<<"性别:1.男 2.女"<<std::endl;
        std::cin >> sex;
        if(sex!=1&&sex!=2)
            {
                std::cout<<"输入数据不合法。"<<std::endl;
            } 
    }while(sex!=1&&sex!=2);
    aBook->personArray[*person_num].m_Sex=sex;
  
    //年龄
    std::cout<<"年龄:"<<std::endl;
    std::cin >> aBook->personArray[*person_num].m_Age;

    //手机号
    std::cout<<"手机号:"<<std::endl;
    std::cin >> aBook->personArray[*person_num].m_Phone;
    std::cout<<"住址:"<<std::endl;
    std::cin >> aBook->personArray[*person_num].m_Addr;

    
    return true;
}


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