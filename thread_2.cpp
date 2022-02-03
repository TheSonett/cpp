#include <iostream>
#include <thread>
#include <chrono>

static unsigned long long odd, even;

void findOdd(unsigned long long start, unsigned long long end) 
{
	for (unsigned long long i = start; i <= end; i++) {
		if ((i & 1) == 0) {
			even += i;
		}
	}
}

void findEven(unsigned long long start, unsigned long long end) 
{
	for (unsigned long long i = start; i <= end; i++) {
		if ((i & 1) == 1) {
			odd += i;
		}
	}
}

int main()
{
	unsigned long long start = 0, end = 1900000000;
	std::chrono::time_point<std::chrono::steady_clock> startTime = std::chrono::high_resolution_clock::now();

	std::thread t1(findEven, start, end);
	std::thread t2(findOdd, start, end);

	t1.join();
	t2.join();

	//findOdd(start, end);
	//findEven(start, end);

	auto endTime = std::chrono::high_resolution_clock::now();
	std::chrono::duration<float> duration = endTime - startTime;

	std::cout << "Odd : " << odd << "\n";
	std::cout << "Even : " << even << "\n";

	std::cout << "Time took: " << duration.count() * 1000.0f << "ms" << "\n";
}


/* Here, Using multithreading--> Time Took : 7.4s
*	whereas in singlethreading --> Time took : 6s which is faster. So, remember....
* 
*	In reality: Multiple threads don't always speed things up. 
	Multiple threads usually only speed things up if your threads are accessing different hardware resources that can be serviced in parallel. 

	Two threads running CPU-bound tasks on two different cores that don't share memory (or rarely share memory) will probably be faster. 
	If they're sharing memory or hitting the same disk, there's a good chance they're going to slow.
* 
*/