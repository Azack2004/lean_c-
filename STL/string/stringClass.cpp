#include<iostream>
#include<string>

int main()
{
    std::string s;
    std::string s1="ni";
    std::string s2("hello");
    std::cout<<s2<<std::endl;
    std::string s3(s2);
    std::cout<<s3<<std::endl;
    const char* c = "hello";
    std::string s4(c);
    std::cout<<s4<<std::endl;
    std::string s5(10,'a');
    std::cout<<s5<<std::endl;
    /*
    =
    assign
    */
    std::string str1;
    str1 = "hello";
    std::cout<<str1<<std::endl;
    str1.assign(10,'c');
    std::cout<<str1<<std::endl;
    str1.assign("hello C++");
    std::cout<<str1<<std::endl;
    str1.assign(c,4);
    str1+=c;
    std::cout<<str1<<std::endl;
    str1.append(c,2);
    std::cout<<str1<<std::endl;
    
    str1+='c';
    str1.append(s2,1,4);//从那个位置开始截取，截几个
    std::cout<<str1<<std::endl;
    
    return 0;
}