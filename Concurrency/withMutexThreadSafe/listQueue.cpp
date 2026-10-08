#include<iostream>
#include<thread>
#include<mutex>
#include <stdexcept>
template <typename T>
class Queue
{
    private:
        struct node
        {
            T data;
            node* next;
            node(T data){this->data = data;this->next=nullptr;}
        };
        node* head=nullptr;
        node* tail=nullptr;
    public:
        Queue(){};
         ~Queue()
        {
            while (head)
            {
                node* temp = head;
                head = head->next;
                delete temp;
            }
         }
        void push(T data)
        {
            node* new_tail = new node(std::move(data));
            if(tail)
            {
               tail->next = new_tail;
               
            }
            tail = std::move(new_tail);
           
            if(!head)
            {
                head = new_tail;
            }
        }
        void pop(T &a)
        {
            if(!head)
            {
                throw std::runtime_error("Queue is empty");;
            }
           
            a =  std::move(head->data);
            node* temp = std::move(head);
            head = std::move(head->next);
            if(!head)
            {
                tail = nullptr;
            }
            delete temp;

        }

        
};
int main()
{
    Queue<int> q;
    int a=0;
    for(int i = 0;i<10;i++)
    {
        q.push(i);
    }
    for(int i = 0;i<11;i++)
    {
        q.pop(a);
        std::cout<<a<<std::endl;
    }
    return 0;
}