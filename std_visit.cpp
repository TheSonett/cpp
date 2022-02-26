#include <iostream>
#include <variant>

void print(std::variant<bool, int, std::string> data) {
	std::visit([](const auto& x) {
		std::cout << x << std::endl;
	}, data);
}

int main()
{
	std::variant<bool, int, std::string> data;



	data = std::string("Ginger");
	print(data);

	data = 100;
	print(data);

	std::cin.get();
}