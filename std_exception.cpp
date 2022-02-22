//std::exception	This is an exceptionand the parent class of all standard C++ exceptions.
//std::bad_alloc	This exception is thrown by a new keyword.
//std::bad_cast	This is an exception thrown by dynamic_cast.
//std::bad_exception	A useful device for handling unexpected exceptions in C++ programs.
//std::bad_typeid	An exception thrown by typeid.
//std::logic_error	This exception is theoretically detectable by reading code.
//std::domain_error	This is an exception thrown after using a mathematically invalid domain.
//std::invalid_argument	An exception thrown for using invalid arguments.
//std::length_error	An exception thrown after creating a big std::string.
//std::out_of_range	Thrown by at method.
//std::runtime_error	This is an exception that cannot be detected via reading the code.
//std::overflow_error	This exception is thrown after the occurrence of a mathematical overflow.
//std::range_error	This exception is thrown when you attempt to store an out - of - range value.
//std::underflow_error	An exception thrown after the occurrence of mathematical underflow.

//Note: Integer divide by zero is not an exception in standard C++.

#include <iostream>
#include <exception>
#include <cassert>

struct MyException : public std::exception {
	const char* what() const throw() override {
		return "Integer division not possible!";
	}
};

int Division(int& a, int& b) {
	if (b == 0) {
		throw MyException();
	}
	return a / b;
}


int main()
{
	int a, b, c;
	std::cout << "Enter first number: ";
	std::cin >> a;


	std::cout << "Enter second number: ";
	std::cin >> b;

	//assert(b != 0 && "Integer divisible by zero not possible!"); // This works because char* can be converted to bool and that it never will be false (since the address is not 0).
	//c = a / b;
	//std::cout << "The division is: " << c << std::endl;

	/*try {

		if (b == 0) {
			throw std::exception("Integer divisible by zero not possible!");
		}

		c = a / b;
		std::cout << "The division is: " << c << std::endl;
	}
	catch (const std::exception &ex) {
		std::cerr << "Exception occured! : " << ex.what() << std::endl;
	}*/


	// User-defined exception
	try {
		c = Division(a, b);
		std::cout << "The division is: " << c << std::endl;
	}
	catch (std::exception& ex) {
		std::cerr << "Exception occured!: " << ex.what() << std::endl;
	}


	std::cin.get();
}