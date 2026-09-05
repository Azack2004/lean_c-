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
            len = 0;
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
        MyInt(int b):a(b){}
        void show()
        {
            std::cout<<a<<std::endl;
        }
};

int main()
{
    
    return 0;
}