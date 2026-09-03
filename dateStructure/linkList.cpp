#include<iostream>
class LNode
{
    public:
        LNode* next = nullptr;
        int value;
};


void addLastList(LNode * l, const int &a)
{
   
    LNode * p = l;
    while(p->next!=nullptr)
    {
        p = p->next;
    }
    LNode*q = new LNode();
    q->next=nullptr;
    q->value = a;
    p->next = q;
    
}
void showList(LNode *l )
{
    LNode * p = l->next;
    while(p!=nullptr)
    {   
        std::cout<<p->value;  
        if(p->next!=nullptr)
        {
           std::cout<<"->";
        } 
        p = p->next; 
    }
    std::cout<<std::endl;
}
void addPostionList(LNode *l,int i,int a)
{
    LNode * p = l;
    int j =1;
    while(p->next!=nullptr&&j<i)
    {
        p=p->next;
        j++;
        std::cout<<j<<std::endl;
    }
    LNode *q = new LNode();
    q->value=a;
    q->next = p->next;
    p->next=q;
}
void delLastList(LNode*l)
{
    LNode * p = l;
    if(p->next==nullptr)
    {
        std::cout<<"只有头节点了."<<std::endl;
        return;
    }
    while(p->next->next!=nullptr)
    {
        p=p->next;
    }
    LNode * q = p->next;
    delete q;
    p->next = nullptr;
}
int main()
{
    LNode *l =new LNode();
    addLastList(l,10);
    addLastList(l,1);
    addLastList(l,120);
    addLastList(l,100);
    showList(l);
    addPostionList(l,2,2);
    showList(l);
    delLastList(l);
    showList(l);
    delLastList(l);
    showList(l);
    delLastList(l);
    showList(l);
    addPostionList(l,1,100);
    showList(l);
    return 0;
}