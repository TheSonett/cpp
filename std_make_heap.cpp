/*
*  std::make_heap(begin(numbers), end(numbers)); -> makes a heap out of random number
*/


#include <iostream>
#include <vector>

#include <algorithm> // for STL algorithms

int main()
{

	// std::make_heap
	std::vector<int> vec = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	std::make_heap(vec.begin(), vec.end());
	
	std::cout << "Making a collection of numbers a max-heap tree ->" << std::endl;
	for (const int& n : vec) {
		std::cout << n << " ";
	}

	// adding an element into a heap
	vec.push_back(10);
	std::push_heap(vec.begin(), vec.end());

	printf("\n\n");
	std::cout << "After inserting an element ->" << std::endl;
	for (const int& n : vec) {
		std::cout << n << " ";
	}


	// removing an element from heap
	std::pop_heap(vec.begin(), vec.end());
	vec.pop_back();

	printf("\n\n");
	std::cout << "After removing an element ->" << std::endl;
	for (const int& n : vec) {
		std::cout << n << " ";
	}


	// sorting a heap tree
	std::sort_heap(vec.begin(), vec.end());
	printf("\n\n");
	std::cout << "After sorting this max-heap, we get ->" << std::endl;
	for (const int& n : vec) {
		std::cout << n << " ";
	}

	std::cin.get();
}