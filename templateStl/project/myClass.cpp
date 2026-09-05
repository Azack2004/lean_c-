#include<iostream>
template<typename T>
class MyList
{
    private:
        int len;//实际长度
        int max;
        T * L;

    public:
        MyList(const int &max)
        {   
            this->len = 0;
            this->max = max;
            try
            {
                L = new T[max];
            }          
            catch(const std::bad_alloc& e)
            {
                std::cout<<"申请内存失败:"<<e.what()<<std::endl;
                L = nullptr;
            }
        }
        int getLen()
        {
            return this->len;
        }
        int getMax()
        {
            return this->max;
        }
        MyList(const MyList& m)
        {   
            try
            {
                this->L = new T[m.max];
            }          
            catch(const std::bad_alloc& e)
            {
                std::cout<<"申请内存失败:"<<e.what()<<std::endl;
                this->L = nullptr;
            }

            if(this->L!=nullptr)
            {
                for(int i=0;i<m.len;i++)
                {
                    this->L[i]=m.L[i];
                }
                this->len = m.len;

            }   
        }
        void operator=(const MyList& m)
        {
            try
            {
                this->L = new T[m.max];
            }          
            catch(const std::bad_alloc& e)
            {
                std::cout<<"申请内存失败:"<<e.what()<<std::endl;
                this->L = nullptr;
            }

            if(this->L!=nullptr)
            {
                for(int i=0;i<m.len;i++)
                {
                    this->L[i]=m.L[i];
                }
                this->len = m.len;

            } 
        }
        bool add(const T& t)
        {
            if(L==nullptr)
            {
                return false;
            }
            if(this->len==this->max)
            {
                return false;
            }
            L[len]=t;
            len++;
            return true;
        }
        bool pop(T& value)
        {
            if(L==nullptr)
            {
                return false;
            }
            if(this->len==0)
            {
                return false;
            }
            this->len--;
            value= this->L[len];
            return true;
        }
        T operator[](const int & i)
        {
           
            if (this->L == nullptr)
            {
                throw std::runtime_error("指针为空");
            }
            if(i>=this->len)
            {
                throw std::runtime_error("索引过界");
            }
            return this->L[i];
          
        }
        void showAll()
        {
            if(L==nullptr)
            {
                return ;
            }
            for(int i=0;i<len;i++)
            {
                std::cout<<L[i]<<" ";
            }
            std::cout<<std::endl;
        }
        
        ~MyList()
        {
            if(L!=nullptr)
            {
                delete[] L;
                L=nullptr;
            }
        }
};
class MyInt
{
    
    private:
        int a;
    public:
        MyInt(){
            a =0;
        }
        MyInt(int b):a(b){}
        int show() const
        {
            return a;
        }
};
//重载左移运算符
std::ostream & operator<<(std::ostream & c,const MyInt & a)
{
    std::cout<<a.show();
    return c;
}

int main()
{
    MyList<MyInt> m(10);
    MyInt a(1);
    MyInt b(2);
    m.add(a);
    m.add(b);
    m.showAll();
    MyList<int> c(1);
    c.add(1);
    std::cout<<c.add(10)<<std::endl;
    c.showAll();
    return 0;
}