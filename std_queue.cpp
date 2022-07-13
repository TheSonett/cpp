#include <iostream>
#include <queue>

static std::queue<int> queue;

int main()
{
	queue.push(2);
	queue.push(5);
	queue.push(1);
	queue.push(9);
	queue.push(4);

	while (!queue.empty()) {
		std::cout << queue.front() << " ";
		queue.pop();
	}
	
	std::cin.get();
}