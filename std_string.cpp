#include <iostream>
#include <string>

void* operator new(size_t size) {
	std::cout << "Allocating " << size << " bytes" << std::endl;
	return malloc(size);
}

// Armstrong Number
bool checkArmstrongNumber(const int& num) {
	int temp, sum = 0, digit;
	bool isArm;

	temp = num;
	while (temp != 0) {
		digit = temp % 10; // taking last digit from temp
		sum = sum + (digit * digit * digit); // giving 1
		temp = temp / 10; // giving 37
	}
	if (sum == num)
		isArm = true;
	else
		isArm = false;

	return isArm;
}


int main()
{
	// Checking Palindrome string
	std::string_view name = "abcba";
	std::cout << sizeof(std::string) << std::endl; // 40
	std::cout << sizeof(std::string_view) << std::endl; // 16

	if (name == std::string(name.rbegin(), name.rend())) {
		std::cout << "It is a palindrome\n";
	}
	else {
		std::cout << "It is not a palindrome\n";
	}

	// 153 -> 1 5 3
	bool isArmstrong = checkArmstrongNumber(371);
	std::cout << isArmstrong << std::endl;


	std::cin.get();
}