#include "spinlock.h"

Spinlock::Spinlock()
{
    counter.store(0, std::memory_order_release);
}

void Spinlock::lock()
{
    int locked = 1;
    int unlocked = 0;
    // Wait for the lock to release and then lock
    while (counter.compare_exchange_strong(locked,
            unlocked,
            std::memory_order_acq_rel));
}

void Spinlock::unlock()
{
    int unlocked = 0;
    counter.exchange(unlocked, std::memory_order_acq_rel);
}

int Spinlock::getCounter()
{
    return counter.load(std::memory_order_acquire);
}
