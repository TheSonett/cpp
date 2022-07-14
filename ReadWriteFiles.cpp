#include <iostream>
#include <fstream>
#include <string>

// But what if, we have data which may or may not be there in the file!!! How do we know???
// What happends if the file could not be read? what happens if we couldn't load the file if it's not present? etc... 


int main()
{
	std::fstream myFile;

	// Writing in the file
	myFile.open("Hello.txt", std::ios::out); // write
	if (myFile.is_open()) {
		myFile << "Hello Joy!\n";
		myFile << "Welcome to the C++ IO System!\n";
		myFile.close();
	}


	//myFile.open("Hello.txt", std::ios::out); // It will overwrite the file content
	//if (myFile.is_open()) {
	//	myFile << "Hello Joy!\n";
	//	myFile.close();
	//}

	myFile.open("Hello.txt", std::ios::app); // append
	if (myFile.is_open()) {
		myFile << "C++ is too hard :(\n";
		myFile.close();
	}


	// Reading file contents
	std::string myString;
	myFile.open("Hello.txt", std::ios::in); // read
	if (myFile.is_open()) {
		std::string fileContent;
		while (std::getline(myFile, fileContent)) {
			std::cout << fileContent << std::endl;
			myString.append(fileContent);
		}

		myFile.close();
	}

	std::cout << myString << std::endl;

	std::cin.get();
}