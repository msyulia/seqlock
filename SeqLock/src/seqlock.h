#include "spinlock.h"

class Seqlock
{
private:
	Spinlock* spinLock;
    bool isWriting();
public:
    Seqlock();
    void BeginRead();
    void EndRead();

    void BeginWrite();
    void EndWrite();
};
