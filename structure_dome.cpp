#include<iostream>
#include<string>

struct Student
{
    std::string name;
    int scores[3];
};

struct Teacher
{   

    std::string name;
    Student stuWith[5];
};
void init_t(Teacher * t,int len_t,int len_tsw);
void show_t(const Teacher * t,int len_t,int len_tsw,int len_scores);
Student s[15]={
        {"王二",{100,80,90}},
        {"张三1",{30,67,90}},
        {"张三2",{30,67,90}},
        {"张三3",{30,67,90}},
        {"张三4",{30,67,90}},
        {"张三5",{30,67,90}},
        {"张三6",{30,67,90}},
        {"张三7",{30,67,90}},
        {"张三8",{30,67,90}},
        {"张三9",{30,67,90}},
        {"张三10",{30,67,90}},
        {"张三11",{30,67,90}},
        {"张三12",{30,67,90}},
        {"张三13",{30,67,90}},
        {"张三14",{30,67,90}},
    };
Teacher t[3];
int main()
{   
    int len_t = sizeof(t)/sizeof(t[0]);
    int len_tsw = sizeof(t->stuWith)/sizeof(t->stuWith[0]);
    int len_scores = sizeof(s[0].scores)/sizeof(s[0].scores[0]);
    //std::cout<<len_t<<" "<<len_tsw<<" "<<len_scores<<std::endl;
    init_t(t,len_t,len_tsw);
    show_t(t,len_t,len_tsw,len_scores);
    return 0;
}

void init_t(Teacher * t,int len_t,int len_tsw)
{
    for(int i=0;i<len_t;i++)
    {
        (t+i)->name="二逼";
        for(int j=0;j<len_tsw;j++)
        {
            (t+i)->stuWith[j]=s[i*5+j];
        }
  
    }
}
void show_t(const Teacher * t,int len_t,int len_tsw,int len_scores)
{
    for(int i=0 ;i<len_t;i++)
    {
        std::cout<<"老师名字："<<(t+i)->name<<std::endl;
        std::cout<<"学生详情——————"<<std::endl;
        for(int j=0;j<len_tsw;j++)
        {
            std::cout<<(t+i)->stuWith[j].name<<std::endl;
            for(int k=0;k<len_scores;k++)
            {
                std::cout<<(t+i)->stuWith[j].scores[k]<<std::endl;
            }
        }
    }
}
