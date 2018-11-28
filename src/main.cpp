#include <iostream>
#include <thread>

#include "spinlock.h"

int globalVariable = 0;
Spinlock spinlock = Spinlock();

void func(int ammount)
{
	spinlock.lock();

	for (int i = 0; i < ammount; i++)
	{
		globalVariable++;
	}

	spinlock.unlock();
}

int main()
{
	std::thread threads[5];
	for (int i = 0; i < 5; i++)
	{
		threads[i] = std::thread(func, i);
	}

	for (auto &thread : threads)
	{
		thread.join();
	}

	std::cout << globalVariable;

	return 0;
}