// Function objects are objects specifically designed to be used with a syntax similar to that of functions.
// Instances of std::function can store, copy, and invoke any Callable target -- functions, lambda expressions, 
// bind expressions, or other function objects, as well as pointers to member functionsand pointers to data members.


#include <iostream>
#include <functional>

void Function(const int& val) {
	std::cout << "The value is: " << val << std::endl;
}

void Function2(const int& val, const int &val2) {
	std::cout << "The values are: " << val  << " , " << val2 << std::endl;
}



int main()
{
	int val = 20, val2 = 10;

	std::function<void(const int&)> func = Function;
	std::function<void(const int&, const int&)> func2 = Function2;

	func(val);
	func2(val, val2);

	std::cin.get();
}