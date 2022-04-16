/*
* 
* A permutation, also called an "arrangement number" or “order”, is a rearrangement of the elements of an 
		ordered list S into a one-to-one correspondence with S itself. 
  A string of length n has n! permutation. 
*/

#include <iostream>
#include <algorithm>
#include <string>

#define N 4

int main()
{
	std::string string = "aba";
	std::sort(string.begin(), string.end());
	
	do 
	{
		std::cout << string << std::endl;
	} while (std::next_permutation(string.begin(), string.end()));

	printf("\n\n");

	int arr[N] = { 0, 0, 0, 1 };
	std::sort(arr, arr + N);

	std::cout << "The possible permutations with "<< N <<" elements: " << std::endl;
	do {
		for (int i = 0; i < N; i++) {
			std::cout << arr[i] << " ";
		}
		std::cout << std::endl;
	} while (std::next_permutation(arr, arr+N));

	printf("\n");
	std::cout << "After loop: " << std::endl;
	for (int i = 0; i < N; i++)
	{
		std::cout << arr[i] << " ";
	}

	// std::cout << sizeof(arr) << std::endl; // 12 size
	std::cin.get();
}