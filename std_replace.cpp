#include <iostream>
#include <string>
#include <algorithm>

int main()
{
	std::string string = "arjkfgasfaseakya";
	std::replace(string.begin(), string.end(), 'a', '$');
	std::cout << string << std::endl;


	std::string name = "Joy Saha";
	for (int i = 0; name[i] != '\0'; i++) {
		if (name[i] == 'a') {
			name[i] = '@';
		}
	}

	std::cout << name << std::endl;
	std::cin.get();
}