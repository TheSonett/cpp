#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	std::vector<int> vec = { 2, 4, 7, 5 };
	bool isFound = std::binary_search(vec.begin(), vec.end(), 1);

	if (isFound) {
		std::cout << "Element found!!" << std::endl;
	}
	else {
		std::cout << "Element not found!!" << std::endl;
	}

	std::cin.get();
}