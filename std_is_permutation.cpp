/*
* Permutation: Two containers are said to be a permutation of each other if the arrangement of elements in
  the two containers is different.

  The is_permutation() is a built-in function in C++ STL which is used to check whether two given containers 
  are permutations of each other or not.

*/


// is_permutation example
#include <iostream>     // std::cout
#include <algorithm>    // std::is_permutation
#include <array>        // std::array
#include <vector>

#define N 7

int main() {
	std::array<int, N> foo = { 2, 3, 1, 4, 5, 2, 2 };
	std::array<int, N> bar = { 3, 1, 4, 5, 1, 2, 2 };

	if (std::is_permutation(foo.begin(), foo.end(), bar.begin())) {
		std::cout << "foo and bar containing the same elements.\n";
	}
	else {
		std::cout << "foo and bar not containing the same elements.\n";
	}

	std::cin.get();

	printf("\n");

	// All elements in the two vectors are unique
	std::vector<int> v1 = { 10, 20, 3, 5 };
	std::vector<int> v2 = { 20, 10, 5, 3 };

	if (std::is_permutation(v1.begin(), v1.end(), v2.begin())) {
		std::cout << "YES\n";
	}
	else {
		std::cout << "NO\n";
	}

	// When elements in the two vectors are duplicate
	std::vector<int> v3 = { 10, 20, 3, 5, 20 };
	std::vector<int> v4 = { 20, 10, 5, 3, 5 };

	if (std::is_permutation(v3.begin(), v3.end(), v4.begin())) {
		std::cout << "YES\n";
	}
	else {
		std::cout << "NO\n";
	}

	std::cin.get();

	//OUTPUT 
	//  YES
	//	NO
	//
}