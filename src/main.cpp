#include <iostream>
#include <thread>

#include "seqlock.h"

// First test
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

// Second test
struct Data
{
public:
	int x, y, z;

	Data(int x, int y, int z) : x(x), y(y), z(z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}

	void store(int x, int y, int z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}

	Data load()
	{
		return Data(x, y, z);
	}
};

Data testData = Data{0, 0, 0};
Seqlock<Data> seqlock = Seqlock(testData);


int main()
{
	// First test
	{
		std::cout << "First test" << std::endl;

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
	}

	// Second test
	{
		std::cout << "Second test" << std::endl;

		std::thread my_thread = std::thread(&Seqlock<Data>::store,
				Seqlock<Data>(testData),
				1, 2, 3);
	}



	return 0;
}