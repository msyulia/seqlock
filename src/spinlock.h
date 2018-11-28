#include <atomic>
class Spinlock
{
    std::atomic_int counter;
public:
    Spinlock();
    void lock();
    void unlock();
    int getCounter();
};