/*

#include<iostream>
#include<thread>
#include<atomic>
#include<queue>
#include<chrono>
std::atomic<int> count{0};
std::vector<int> q;
std::atomic<bool> stop{false};
void produce()
{
    q.reserve(30);
    for(int i=0;i<30;i++)
    {
        q.push_back(i);
    }
    count.store(30,std::memory_order_release);

}
void consumer()
{
    int index;
    while(true)
    {
        if(count.load(std::memory_order_acquire)==0)
        {
            stop.store(true,std::memory_order_release);
        }
        if(stop.load(std::memory_order_acquire))
        {
            break;
        }
        if((index = count.fetch_sub(1,std::memory_order_acquire))>0)
        {
            std::cout<<q[index-1]<<std::endl;    
        }
        else{
            continue;
        }
        
    }

}
int main()
{
    std::thread t1(produce);
    std::thread t2(consumer);
    std::thread t3(consumer);
    t1.join();
    t2.join();
    t3.join();
    return 0;
}
*/
#include <iostream>
#include <thread>
#include <atomic>
#include <vector>

constexpr int TOTAL_COUNT = 30;

// 1. 初始化 count 为 0（而不是 -1）
std::atomic<int> count{0}; 
std::atomic<bool> run{false};
std::vector<int> q;

void produce() {
    q.reserve(TOTAL_COUNT); // 避免 vector 扩容导致的内存重新分配
    for (int i = 0; i < TOTAL_COUNT; i++) {
        q.push_back(i);
    }
    // 生产者完成写入后，一次性发布 release 信号
    count.store(TOTAL_COUNT, std::memory_order_release);
    
}

void consumer(int id) {
    while (count.load(std::memory_order_acquire) == 0) {
        #if defined(__x86_64__)
        _mm_pause(); // 加上 pause 指令降低 CPU 功耗
        #endif
    }
    while (true) {
        // 先读取当前剩余数量
        int current = count.load(std::memory_order_relaxed);
        
        // 如果已经没有数据可领了，直接退出循环
        if (current <= 0) {
            break;
        }

        // 尝试抢夺数据：fetch_sub 返回的是减 1 前的旧值
        int index = count.fetch_sub(1, std::memory_order_acquire);
        
        if (index > 0) {
            // index - 1 才是安全的索引（范围在 29 到 0）
            // 依赖释放序列，此处安全读取 q[index-1]
            std::cout << "Consumer " << id << " got: " << q[index - 1] << "\n";
        } else {
            // 如果 index <= 0，说明被别的线程抢先抽干了，直接退出
            break;
        }
    }
}

int main() {
    std::thread t1(produce);
    std::thread t2(consumer, 1);
    std::thread t3(consumer, 2);

    t1.join();
    t2.join();
    t3.join();
    return 0;
}
