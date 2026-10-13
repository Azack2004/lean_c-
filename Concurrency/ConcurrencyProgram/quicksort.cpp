#include <iostream>
#include <list>
#include <vector>
#include <thread>
#include <atomic>
#include <future>
#include <memory>
#include <mutex>
#include <stack>
#include <algorithm>

// 1. 实现一个简单的线程安全栈（支持多线程推入和弹出）
template<typename T>
class thread_safe_stack
{
private:
    std::stack<T> data;
    mutable std::mutex m;
public:
    thread_safe_stack() {}
    thread_safe_stack(const thread_safe_stack& other) {
        std::lock_guard<std::mutex> lock(other.m);
        data = other.data;
    }

    void push(T new_value) {
        std::lock_guard<std::mutex> lock(m);
        data.push(std::move(new_value));
    }

    // 弹出一个元素，如果为空返回空指针
    std::shared_ptr<T> pop() {
        std::lock_guard<std::mutex> lock(m);
        if (data.empty()) return std::shared_ptr<T>();
        std::shared_ptr<T> const res(std::make_shared<T>(std::move(data.top())));
        data.pop();
        return res;
    }

    bool empty() const {
        std::lock_guard<std::mutex> lock(m);
        return data.empty();
    }
};

// 2. 并行快速排序的核心 sorter 结构体
template<typename T>
struct sorter
{
    struct chunk_to_sort
    {
        std::list<T> data;
        std::promise<std::list<T> > promise;
    };

    thread_safe_stack<chunk_to_sort> chunks;
    std::vector<std::thread> threads;
    unsigned const max_thread_count;
    std::atomic<bool> end_of_data;

    sorter():
        max_thread_count(std::max(2u, std::thread::hardware_concurrency() - 1)),
        end_of_data(false)
    {}

    ~sorter()
    {
        end_of_data = true;
        for(unsigned i = 0; i < threads.size(); ++i)
        {
            if(threads[i].joinable())
            {
                threads[i].join();
            }
        }
    }

    void try_sort_chunk()
    {
        std::shared_ptr<chunk_to_sort> chunk = chunks.pop();
        if(chunk)
        {
            sort_chunk(chunk);
        }
    }

    void sort_chunk(std::shared_ptr<chunk_to_sort> const& chunk)
    {
        chunk->promise.set_value(do_sort(chunk->data));
    }

    void sort_thread()
    {
        while(!end_of_data)
        {
            try_sort_chunk();
            std::this_thread::yield(); // 让出 CPU，避免空转消耗过高
        }
    }

    std::list<T> do_sort(std::list<T>& chunk_data)
    {
        if(chunk_data.empty())
        {
            return chunk_data;
        }

        std::list<T> result;
        result.splice(result.begin(), chunk_data, chunk_data.begin());
        T const& partition_val = *result.begin();

        // 划分数据
        typename std::list<T>::iterator divide_point = 
            std::partition(chunk_data.begin(), chunk_data.end(),
            [&](T const& val){return val < partition_val;});

        chunk_to_sort new_lower_chunk;
        new_lower_chunk.data.splice(new_lower_chunk.data.end(),
                                    chunk_data, chunk_data.begin(),
                                    divide_point);

        std::future<std::list<T> > new_lower =
            new_lower_chunk.promise.get_future();

        // 把左半部分丢进线程安全栈
        chunks.push(std::move(new_lower_chunk));

        // 如果线程数还没满，动态创建新线程
        if(threads.size() < max_thread_count)
        {
            threads.push_back(std::thread(&sorter<T>::sort_thread, this));
        }

        // 当前线程自己去递归处理右半部分
        std::list<T> new_higher(do_sort(chunk_data));
        result.splice(result.end(), new_higher);

        // 边等待左半部分完成，边帮着干活（Work Stealing）
        while(new_lower.wait_for(std::chrono::seconds(0)) != std::future_status::ready)
        {
            try_sort_chunk();
        }

        // 获取左半部分的结果并拼回来
        result.splice(result.begin(), new_lower.get());
        return result;
    }
};

// 3. 对外暴露的并行快排接口
template<typename T>
std::list<T> parallel_quick_sort(std::list<T> input)
{
    if(input.empty())
    {
        return input;
    }
    sorter<T> s;
    return s.do_sort(input);
}

// 4. 测试运行
int main()
{
    std::list<int> numbers = {42, 7, 19, 3, 85, 12, 56, 23, 9, 31, 1, 68, 74, 15};

    std::cout << "Original list: ";
    for(int n : numbers) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    std::list<int> sorted = parallel_quick_sort(numbers);

    std::cout << "Sorted list:   ";
    for(int n : sorted) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    return 0;
}
