#include "seqlock.h"

Seqlock::Seqlock() = default;

void Seqlock::BeginWrite()
{
	this->spinLock.lock();
}

void Seqlock::EndWrite()
{
    this->spinLock.unlock();
}

void Seqlock::BeginRead()
{
    // Wait for the writer to finish writing
	while(isWriting());
}

void Seqlock::EndRead()
{
    // If a writer locked the spinlock, start reading again
    if(isWriting())
    {
        this->BeginRead();
    }
}

bool Seqlock::isWriting()
{
    return this->spinLock.getCounter() % 2 == 1;
}
