#include <iostream>
#include <string> // for std::getline
#include <fstream>
#include <optional> // C++17


std::optional<std::string> ReadFileAsString(const std::string& filePath)
{
	std::ifstream stream(filePath);
	std::string result;

	//Note: Reads the whitespace character also
	if (std::getline(stream,result)) {
		stream.close();
		return result;
	}

	//Note: Breaks after reading whitespace character
	/*if (stream >> result) {
		stream.close();
		return result;
	}*/

	return {};
}


int main()
{
	std::optional<std::string> file = ReadFileAsString("src/data.txt");

	std::string value = file.value_or("No Data present in the file!");
	std::cout << value;

	if (file.has_value()) {
		std::cout << "\n\nOpened succesfully!" << std::endl;
	}
	else {
		std::cout << "\n\nFailed to open the file!" << std::endl;
	}

	std::cin.get();
}