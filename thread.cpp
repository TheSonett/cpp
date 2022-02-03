/* Notes:
* 
* Thread:
* 
* 1. In every application there is a default thread which is main(), 
	in side this we create other threads.
* 
* 2. A thread is also known as lightweight process. 
	Idea is achieve parallelism b dividing a process into multiple threads.
* 
* For example:
* (a) The brower has multiple tabs that can be different threads.
* (b) MS Word must be using multiple threads, one thread to format the text, 
		another thread to process inputs (spell checker).
* (c) VS Code's Intellicence
* 
* WAYS TO CREATE THREADS IN C++11
	1. Function Pointers
	2. Lambda Functions
	3. Functors
	4. Member Functions
	5. Static Member functions
*/

#include <iostream>
#include <thread>


using namespace std::literals::chrono_literals;

static bool s_Finished = false;

void DoSomething() {

	std::cout << "Do Somehting() --- Thread ID = " << std::this_thread::get_id() << "\n\n";

	while (!s_Finished) {
		std::cout << "Do something......\n";
		std::this_thread::sleep_for(1s);
	}
}


int main()
{
	std::thread worker(DoSomething); // here, worker thread takes a function pointer**

	// Do some work below while DoSomething() thread is running.....

	std::cin.get(); // wait for user to press enter
	s_Finished = true;

	worker.join(); // wait for DoSomething() thread to finish it's work
	// ---------------- thread finished

	std::cout << "main() --- Thread ID = " << std::this_thread::get_id() << std::endl;

	std::cin.get();
}