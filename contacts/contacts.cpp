#include <iostream>
#include <string>

#include"function.h"



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
        std::cout<<"--------"<<std::endl;
        // 如果处理函数返回 false，说明用户选了退出，直接跳出 while 循环
        if (!processSelect(select,&aBook,&person_num))
        {
            break; 
        }
    }
    
    return 0;
}




