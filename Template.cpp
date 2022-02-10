/*
* Templates in C++
* 
* 1. The simple idea is to pass data type as a parameter so that we don’t need to write the same code for different data types.
* 2. We can pass more than one data types as arguments to templates. 
* 3. we can specify default arguments to templates.
*/


#include <iostream>

//template <typename T>
//template <class T, class U>
//template <class T = int>
//template <class T , int max> // We can pass non-type arguments to templates

template <class T>

T Sum(T a, T b) {
	return (a + b);
}

int main()
{
	int r1 = Sum<int>(2, 4);
	float r2 = Sum<float>(2.4f, 4.8f);

	std::cout << r1 << std::endl;
	std::cout << r2 << std::endl;
}