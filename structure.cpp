#include<iostream>
#include<string>

//结构体
struct Student
{
    int age;
    std::string name ;
    int score[3];
};
struct Teacher
{
    int age;
    std::string name ;
    Student stu;
};
void modify_student(const Student * stu);
void info_sudent(Student s);
int main()
{   //结构体数组
    Student s1[3] ={{10,"天才",{10,20,30}},{30,"煞笔",{10,20,30}},{59,"人类",{10,20,30}}};


    for(int i=0;i<sizeof(s1)/sizeof(s1[0]);i++)
    {
        std::cout<<s1[i].age<<std::endl;
    }
    Student * ps = nullptr;
    ps = s1;
    ps++->age = 40;
    
    std::cout<<"_______________"<<std::endl;
    std::cout<<s1[1].age<<std::endl;
    std::cout<<"_______________"<<std::endl;
    for(int i=0;i<sizeof(s1)/sizeof(s1[0]);i++)
    {
        std::cout<<s1[i].age<<std::endl;
    }
    
    std::cout<<"_______________"<<std::endl;
    // std::cout<<ps->age<<std::endl;
    modify_student(&s1[0]);
    Teacher t1 = {10,"teacher",s1[0]};
    for(int i=0 ;i<sizeof(t1.stu.score)/sizeof(t1.stu.score[0]);i++)
    {
        std::cout<<t1.stu.score[i]<<std::endl;
    }
    info_sudent(s1[1]);
    return 0;
}

void modify_student(const Student * stu)
{   //传地址
    for(int i =0;i<3;i++)
    {
      //stu->score[i]=i;
      std::cout<<(*stu).name<<std::endl;
    }
  
}
void info_sudent(Student s)
{   //传值
    for(int i =0 ;i<3;i++)
    {
        std::cout<<s.name<<std::endl;
    }
}