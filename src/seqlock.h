#include "spinlock.h"

class Seqlock
{
private:
    Spinlock spinLock = Spinlock();
    bool isWriting();
public:
    Seqlock();
    void BeginRead();
    void EndRead();

    void BeginWrite();
    void EndWrite();
};
