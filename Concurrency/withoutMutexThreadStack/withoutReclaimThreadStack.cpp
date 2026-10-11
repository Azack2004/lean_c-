#include<thread>
#include<atomic>
#include<memory>
#include<iostream>
#include<mutex>
#include<assert.h>
std::mutex mtx;
template<typename T>
class lock_free_stack
{
    private:
        struct node
    {
        std::shared_ptr<T> data; // 1 指针获取数据
        node* next;
        node(T const& data_):
        data(std::make_shared<T>(data_)) // 2 让std::shared_ptr指向新分配出来的T
        {}
    };
        std::atomic<node*> head{nullptr};
    public:
        void push(T const& data)
        {
            node* const new_node=new node(data);
            new_node->next=head.load();
            while(!head.compare_exchange_weak(new_node->next,new_node));
        }
        std::shared_ptr<T> pop()
        {
            node* old_head=head.load();
            while(old_head && !head.compare_exchange_weak(old_head,old_head->next)); 
            // 3 在解引用前检查old_head是否为空指针
            return old_head ? old_head->data : std::shared_ptr<T>(); //
        }
};
int main()
{
   
    lock_free_stack<int> stack;
    int ToTal = 1000;
    int part = 450;
    int sum1 = 0;
    int sum2 = 0;
    int popsum1 = 0;
    int popsum2=0;
    std::thread t([&stack,ToTal,&sum1](){
        for(int i=0;i<ToTal;i++)
        {
            stack.push(i);
            sum1+=i;
        }
    });
    std::thread t3([&stack,ToTal,&sum2](){
        for(int i=0;i<ToTal;i++)
        {
            stack.push(i);
            sum2+=i;
        }
    });
    std::thread t1([&stack,ToTal,part,&popsum1](){
         std::shared_ptr<int> upr;
        for(int i=0;i<2*ToTal-part;i++)
        {
           
            upr=stack.pop();
            if(upr)
            {
                std::lock_guard lock(mtx);
                std::cout<<std::this_thread::get_id()<<":"<<*upr<<std::endl;
                popsum1+=*upr;
            }
            
        }
    });
    std::thread t2([&stack,part,&popsum2](){
        std::shared_ptr<int> upr;
        for(int i=0;i<part;i++)
        {
            
            upr=stack.pop();
            if(upr)
            {
                std::lock_guard lock(mtx);
               std::cout<<std::this_thread::get_id()<<":"<<*upr<<std::endl; 
               popsum2+=*upr;
            }
            
        }
    });
    t.join();
    t1.join();
    t2.join();
    t3.join();
    
    std::cout<<sum1+sum2<<std::endl;
    std::cout<<popsum1+popsum2<<std::endl;
    assert((sum1+sum2)==(popsum1+popsum2));
    return 0;
}