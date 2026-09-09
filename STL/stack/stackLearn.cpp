#include<iostream>
#include<stack>
int main()
{
    std::stack<int> s;
    for(int i=0;i<5;i++)
    {
        s.push(i);
    }
    std::cout<<s.size()<<std::endl;
    for(int i=0;i<9;i++)
    {
        if(s.empty())
        {
            break;
        }
        std::cout<<s.top()<<" ";
        s.pop();
    }
    std::cout<<std::endl;
     std::cout<<s.size()<<std::endl;
    return 0;
}