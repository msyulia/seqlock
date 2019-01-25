## Sequence lock implementation in C++

A seqlock is a special locking mechanism used in Linux for supporting fast writes of shared variables between two parallel operating system routines. 

It is a reader-writer consistent mechanism which avoids the problem of writer starvation. A seqlock consists of storage for saving a sequence number in addition to a lock. 
The lock is to support synchronization between two writers and the counter is for indicating consistency in readers.

## How it works?

Sequence locks use spinlocks to synchronize writers. 
When reading it waits for the spinlock counter to be even - writer finished writing.

## API

Just instantiate a `Seqlock` object and use the methods `BeginRead`, `EndRead`, `BeginWrite`, `EndWrite`.
Be aware that this lock doesn't support recurrent locking, so calling for example `BeginWrite` twice on the same thread
without unlocking will cause a deadlock 
