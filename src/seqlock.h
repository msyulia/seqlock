#include "spinlock.h"

class Seqlock
{
    Spinlock spinLock;
public:
    Seqlock();
    void lock();
    void unlock();
};
