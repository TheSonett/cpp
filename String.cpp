#include <iostream>
#include <string>

int main()
{
	std::string str = "abcdefaswljadagawoa";
	while (str.find("a") != std::string::npos) {
		str.replace(str.find("a"), 1, "$");
	}

	std::cout << str << std::endl;

	str.erase(std::remove(str.begin(), str.end(), 'a'), str.end());

	std::cout << str << std::endl;
	std::cin.get();
}