#include <iostream>
#include <vector>


int main() 
{
	int x = 3;

	auto lmda = [&x](std::ostream& stream) -> std::ostream& { 
		x++;
		stream << x;
		return stream;
	};

	lmda(std::cout) << std::endl;
	std::cout << x << std::endl;
	std::cin.get();
}