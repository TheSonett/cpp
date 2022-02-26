#include <iostream>

int main()
{
	// You cannot change the content of a variable but you can change the address of this pointer to point some other variable.
	const int *a = new int; // or
	int* const b = new int;

	// It means you cannot change the contents of that pointer as well as you cannot reassign the actual value it'self
	const int* const c = new int;


	int d = 10;
	a = &d; // can point to other variable like d
	//a = 20; // error -> cannot change it's content

	std::cout << *a << std::endl;

	int e = 20;
	*b = e; // can change the content of pointer b variable
	//b = &e; // error-> cannot point to other variable
	std::cout << *b << std::endl;

	int f = 30;
	//c = &f; // not possible
	//*c = 40; // not possible


	//------------------ breaking promise --------------------
	int* ptr = const_cast<int*>(c);
	ptr = &f; // possible
	*ptr = 40; // possible

	std::cout << *ptr << std::endl;


	std::cin.get();
}