#include "seqlock.h"

template<typename T>
Seqlock<T>::Seqlock(T &value)
{
	this->spinLock = Spinlock();
}

template<typename T>
void Seqlock<T>::store(T &value)
{
	this->spinLock.lock();

	// Critical section
	this->storedValue.store(value);

	this->spinLock.unlock();
}

template<typename T>
T Seqlock<T>::load()
{
	T result = NULL;
	while(this->spinLock.getCounter() % 2 == 1)
	{
		result = this->storedValue.load();
	}
	return result;
}