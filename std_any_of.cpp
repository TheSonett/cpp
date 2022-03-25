#include <iostream>
#include <vector>
#include <algorithm>


int main()
{
	std::vector<int> values = { 1, 2, 3, 4, 5, -6, -7, 1, 9, 1, 10 };
	auto pred = [](int value) {
		return value > 3; 
	};
	int count = 0;


	/*std::all_of(values.begin(), values.end(), [&](int value) {count++;  return value > -1; }) ? std::cout << "All values are positive" << std::endl : 
		std::cout << "It contains some negative values" << std::endl;
	std::cout << "\nTotal positive values are: " << count << std::endl;*/

	/*std::any_of(values.begin(), values.end(), [](int value) { return value < 0; }) ? std::cout << "We have atleast one negative value" << std::endl :
		std::cout << "All values are positive" << std::endl;*/

	/*std::none_of(values.begin(), values.end(), [](int value) { return value == 10; }) ? std::cout << "We have no element which is exactly 10" : 
		std::cout << "We have atleast one element = 10" << std::endl;*/


	std::vector<int> temp{ 0 };
	temp.resize(values.size()); // new vector must be resized before copying

	std::copy_n(values.begin(), values.size(), temp.begin());
	std::for_each(temp.begin(), temp.end(), [](const int& x) { std::cout << x << " "; });

	std::cout << "\nCount: " << std::count(values.begin(), values.end(), 1); // searching 1 0(n)

	std::cin.get();
}