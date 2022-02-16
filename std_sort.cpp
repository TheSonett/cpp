#include <iostream>
#include <algorithm>
#include <vector>

/*
*	partial_sort- sorts until some place
	nth_element - sorts one element as if everything would have been sorted, left is smaller but not sorted, right is bigger but not sorted
	sort_heap - over and over again pop_heap

	inplace_merge(beg1, beg2, end) :- This function is used to sort two consecutively placed sorted ranges in a single container. 
	It takes 3 arguments, iterator to beginning of 1st sorted range, iterator to beginning of 2nd sorted range, and iterator to last position.
	two sorted halves into one sorted thing.
*/


int main() 
{
	//std::vector<int> nums = { 5, 2, 1, 43, 13, 55, 49 };

	/*std::cout << "Using std::sort()" << std::endl;
	std::sort(nums.begin(), nums.end());
	for (const int& i : nums) {
		std::cout << i << " ";
	}*/


	/*printf("\n\n");
	std::cout << "Using std::partial_sort()" << std::endl;
	std::partial_sort(nums.begin(), nums.begin() + 3, nums.end());
	for (const int& i : nums) {
		std::cout << i << " ";
	}*/

	/*printf("\n\n");
	std::cout << "Using std::nth_element()" << std::endl;
	std::nth_element(nums.begin(), nums.begin() + 1, nums.end());
	for (const int& i : nums) {
		std::cout << i << " ";
	}*/

	printf("\n\n");
	std::vector<int> v1 = { 1, 3, 4, 5, 20, 30 };
	std::vector<int> v2 = { 1, 5, 6, 7, 25, 30 };
	std::vector<int> vec(v1.size() + v2.size()); // don't use sizeof()

	std::vector<int>::iterator it = std::copy(v1.begin(), v1.end(), vec.begin());
	std::copy(v2.begin(), v2.end(), it);

	std::cout << "Using std::inplace_merge()" << std::endl;
	std::inplace_merge(vec.begin(), it, vec.end());
	for (const int& i : vec) {
		std::cout << i << " ";
	}

	
	std::cin.get();
}