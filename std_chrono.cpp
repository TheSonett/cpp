#include <iostream>
#include <chrono> // for using timing functions
#include <thread>

using namespace std::literals::chrono_literals; // We have to include this to use the 's' in sleep_for() function, otherwise it will not work

struct Timer 
{
	std::chrono::time_point<std::chrono::steady_clock> start, end;
	std::chrono::duration<float> duration;

	// std::time_t sleepTime = std::chrono::system_clock::to_time_t(start); // We can print sleep time by -> std::ctime(&sleepTime)


	Timer()
	{
		start = std::chrono::high_resolution_clock::now(); // We can also use --> start = std::chrono::system_clock::now();
	}

	~Timer()
	{
		end = std::chrono::high_resolution_clock::now();
		duration = start - end;

		float ms = duration.count() * 1000.0f; // gives us the time in miliseccond
		std::cout << "Timer took " << ms << "ms\n";
	}
};

void Function() 
{
	Timer timer; // It will gives us the time after we go out of this scope of Function()

	int i = 5;

	while (i != 0) {
		std::cout << "While Loop....\n";
		std::this_thread::sleep_for(1s); // printing gap 1s
		i--;
	}

	for (int i = 0; i < 5; i++) {
		std::cout << "For Loop....\n";
		std::this_thread::sleep_for(1s);
	}

}


int main()
{
	/*auto start = std::chrono::high_resolution_clock::now(); // It gives us the current time // std::chrono::time_point<std::chrono::steady_clock>(auto) start
	std::this_thread::sleep_for(1s); // It will not work if you don't include the namespace above // sleep the current thread for 1 second
	auto end = std::chrono::high_resolution_clock::now(); // It gives the end time

	std::chrono::duration<float> duration = end - start; // It gives the time gap or how much time it takes
	std::cout << duration.count() << "second" << std::endl; // It gives the time in seconds  */


	Function();


	std::cin.get();
}