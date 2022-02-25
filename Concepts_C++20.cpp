/*
* Concepts in C++ 20
*	It is a mechanism to place constrains on your template type parameters. It is used to perform compile-time validation of template arguments
* 
* 1. Standard built in concepts
* 2. Custom concepts
*/


#include <iostream>
#include <cassert>
#include <concepts> // C++ 20

// Standard built in concepts
template <typename T>
void print_number(T n) {
	static_assert(std::is_integral<T>::value, "Must pass an integral agrument");
	std::cout << "n: " << n << std::endl;
}

template <typename T>
requires std::integral<T>

T add(T a, T b) {
	return a + b;
}

template <typename T>
T multi(T a, T b) requires std::integral<T> {
	return a * b;
}

auto subtract(std::integral auto a, std::integral auto b) {
	return a / b;
}

// Custom concepts
template <typename T>
concept MyIntegral = std::is_integral_v<T>;


template <typename T>
concept MyMultip = requires(T a, T b) {
	a * b;
};

template <MyMultip Y>
Y add2(Y a, Y b) {
	return a + b;
}


int main()
{
	print_number(2);
	//print_number(2.5f); // error


	int sum = add(2, 3);
	//int sum = add(2.5, 3.7); // error
	std::cout << sum << std::endl;


	std::cin.get();
}