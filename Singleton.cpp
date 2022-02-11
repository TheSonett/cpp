// Singleton design pattern is a software design principle that is used to restrict the instantiation of a class to one object.
// This is useful when exactly one object is needed to coordinate actions across the system

// namespace & singleton are almost same but in class we can mention the visibility like private , public..but not in the namespace kind of stuffs

#include <iostream>

class Singleton 
{
private:
	Singleton() {}
public:

	Singleton(const Singleton&) = delete; // not allowing copy constructor

	static Singleton& GetInstance() {
		static Singleton instance;
		return instance;
	}

	void show() {
		std::cout << "Do something...." << std::endl;
	}

	void data(int x) {
		std::cout << x << std::endl;
	}
};

//Singleton Singleton::instance;

int main()
{
	Singleton::GetInstance().show();
	Singleton::GetInstance().data(10);

	std::cin.get();
}