#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex mtx;
std::condition_variable cv;
int a = 0;
bool stop = false;
void processNum()
{
    std::unique_lock<std::mutex> lock(mtx);
    while (!stop)
    {
        // 等待 a 是 7 的倍数
        cv.wait(lock, [] {
            return a % 7 == 0 || stop;
        });
        if (stop)
            break;
        // 跳过这个 7 的倍数
        std::cout << "子线程跳过: " << a << std::endl;
        ++a;
        // 把锁交还给主线程
        cv.notify_one();
    }
}

int main()
{
    std::thread t(processNum);
    std::unique_lock<std::mutex> lock(mtx);
    while (a < 100)
    {
        // 如果 a 是 7 的倍数
        if (a % 7 == 0)
        {
            // 告诉子线程：你该工作了
            cv.notify_one();
            // 等子线程把 a 加 1
            cv.wait(lock, [] {
                return a % 7 != 0;
            });
            continue;
        }

        // 普通数字由主线程打印
        std::cout << "主线程打印: " << a << std::endl;

        ++a;
    }
    stop = true;
    // 防止子线程还睡着
    cv.notify_one();
    lock.unlock();
    t.join();
    return 0;
}
