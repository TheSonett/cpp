#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

int main()
{
	std::vector<int> nums{2, 3, 6, 3, 9, 10, 23, 11, 67, 44};
	std::priority_queue<int> maxHeap(nums.begin(), nums.end()); // by default It is max-heap
	std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap(nums.begin(), nums.end()); // min-heap

	while (!maxHeap.empty()) {
		std::cout << maxHeap.top() << " ";
		maxHeap.pop();
	}

	printf("\n\n");
	while (!minHeap.empty()) {
		std::cout << minHeap.top() << " ";
		minHeap.pop();
	}


	std::cin.get();
}