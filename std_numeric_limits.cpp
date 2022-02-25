#include <iostream>
#include <limits>

int main()
{
	std::cout << "The Max value of int is: " << std::numeric_limits<int>::max();
	std::cout << "\nThe Min value of int is: " << std::numeric_limits<int>::min();

	std::cout << "\nThe Max value of uint32_t is: " << std::numeric_limits<uint32_t>::max();
	std::cout << "\nThe Min value of uint32_t is: " << std::numeric_limits<uint32_t>::min();


	std::cin.get();
}