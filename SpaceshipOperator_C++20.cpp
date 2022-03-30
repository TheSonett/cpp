#include <iostream>
#include <compare> // C++ 20
#include <vector>

int main()
{
	std::vector<int> vec1 = { 10, 3, 4 };
	std::vector<int> vec2 = { 2, 3, 4 };
	
	std::strong_ordering result = vec1 <=> vec2;

	if (result == 0) {
		std::cout << "They are same" << std::endl;
	}
	else {
		std::cout << "They are not same" << std::endl;
	}

	if(result < 0) {
		std::cout << "vec2 has larger values than vec1" << std::endl;
	}
	else if (result > 0) {
		std::cout << "vec1 has larger values than vec2" << std::endl;
	}

	
	std::cin.get();
}