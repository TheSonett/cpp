//std::mt19937(since C++11) class is a very efficient pseudo - 
//random number generator and is defined in a random header file.
//It produces 32 - bit pseudo - random numbers using the well - 
//known and popular algorithm named Mersenne twister algorithm.std::mt19937 class is 
//basically a type of std::mersenne_twister_engine class.

// Syntax -> mt19937 mt1(seed_value);
// Here mt1 is an instance of the mt19937 class and it takes a seed value to generate 
// an entire sequence.


#include <iostream>
#include <random> // for std::mt19937

int main()
{
	std::mt19937 randomNumber;
	//std::cout << "Random: " << randomNumber;
	std::cout << "\nRandom max value: " << randomNumber.max(); // 4294967295
	std::cout << "\nRandome min value: " << randomNumber.min(); // 0

	std::cin.get();
}