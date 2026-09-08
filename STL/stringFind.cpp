#include<iostream>
#include<string>
int main()
{
    std::string s = "hello world C++";
    int pos = s.find("l");
    std::cout<<pos<<std::endl;
    std::cout<<(pos != std::string::npos)<<std::endl;;//这么些没找到
    //std::cout<<s[pos]<<std::endl;
    //find是从左往右查找
    //rfind是从右往左查找
    int po = s.rfind('l');
    std::cout<<po<<std::endl;
    //从1号位置起到3号位置，全变为nihao
    s.replace(1,3,"nihao");
    std::cout<<s<<std::endl;
    std::string s1 = "znihaoo world C++";
    std::cout<<s.compare(s1)<<std::endl;
    std::cout<<s.at(1)<<std::endl;
    std::cout<<(s[0]='x')<<std::endl;
    for(int i=0;i<s.size();i++)
    {
        std::cout<<s[i]<<std::endl;
    }
    s.insert(0,"1112");
    std::cout<<s<<std::endl;
    s.erase(0,4);
    std::string c = s.substr(0,7);
    std::cout<<c<<std::endl;
    s = "1483932084@qq.com";
    pos = s.rfind("@");
    int pos1 =  s.rfind('.');
    std::string c1 = s.substr(0,pos);
    std::cout<<c1<<" "<<pos1<<std::endl;
    std::string c2 = s.substr(pos+1,pos1-pos-1);
    std::cout<<c2<<std::endl;
    return 0;
}