/*
* 1. partition(beg, end, condition) :- This function is used to partition the elements on basis of condition mentioned in its arguments.
  2. is_partitioned(beg, end, condition) :- This function returns boolean true if container is partitioned else returns false.
* 
* 3. partition_point(begin, end, condition) :- This function returns an iterator pointing to the partition point of container i.e. 
	 the first element in the partitioned range [beg,end) for which condition is not true. The container should already be partitioned for this function to work.
* 
*/

#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
	std::vector<int> vec = { 2, 1, 5, 6, 8, 7 };

	std::is_partitioned(vec.begin(), vec.end(), [](int x) {
		return x % 2 == 0;
		}) ? std::cout << "Vector is partitioned\n": std::cout << "Vector is not partitioned\n";


	std::partition(vec.begin(), vec.end(), [](int x) {
		return x % 2 == 0;
	});

	std::is_partitioned(vec.begin(), vec.end(), [](int x) {
		return x % 2 == 0;
	}) ? std::cout << "Now, Vector is partitioned by user\n" : std::cout << "Still the vector is not partitioned!!!\n";


	std::cout << "\nThe partitioned vector is -> " << std::endl;
	std::for_each(vec.begin(), vec.end(), [](int x) {
		std::cout << x << " ";
	});


	std::vector<int>::iterator i;
	std::vector<int>::iterator it = std::partition_point(vec.begin(), vec.end(), [](int x) {
		return x % 2 == 0;
	});

	std::cout << "\nFetching the values from vector -> " << std::endl;
	for (i = vec.begin(); i != it; i++) {
		std::cout << *i << " ";
	}

	std::cin.get();
}