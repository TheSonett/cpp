#include <iostream>
#include <memory>

class MyClass
{
public:
	MyClass() {
		std::cout << "Constructor Created!" << std::endl;
	}
	~MyClass() {
		std::cout << "Destructor Called!" << std::endl;
	}
};

int main()
{
	{
		std::unique_ptr<MyClass> u1 = std::make_unique<MyClass>();
	}

	std::cin.get();
}