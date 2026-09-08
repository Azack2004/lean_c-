#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>
class Person
{
    public:
        std::string name;
        std::deque<int> dqscore;
        int final_score=0;
        Person(){};
        Person(const std::string &n):name(n){};
        void getScore()
        {
            int score;
            for(int i=0;i<5;i++)
            {
                std::cout<<"给"<<this->name<<"打分:";
                std::cin>>score;
                dqscore.push_front(score);
            }
        }
        void result()
        {
            std::sort(dqscore.begin(),dqscore.end());
            dqscore.pop_front();
            dqscore.pop_back();
            int n = 0;
            for(std::deque<int>::iterator it=dqscore.begin();it!=dqscore.end();it++)
            {
                this->final_score+=(*it);
                n++;
            }
            this->final_score = this->final_score/n;
        }
};
int main()
{
    std::vector<Person*> plist;
    std::vector<int> slist;
    Person p1("1");
    Person p2("2");
    plist.push_back(&p1);
    plist.push_back(&p2);
    
    for(std::vector<Person*>::iterator it = plist.begin();it!=plist.end();it++)
    {
        (*it)->getScore();
        (*it)->result();
    }
    for(std::vector<Person*>::iterator it = plist.begin();it!=plist.end();it++)
    {
        slist.push_back((*it)->final_score);
    }
    std::sort(slist.begin(),slist.end());
    for(int i =0;i<slist.size();i++)
    {
        std::cout<<slist[i]<<" ";
    }
    std::cout<<std::endl;
    return 0;
}