#include <iostream>
#include <vector>
#include <string>

#include <algorithm> // std::tranform()
#include <deque>


int main()
{
	std::vector<int> values = { 6, 4, 3, 9, 20, 44 };
	std::string name = "Joy Saha";


	// std::transform = (firstvalue, secondvalue, storevalue, function) . It must return a value
	// changing my name into capital letters & storing the updated result in name variable by returning it's value.

	std::transform(name.begin(), name.end(), name.begin(), [](const char& str) {
		return std::toupper(str);
	});
	std::cout << "Name: " << name << std::endl;


	// std::transform = (firstvalues, lastvalues, firstvalues2, result, function)
	// std::back_inserter = It is a back-insert iterator that inserts new elements at the end of the container to which it is applied.
	//						A back-insert iterator is a special type of output iterator designed to allow algorithms that usually overwrite elements
	//						(such as copy) to instead insert new elements automatically at the end of the container.

	std::vector<int> values2 = { 6, 4, 3, 9, 20, 44 };
	std::vector<int> result;

	std::cout << "\nresult vector: ";
	std::transform(values.begin(), values.end(), values2.begin(), std::back_inserter(result), std::plus<int>());
	
	for (int i : result) {
		std::cout << " " << i;
	}




	// std::inserter = std::inserter constructs an insert iterator that inserts new elements into x in successive locations 
	//				   starting at the position pointed by it. it can be used with only those containers that have insert as 
	//				   one of its methods like in case of vector, list and deque, and so on.
	// 

	std::deque<int> v1 = { 1, 2, 3 };
	std::deque<int> v2 = { 4, 5, 6 };

	std::deque<int>::iterator i1;
	i1 = v2.begin() + 1; // i1 points to next element of 4 in v2

	// copying data to v2
	std::copy(v1.begin(), v1.end(), std::inserter(v2, i1));
	// v2 now contains 4 1 2 3 5 6

	std::cout << "\n\nv1 = ";
	for (int i = 0; i < 3; ++i) {
		std::cout << v1[i] << " ";
	}

	std::cout << "\nv2 = ";
	for (int i = 0; i < 6; ++i) {
		std::cout << v2[i] << " ";
	}



	std::cin.get();
}