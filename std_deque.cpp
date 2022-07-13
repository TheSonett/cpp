#include <iostream>
#include <deque>
// Double ended Queue
static std::deque<int> deque;

int main()
{
	deque.push_back(2);
	deque.push_back(3);
	deque.push_back(4);
	deque.push_back(7);
	deque.push_front(10);

	while (!deque.empty()) {
		std::cout << deque.front() << " ";
		deque.pop_front();
	}

	std::cin.get();
}