// Program to reverse a string
// Example: Input: "JoySaha" -- Output: "ahaSyoJ"

#include <iostream>
#include <stack>

static std::stack<char> stack;

int main() {
	std::string name = "aabbaaa";
	std::string result;

	for (int i = 0; i < name.length(); i++) {
		stack.push(name[i]);
	}

	while (!stack.empty()) {
		result.push_back(stack.top());
		stack.pop();
	}

	std::cout << result << "\n";

	if (name == result) {
		std::cout << "It is a palindrome string!\n";
	}
	else {
		std::cout << "It is not a palindrome string!\n";
	}

	std::cin.get();
}