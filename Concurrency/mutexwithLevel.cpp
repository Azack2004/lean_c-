#include <iostream>
#include <mutex>
#include <thread>
#include <climits>
#include <stdexcept>

class LevelMutex
{
private:
    // 真正负责加锁的 mutex
    std::mutex mtx;

    // 这个锁自己的层级
    const unsigned long mutexLevel;

    // 当前线程之前的层级
    unsigned long previousLevel;

    // 每个线程自己拥有一份
    static thread_local unsigned long thisThreadLevel;

public:
    explicit LevelMutex(unsigned long level)
        : mutexLevel(level),
          previousLevel(ULONG_MAX)
    {
    }

    void lock()
    {
        // 新锁必须比当前线程层级低
        if (thisThreadLevel <= mutexLevel)
        {
            throw std::logic_error("lock hierarchy violated");
        }

        // 真正锁住这个对象自己的 mutex
        mtx.lock();

        // 保存之前的层级
        previousLevel = thisThreadLevel;

        // 当前线程进入这个锁的层级
        thisThreadLevel = mutexLevel;
    }

    void unlock()
    {
        // 恢复之前的层级
        thisThreadLevel = previousLevel;

        // 真正解锁
        mtx.unlock();
    }
};

thread_local unsigned long LevelMutex::thisThreadLevel = ULONG_MAX;