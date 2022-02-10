/* std::async and its usage like how to create task.
There are three different launch policy for creating task using std::async are as follows :

1. std::launch::async
2. std::launch::deffered
3. std::launch::async | std::launch::deffered

*/


#include <iostream>
#include <thread>
#include <future>

using namespace std::chrono;

int findOddSum(int start, int end)  // we cannot write int& start
{
	int OddSum = 0;
	for (int i = start; i <= end; i++) {
		if ((i & 1) == 1) {
			OddSum += i;
		}
	}
	return OddSum;
}


int main()
{
	int start = 0, end = 10;

	//std::future<int> OddSum = std::async(std::launch::async, findOddSum, start, end); // It starts executing findOdd()
	std::future<int> OddSum = std::async(std::launch::deferred, findOddSum, start, end); // It will start executing findOdd() when It gets call by .get() function
	std::cout << OddSum.get() << std::endl;

	std::cin.get();
}
