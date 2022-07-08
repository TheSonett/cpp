#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	// Ranged based for loop // C++17
	std::vector<int> values = { 1,2,3,4,5,6 };
	for (int& i : values) {
		std::cout << i << " ";
	}

	std::cout << std::endl;
	// Ranged based for loop with initialization // C++ 20
	for (std::vector<int> values = { 10,20,30,40 }; int& i: values) {
		std::cout << i << " ";
	}
	
	std::cout << std::endl;
	std::for_each(values.begin(), values.end(), [](int i) {
		std::cout << i << " ";
	});
	std::cin.get();
}