#include "spinlock.h"

template<typename T>
class Seqlock
{
    Spinlock spinLock;
    T storedValue;
public:
    Seqlock(T &value);
    void store(T &value);
    T load();
};
