#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

int main()
{
	std::ifstream file("C:/Users/sonet/Desktop/player.txt"); // ifstream is used to read data from a file


	std::string informations;

	// reading not line by line
	/*while (file >> informations) {
		std::cout << informations << " ";
	}*/

	// reading line by line
	std::string vertexSource;
	std::string fragmentSource;
	/*if (file.is_open()) {

		while (std::getline(file, informations)) { // std::getline helps to read also the white space characters
			std::cout << informations << std::endl;
		}

		file.close();
	}*/

	std::stringstream buffer;
	buffer << std::ifstream("C:/Users/sonet/Desktop/player.txt").rdbuf();
	informations = buffer.str();

	std::cout << informations;

	std::ofstream send("C:/Users/sonet/Desktop/player.txt", std::ios::app); // std::ios::app helps to avoid overwriting a file

	send << "\nHello";

	// fseek(file_pointer, offset, position) function used to move curser to a specific position


	std::cin.get();
}