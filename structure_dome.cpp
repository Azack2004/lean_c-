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
void score_sum(Teacher * t,int len_t,int len_tsw,int len_scores,int * score_sum);
void bubble_sort(int * scores_sum,Student * s,int len);
void show_sorted(const Student * p[],int len,const int * scores_sum);

Student s[15]={
        {"王二",{100,80,90}},
        {"张三1",{31,67,90}},
        {"张三2",{46,67,90}},
        {"张三3",{30,67,90}},
        {"张三4",{78,67,90}},
        {"张三5",{90,67,90}},
        {"张三6",{56,67,90}},
        {"张三7",{38,67,90}},
        {"张三8",{378,67,90}},
        {"张三9",{389,67,90}},
        {"张三10",{78,67,90}},
        {"张三11",{39,67,90}},
        {"张三12",{309,67,90}},
        {"张三13",{30,967,90}},
        {"张三14",{30,67,900}},
    };
Teacher t[3];
const Student * p[15];

int scores_sum[15] ={0};

int main()
{   
    for(int i=0;i<15;i++)
    {
        p[i]=&s[i];
    }

    int len_t = sizeof(t)/sizeof(t[0]);
    int len_tsw = sizeof(t->stuWith)/sizeof(t->stuWith[0]);
    int len_scores = sizeof(s[0].scores)/sizeof(s[0].scores[0]);
    
    init_t(t,len_t,len_tsw);
    show_t(t,len_t,len_tsw,len_scores);
    score_sum(t,len_t,len_tsw,len_scores,scores_sum);
    bubble_sort(scores_sum,s,len_t*len_tsw);
    std::cout<<"--------------"<<std::endl;
    show_sorted(p,len_t*len_tsw,scores_sum);
    return 0;
}

void init_t(Teacher * t,int len_t,int len_tsw)
{
    for(int i=0;i<len_t;i++)//len_t=0,1,2
    {
        (t+i)->name="二逼";
        for(int j=0;j<len_tsw;j++)//5
        {
            (t+i)->stuWith[j]=s[i*5+j];
        }
  
    }
}
void show_t(const Teacher * t,int len_t,int len_tsw,int len_scores)
{
    for(int i=0 ;i<len_t;i++)//
    {
        std::cout<<"老师名字："<<t[i].name<<std::endl;
        std::cout<<"学生详情——————"<<std::endl;
        for(int j=0;j<len_tsw;j++)
        {
            std::cout<<t[i].stuWith[j].name<<std::endl;
            for(int k=0;k<len_scores;k++)
            {
                std::cout<<t[i].stuWith[j].scores[k]<<std::endl;
            }
        }
    }
}
void score_sum(Teacher * t,int len_t,int len_tsw,int len_scores,int * scores_sum)
{  
    for(int k=0;k<len_t;k++)//3
    {   
        for(int i=0;i<len_tsw;i++)//5
        {
            for(int j=0;j<len_scores;j++)//3
            {   
                scores_sum[i+k*5] += t[k].stuWith[i].scores[j];
                
            }
        } 
    }   
}
void bubble_sort(int * scores_sum,Student * s,int len)
{   
    for (int j=0 ;j<len;j++)
    {
        for (int i=0;i+1<len-j;i++)
        {
            if(scores_sum[i]>scores_sum[i+1])
            {
                int temp = scores_sum[i+1];
                scores_sum[i+1]=scores_sum[i];
                scores_sum[i]=temp;

                const Student * temps = p[i+1];
                p[i+1]=p[i];
                p[i]=temps;

            }  
        }
    } 
}

void show_sorted(const Student * p[],int len,const int * scores_sum)
{
     for(int i=0;i<len;i++)
    {   
        std::cout<<p[i]->name<<std::endl;
        std::cout<<scores_sum[i]<<std::endl;
    }
}
