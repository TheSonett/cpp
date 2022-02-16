/*
*   rotate - takes last element into first place
	shuffle - arranges list in random order
	next_permutation - reverses sort if is sorted normally, can be used for generating all possible arrangements
	prev_permutation - reverses sort to normal if sorted like reversed
	reverse - reverses the element collection
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <random>

int main()
{
	std::vector<int> vec = { 1, 4, 7, 5, 8, 10, 12, 2, 6 };
	std::rotate(vec.begin(), vec.begin() + 3, vec.end());
	
	std::cout << "After rotating 3 times, the vector is -> " << std::endl;
	for (const int& i : vec) {
		std::cout << i << " ";
	}

	std::shuffle(vec.begin(), vec.end(), std::default_random_engine(1));

	std::cout << "\nAfter shuffling the vector 2 times -> " << std::endl;
	for (const int& i : vec) {
		std::cout << i << " ";
	}

	std::cin.get();
}