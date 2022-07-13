#include <iostream>
#include <unordered_set>

int main()
{
	std::unordered_set<std::string> StringSet;

	StringSet.insert("JOY");
	StringSet.insert("SONETT");
	StringSet.insert("KONICA");
	StringSet.insert("JHANTU");
	StringSet.insert("JHANTU"); // repeated value will not show

	std::string key = "JOY";

	if (StringSet.find(key) != StringSet.end()) {
		std::cout << key << " is found!" << std::endl;
	}
	else {
		std::cout << key << " is not found!" << std::endl;
	}

	std::unordered_set<std::string>::iterator i;
	for (i = StringSet.begin(); i != StringSet.end(); i++) {
		std::cout << *i << " ";
	}

	std::cin.get();
}