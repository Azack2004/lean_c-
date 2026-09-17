#include<iostream>
#include<memory>
#include<stdio.h>
#include <iostream>
#include <memory>
#include <cstdio> // 使用 C 语言文件 API 所需头文件

int main() {
    // 1. 定义自定义删除器 (Lambda 表达式)
    auto fileDeleter = [](FILE* fp) {
        if (fp) {
            fclose(fp);
            std::cout << "File closed automatically" << std::endl;
        }
    };

    // 2. 将删除器的类型（decltype）作为 unique_ptr 的第二个模板参数
    //    并在构造函数中将实际的删除器 Lambda 实例作为第二个实参传入
    std::unique_ptr<FILE, decltype(fileDeleter)> filePtr(
        fopen("test.txt", "w"), 
        fileDeleter
    );

    // 3. 检查文件是否成功打开并写入数据
    if (filePtr) {
        std::cout << "File opened successfully." << std::endl;
        fputs("Hello Smart Pointer!\n", filePtr.get()); // 通过 .get() 获取原始 FILE* 指针
    } else {
        std::cout << "Failed to open file." << std::endl;
    }

    // 4. 离开 main 函数作用域时，filePtr 会自动调用 fileDeleter：
    //    自动执行 fclose(fp) 并打印 "File closed automatically"
    return 0;
}