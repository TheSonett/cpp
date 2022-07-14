#include <iostream>
#include <memory>

class Entity {
private:
	int age;
public:
	Entity() {
		std::cout << "Object Created!" << std::endl;
	}

	~Entity() {
		std::cout << "Object Destroyed!" << std::endl;
	}

	void printSomething() {
		std::cout << "It is printing something\n";
	}

	void setValue(std::weak_ptr<Entity> entity) {
		
	}
};


int main()
{
	{
		std::weak_ptr<Entity> e1;
		{
			std::weak_ptr<Entity> entity = std::make_shared<Entity>();
			e1 = entity;
		}
	}


	std::cin.get();
}