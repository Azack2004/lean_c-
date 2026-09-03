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
    if(l!=nullptr)
    {
        std::cout<<l->data<<"->";
        while(l->next!=nullptr)
        {
            l=l->next;
            std::cout<<l->data<<"->";
        }
        std::cout<<std::endl;
    }
}
int main()
{
    //不带头节点的单链表
    //空指针
    LNode *L;
    //滞空
    std::cout<<InitList(L)<<std::endl;
    std::cout<<IsEmpty(L)<<std::endl;
    std::cout<<AddNode(L,10)<<std::endl;
    std::cout<<AddNode(L,10)<<std::endl;
    ShowAll(L);
    std::cout<<(L==nullptr);
    return 0;
}