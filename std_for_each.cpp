#include <iostream>
#include <vector>
#include <algorithm> // for_each()


// Multiply function for  for_each loop to print square of each number
void Multiply(int& n)
{
	n *= n;
	std::cout << n << " ";
}

// Calculating sum using struct & operator overloading
struct Sum {
	int sum = 0; // or int sum{ 0 };
	void operator()(int& n) {
		sum += n;
	}
};

int main()
{
	std::vector <int> vec = { 3, 4, 5, 7, 10, 223, 13 };

	// Note: for_each function takes the first value, last value & a function
	// Here, I don't create aa function. I use the lambda expression
	std::cout << "Before : ";
	std::for_each(vec.begin(), vec.end(), [](const int &n) {
		std::cout << " " << n;
	});
	printf("\n");

	// We will now increment by 1 of each value of vector.
	// As, the value is changing, we are not taking const keyword
	std::for_each(vec.begin(), vec.end(), [](int& n) {
		n++;
	});


	// Printing each value
	std::cout << "After: ";
	std::for_each(vec.begin(), vec.end(), [](const int& n) {
		std::cout << " " << n;
	});
	printf("\n\n");

	// Lambda expression = [captures](parameter) modifiers -> return type {}
	// [&] = Pass the reference
	// [=] = Pass the value

	// If we try to pass a value which is outside the lambda function & we want to modify the value inside lambda function,
	// we can't pass by value [=], to enable that, we have to use mutable keyword but still changes will not reflect in that variable.

	int sum = 0;
	std::for_each(vec.begin(), vec.end(), [&](int& n) mutable -> int {
		sum += n;
		return sum;
	});

	std::cout << "Sum is: " << sum << std::endl;


	// Priting sum using struct Sum.
	// We are taking the return value of the structure Sum, and storing the value in an object. Then we're using that object to print sum;
	Sum sumObj = std::for_each(vec.begin(), vec.end(), Sum());
	std::cout << "Sum is: " << sumObj.sum << std::endl;


	std::cout << "Square of each number: ";
	std::for_each(vec.begin(), vec.end(), Multiply);

	std::cin.get();
}