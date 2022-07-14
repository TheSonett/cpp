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

	void setValue(std::shared_ptr<Entity> entity) {
		entity->age = 24;
		std::cout << entity->age << std::endl;
	}
};


int main()
{
	{
		std::shared_ptr<Entity> e1;
		{
			std::shared_ptr<Entity> entity = std::make_shared<Entity>();
			entity->setValue(entity);

			e1 = entity;
		}
	}


	std::cin.get();
}