#include<memory>
#include<stack>
#include<iostream>
#include<mutex>
#include<exception>
#include<thread>
#include<vector>

// struct empty_stact:std::exception
// {
//     const char* what() const throw()
//     {
//         return "empty stack!;
//     };
// };

template<typename T>
class threadsafe_stack
{
    private:
        std::stack<T> s;
        std::mutex mtx;
    public:
        explicit threadsafe_stack()=default;
        explicit threadsafe_stack(const threadsafe_stack & other)
        {
            std::scoped_lock lock(mtx, other.mtx);
            this->s = other.s;
        }
        void operator=(const threadsafe_stack & other)=delete;
        void push(T data)
        {
            std::lock_guard<std::mutex> gmtx(mtx);
            this->s.push(data);
        }
        void pop(T& data)
        {
            std::lock_guard<std::mutex> gmtx(mtx);
            if(this->s.empty())
            {
                throw "empty stack!";
                return ;
            }
            data = this->s.top();
            this->s.pop();
        }
        std::shared_ptr<T> pop()
        {
            std::lock_guard<std::mutex> gmtx(mtx);
            if(this->s.empty())
            {
                return std::shared_ptr<T>();
            }
            std::shared_ptr<T> s(std::make_shared<T>(std::move(this->s.top())));
            this->s.pop();
            return s;
        }
    
};
template <typename T>
void add(threadsafe_stack<T> & s,T data)
{
    s.push(data);
}
template <typename T>
void pop(threadsafe_stack<T> & s,T& data)
{
    s.pop(data);
}

int main()
{
    threadsafe_stack<int> t_stack;
    std::vector<std::thread> v;
    int data=0;
    std::shared_ptr<int> sp;
    for(int a=0; a<3;a++)
    {
        v.emplace_back(add<int>,std::ref(t_stack),a);
    }
    for(int a=0; a<3;a++)
    {
        v[a].join();
    }
   
    sp = t_stack.pop();
    if(sp)
    {
        std::cout<<*sp<<std::endl;
    }
    std::thread t(pop<int>,std::ref(t_stack),std::ref(data));
    t.join();
    std::cout<<data<<std::endl;
    return 0;
}