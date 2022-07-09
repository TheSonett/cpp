// Q. Write an algorithm to output 1 if the word1 is a right rotation of word2 otherwise return -1.

#include <iostream>
#include <algorithm>

int isRefectionPosiible(std::string& word1, std::string& word2) {
	int answer = 0;

	// if size doesn't match, then simplily return -1
	if (word1.length() != word2.length()) {
		answer = -1;
		return answer;
	}
	else {
		std::string total = word1 + word1;
		for (int i = 0; i < word1.length(); i++) {
			if (total.substr(i, word2.length()) == word2) {
				answer = 1;
				return answer;
			}
		}
	}

	answer = -1;
	return answer;
}

bool rotateString(std::string s, std::string goal) {
	if (s.length() != goal.length()) {
		return false;
	}
	else {
		std::string total = s + s;
		for (int i = 0; i < s.length(); i++) {
			if (total.substr(i, goal.length()) == goal) {
				return true;
			}
		}
	}

	return false;
}

int main()
{
	std::string word1 = "sample";
	std::string word2 = "lesamp";

	std::cout << isRefectionPosiible(word1, word2) << std::endl;

	std::string str = "Hello";
	std::cout << "Before Rotate : " << str << "\n";

	// right rotation
	//std::rotate(str.begin(), str.begin() + 2, str.end());

	// left rotation
	std::rotate(str.rbegin(), str.rbegin() + 2, str.rend());

	std::cout << "After Rotate  : " << str << "\n";
	std::cin.get();
}