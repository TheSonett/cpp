#include <iostream>
#include <any>

int main()
{
	//std::any data = std::make_any<int>(3);
	//data = "Joy Saha"; // not a string, it's a const char pointer

	std::any data;

	data = 2;
	std::cout << std::any_cast<int>(data);

	data = std::string("\nJoy Saha");
	std::cout << std::any_cast<std::string>(data);

	//std::string& string = std::any_cast<std::string&>(data);

	std::cin.get();
}