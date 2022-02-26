#include <iostream>
#include <variant> // C++17

int main()
{
	std::variant<std::string, int> data;

	std::cout << sizeof(std::string) << std::endl;
	std::cout << sizeof(int) << std::endl;

	std::cout << sizeof(data) << std::endl;


	data = std::string("Joy");
	std::cout << std::get<std::string>(data) << "\n";

	data = 23;
	auto* value = std::get_if<std::string>(&data); // or use try-catch or data.index()

	if (value != nullptr) {
		std::cout << std::get<std::string>(data) << "\n"; // bad variant exception error, because data is now integer
	}
	else {
		std::cout << std::get<int>(data) << "\n";
	}


	std::cin.get();
}