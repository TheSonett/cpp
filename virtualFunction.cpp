/*
* Virtual Function
* 1. We cannot use override(C++ 11) keyword if we don't use virtual keyword.
* 2. They are mainly used to achieve Runtime polymorphism.
* 3. It cannot be static.
* 4. A class may have virtual destructor but it cannot have a virtual constructor.
* 5. Virtual functions ensure that the correct function is called for an object, regardless of the type of reference (or pointer) used for function call.
* 6. Early Binding (compile time) & late Binding (runtime)
*/


#include <iostream>

class Entity {
public:
	Entity() { }

	virtual std::string GetName() {
		return "Entity";
	}
};

class Student : public Entity {
private:
	std::string name;
public:
	Student(const std::string& name) {
		this->name = name;
	}

	std::string GetName() override {
		return name;
	}
};

void PrintName(Entity* entity) {  // For student pointer, entity type pointer is pointing to student pointer. By default, it will give the priority to the pointer type
	std::cout << entity->GetName() << std::endl;
}

int main()
{
	Entity* entity = new Entity(); // Entity type pointer
	Student *student = new Student("Joy Saha"); // student type pointer

	PrintName(entity);
	PrintName(student);
}