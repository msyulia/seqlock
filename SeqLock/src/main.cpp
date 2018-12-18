#include <iostream>
#include <thread>
#include <vector>
#include <string>
#include "seqlock.h"

Seqlock lock = Seqlock();
float protectedVariable = 0;

void writer_func(int amount) 
{
	for (size_t i = 0; i < amount; i++)
	{
		lock.BeginWrite();

		protectedVariable += 1;

		lock.EndWrite();
	}
}

void reader_func(int id)
{
	lock.BeginRead();

	auto value = protectedVariable;

	lock.EndRead();

	auto msg = "TID: " + std::to_string(id) + " Result: " + std::to_string(value) + "\n";
	std::cout << msg;
}

int main() {
	
	auto readers = std::vector<std::thread>(5);
	auto writer = std::thread(writer_func, 5000);
	
	for (size_t i = 0; i < 5; i++)
		readers[i] = std::thread(reader_func, i);

	writer.join();

	for (size_t i = 0; i < 5; i++)
		readers[i].join();

	std::cin.get();
	return 0;
}