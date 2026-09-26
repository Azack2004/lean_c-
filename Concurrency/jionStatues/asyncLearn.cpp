#include <iostream>
#include <future>
#include <chrono>
#include <thread>

int async_task() {
    std::this_thread::sleep_for(std::chrono::seconds(1)); // 模拟耗时 2 秒的任务
    return 42;
}

int main() {
    std::cout << "主线程：启动异步任务..." << std::endl;
    
    // 1. std::async 立即返回 fut，子线程开始后台跑 async_task
    std::future<int> fut = std::async(std::launch::async, async_task);

    std::cout << "主线程：做点别的事情..." << std::endl;

    std::cout << "主线程：准备获取结果，准备调用 get()..." << std::endl;

    std::this_thread::sleep_for(std::chrono::seconds(2)); // 模拟耗时 2 秒的任务
    // 2. 这里会阻塞主线程，直到子线程 return 42
    int result = fut.get(); 

    std::cout << "主线程：拿到结果了！结果是: " << result << std::endl;
    return 0;
}
