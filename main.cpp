#include <iostream>
#include <vector>

static std::vector<int> vec;

void subArray_1(int arr[], int size, int k) {
	for (int i = 0; i <= size - k; i++) {
		int sum = 0;
		for (int j = i; j < k + i; j++) {
			sum += arr[j];
		}

		vec.push_back(sum);
	}

	for (int i : vec) {
		std::cout << i << " ";
	}
}

void subArray_2(int arr[], int size, int k) {
	int sum = 0;

	// Get the initial sum of size k
	for (int i = 0; i < k; i++) {
		sum += arr[i];
	}

	std::cout << sum << " ";


	// remove the first element & add next element by sliding the window by 1
	for (int i = k; i < size; i++) {
		sum = (sum - arr[i - k]) + arr[i]; // important (6 - 1 + 4), (6 - 2 + 5) .... etc

		std::cout << sum << " ";
	}

}


int main()
{
	int arr[6] = {1, 2, 3, 4, 5, 6};
	int size = sizeof(arr) / sizeof(arr[0]);
	int k = 3;

	subArray_2(arr, size, k);
	

	std::cin.get();
}