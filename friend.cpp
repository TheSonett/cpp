#include <iostream>

class Base {
private:
	void show() {
		std::cout << "Base Class" << std::endl;
	}

	friend class Derived; // making Derived as a friend of Base
};

class Derived {
private:
	void Fun() {
		std::cout << "Derived Class" << std::endl;
	}

	void DD() {
		Base b; // Here, We are trying to access the private members of Base class & we can do that because in base class we defined Derived as a friend of Base.
		b.show();
	}

	friend int main(); // making main() method as a friend of Derived
};

int main()
{
	Derived dr;
	dr.Fun();
	dr.DD();

	std::cin.get();
}