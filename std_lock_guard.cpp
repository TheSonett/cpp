/*
* TOPICS: std::lock_guard<std::mutex> 
* 
* 0. It is very light weight wrapper for owning mutex on scoped basis.
  1. It acquires mutex lock the moment you create the object of lock_guard.
  2. It automatically removes the lock while goes out of scope.
  3. You can not explicitly unlock the lock_guard.
  4. You can not copy lock_guard.
*/

#include <iostream>
#include <thread>
#include <mutex>

static int count = 0;
std::mutex mutex;

void Worker(const std::string& name, int limit)   
{
	std::lock_guard<std::mutex> lock(mutex); // working as same as lock() & unlock()

	for (int i = 0; i < limit; i++) {
		std::cout << name << std::endl;
		count++;
	}
}


int main()
{
	std::thread t1(Worker, "Joy", 10);
	std::thread t2(Worker, "Saha", 10);

	t1.join();
	t2.join();

	std::cout << "Count: " << count << std::endl;

	std::cin.get();
}