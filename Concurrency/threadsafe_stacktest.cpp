#include <memory>
#include <stack>
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>
#include <atomic>
#include <numeric>
#include <cassert>

template<typename T>
class threadsafe_stack
{
private:
    std::stack<T> s;
    mutable std::mutex mtx;

public:
    threadsafe_stack() = default;

    threadsafe_stack(const threadsafe_stack& other)
    {
        std::scoped_lock lock(mtx, other.mtx);
        s = other.s;
    }

    void operator=(const threadsafe_stack&) = delete;

    void push(T data)
    {
        std::lock_guard<std::mutex> gmtx(mtx);
        s.push(std::move(data));
    }

    // 尝试 Pop，若栈空返回 false，不抛异常（更适合高并发测试）
    bool try_pop(T& value)
    {
        std::lock_guard<std::mutex> gmtx(mtx);
        if (s.empty()) return false;
        value = std::move(s.top());
        s.pop();
        return true;
    }

    std::shared_ptr<T> pop()
    {
        std::lock_guard<std::mutex> gmtx(mtx);
        if (s.empty()) return nullptr;
        std::shared_ptr<T> res = std::make_shared<T>(std::move(s.top()));
        s.pop();
        return res;
    }

    bool empty() const
    {
        std::lock_guard<std::mutex> gmtx(mtx);
        return s.empty();
    }
};

// ==================== 压力测试主逻辑 ====================

const int NUM_PRODUCERS = 4;        // 生产者线程数
const int NUM_CONSUMERS = 4;        // 消费者线程数
const int ITEMS_PER_PRODUCER = 10000; // 每个生产者 Push 的数据量

int main()
{
    threadsafe_stack<int> stack;

    std::atomic<bool> producers_finished{false}; // 标识生产者是否全部完成
    std::atomic<long long> total_pushed_sum{0};  // 所有 Push 进去的数值之和
    std::atomic<long long> total_popped_sum{0};  // 所有 Pop 出来的数值之和
    std::atomic<int> total_popped_count{0};      // 成功 Pop 的元素总数

    std::vector<std::thread> threads;

    // 1. 启动生产者线程 (Push)
    for (int i = 0; i < NUM_PRODUCERS; ++i)
    {
        threads.emplace_back([&stack, &total_pushed_sum, i]() {
            long long local_sum = 0;
            for (int j = 0; j < ITEMS_PER_PRODUCER; ++j) {
                int val = i * ITEMS_PER_PRODUCER + j; // 生成唯一的数据值
                stack.push(val);
                local_sum += val;
            }
            total_pushed_sum += local_sum;
        });
    }

    // 2. 启动消费者线程 (Pop)
    for (int i = 0; i < NUM_CONSUMERS; ++i)
    {
        threads.emplace_back([&stack, &total_popped_sum, &total_popped_count, &producers_finished]() {
            long long local_sum = 0;
            int local_count = 0;
            int val = 0;

            while (true) {
                // 尝试弹出数据
                if (stack.try_pop(val)) {
                    local_sum += val;
                    local_count++;
                } else {
                    // 如果栈空了，检查生产者是否都已经结束
                    if (producers_finished.load()) {
                        // 再次确认栈是否真的空了（防止最后一点数据漏读）
                        if (!stack.try_pop(val)) break;
                        local_sum += val;
                        local_count++;
                    } else {
                        // 生产者还在运行，暂时让出 CPU 稍后重试
                        std::this_thread::yield();
                    }
                }
            }
            total_popped_sum += local_sum;
            total_popped_count += local_count;
        });
    }

    // 3. 等待所有生产者线程完成
    for (int i = 0; i < NUM_PRODUCERS; ++i) {
        threads[i].join();
    }
    producers_finished.store(true); // 标记生产者已完成

    // 4. 等待所有消费者线程完成
    for (int i = NUM_PRODUCERS; i < NUM_PRODUCERS + NUM_CONSUMERS; ++i) {
        threads[i].join();
    }

    // 5. 校验测试结果
    int expected_total_items = NUM_PRODUCERS * ITEMS_PER_PRODUCER;
    std::cout << "========== 测试结果 ==========" << std::endl;
    std::cout << "期望弹出元素总数: " << expected_total_items << std::endl;
    std::cout << "实际弹出元素总数: " << total_popped_count << std::endl;
    std::cout << "Push 数值和: " << total_pushed_sum << std::endl;
    std::cout << "Pop  数值和: " << total_popped_sum << std::endl;

    // 断言验证
    assert(stack.empty() && "错误：所有操作完成后，栈应该为空！");
    assert(total_popped_count == expected_total_items && "错误：丢失或重复处理了元素！");
    assert(total_pushed_sum == total_popped_sum && "错误：弹出的数据与写入的数据不一致！");

    std::cout << "\n✅ 测试成功！栈在多线程并发下安全且数据无损坏。" << std::endl;

    return 0;
}