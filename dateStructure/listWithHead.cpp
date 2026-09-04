#include<iostream>

struct LNode
{
    int data;
    LNode* next;
};
bool InitList(LNode*&L)//这里是个指针
{
    L = new LNode();
    if(L==NULL)//申请内存失败
    {
        return false;
    }
    L->next=nullptr;
    return true;
}
bool IsEmpty(LNode* &L)
{
    if(L->next==nullptr)
    {
        return true;
    }
    return false;
}
bool AddNode(LNode* &L,const int &a)
{
    LNode* p = L;
    while(p->next!=nullptr)
    {
        p = p->next;
    }
    LNode* lastp = new LNode();
    if(lastp==NULL)
    {
        return false;
    }
    lastp->next=nullptr;
    lastp->data=a;
    p->next = lastp;
    return true;
}
void ShowAll(LNode*& L)
{
    LNode* p = L;
    while(p->next!=nullptr)
    {
        p=p->next;
        std::cout<<p->data<<"->";
    }
    std::cout<<std::endl;
}
bool InsertNode(LNode*&L ,const int&i ,const int &a)
{
    LNode*p = L;
    int j=1;
    while(p->next!=nullptr&&j<i)
    {
        p=p->next;
        j++;
    }
    LNode* insertp = new LNode();
    if(insertp==nullptr)
    {
        return false;
    }
    insertp->data = a;
    insertp->next = p->next;
    p->next=insertp;
    return true;
}
int main()
{
    LNode *l;
    std::cout<<InitList(l)<<std::endl;
    std::cout<<IsEmpty(l)<<std::endl;
    std::cout<<AddNode(l,100)<<std::endl;
    std::cout<<AddNode(l,10)<<std::endl;
    ShowAll(l);
    std::cout<<InsertNode(l,1,2)<<std::endl;
    ShowAll(l);
    return 0;
}
