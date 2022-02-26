#include <iostream>

class Base
{
public:
	Base() {
		std::cout << "Base constructor created!!" << std::endl;
	}
	virtual ~Base() {
		std::cout << "Base destructor called!!" << std::endl;
	}
};

class Derived : public Base
{
public:
	Derived() {
		std::cout << "Derived constructor created!!" << std::endl;
	}
	~Derived() {
		std::cout << "Derived destructor called!!" << std::endl;
	}
};

int main()
{
	Base* obj = new Derived(); // base type pointer = Derived type instance/object
	delete obj;

	std::cin.get();
}