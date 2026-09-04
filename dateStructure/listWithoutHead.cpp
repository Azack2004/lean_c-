#include<iostream>

struct LNode
{
    int data;
    LNode* next;
};
bool InitList(LNode *&L)
{
    L = nullptr;
    return true;
}
bool IsEmpty(LNode* &L)
{
    if(L==nullptr)
    {
        return true;
    }
    return false;
}
bool AddNode(LNode*&L,const int &a)
{
    LNode *p = L;
    if(p !=nullptr)
    {
        while(p->next!=nullptr)
        {
            p=p->next;
        }
    }
    LNode * lastp = new LNode();
    if(lastp==nullptr)
    {
        return false;
    }
    //填充节点
    lastp->data = a;
    lastp->next =nullptr;
    //连接
    if(p==nullptr)
    {
        L = lastp;
    }
    else{
         p->next = lastp;
    }
    return true;
}
void ShowAll(LNode*& l)
{
    LNode*p = l;
    if(p!=nullptr)
    {
        std::cout<<p->data<<"->";
        while(p->next!=nullptr)
        {
            p=p->next;
            std::cout<<p->data<<"->";
        }
        std::cout<<std::endl;
    }
}
bool InsertNode(LNode*& L,const int &i,const int &a)
{
    LNode*p = L;
    LNode*insertp = new LNode();

    if(insertp==nullptr)
    {
        return false;
    }
    if(i==1)
    {
        insertp->data=a;
        insertp->next=L;
        L = insertp;
        return true;
    }
    if(p==nullptr)
    {
        L = insertp;
        insertp->data = a;
        insertp->next = nullptr;
        return true;
    }
   
    int j=1;
    while(p->next!=nullptr&&j<i-1)
    {
        p= p->next;
        j++;
    }
    insertp->next = p->next;
    insertp->data = a;
    p->next = insertp;
    
    return true;
}
int main()
{
    //不带头节点的单链表
    //空指针
    LNode *L;
    //滞空
    std::cout<<InitList(L)<<std::endl;
    std::cout<<IsEmpty(L)<<std::endl;
    std::cout<<InsertNode(L,1,1)<<std::endl;
    ShowAll(L);
    std::cout<<AddNode(L,10)<<std::endl;
    std::cout<<AddNode(L,10)<<std::endl;
    ShowAll(L);
    std::cout<<InsertNode(L,2,2)<<std::endl;
    ShowAll(L);
    std::cout<<InsertNode(L,4,4)<<std::endl;
    ShowAll(L);
    return 0;
}