#include<iostream>
#include<string>
int main()
{   short short_num = 100 ;
    std::cout<< "short 的内存大小："<< sizeof(short_num) <<" Byte"<< std::endl;
    // Byte 字节 ，八位二进制数，两位十六进制
    int int_num = 100 ;
    std::cout<< "int 的内存大小："<< sizeof(int_num) <<" Byte"<< std::endl;

    float float_num = 3.1527345f ;
    std::cout << "float 的内存大小："<< sizeof(float_num) <<" Byte.  "<< float_num<< std::endl;

    double double_num = 3.1527345 ;
    std::cout << "double 的内存大小："<< sizeof(double_num) <<" Byte.  "<< double_num<<std::endl;

    float f = 3e-2;
    std::cout << f <<std::endl;
    int i = 3e2;
    std::cout << i <<std::endl;

    char c = 'a';
    short size = sizeof(c);
    short b = (short)c;
    std::cout << c << "--"<< size<<std::endl;
    //字符型变量对应的ASII码值
    // a -- 97
    // A -- 65
    std::cout << (short)c <<" ---- "<< b <<std::endl;
    std::cout << "\\a\tad\n"<< std::endl;

    char char_[] = "hello world.";
    std::string string = "hello world."; 
    std::cout <<char_<<"\n"<<string<<std::endl;

    bool right = false;
    std::cout << right << std::endl;
    right = true;
    std::cout << right<<" "<<sizeof(right) << std::endl;

    int a=0;
    std::cout<< "输入的a";
    std::cin >> a;
    std::cout<< "输入的a:"<< a << std::endl;

    std::cin >>string;
    std::cout << string;

    return 0;
}