/* Pure Virtual Function
* 1. All pure virtual functions must be implemented in each subclass.
* 2. We cannot create an object of a class which contains a pure virtual function.
* 3. Pure virtual function  or inteface allows us to define a function in a base class that doesn't have an implementation or definition in the base class and 
	 force sub classes to implement that function. Pure virtual function is also called an interface in other languages.
  4. The pure virtual function must have virtual written at the beginning and =0 at the end. 
  5. It cannot contain any definition in base class,it is just a declaration.
  6. A class can have more than one pure virtual functions.
  7. We cannot create objects but we can create pointer of the pure vitual function class.
*/
#include <iostream>

class Entity {
public:
	Entity() { }

	void show() {
		std::cout << "Pure Virtual Function" << std::endl;
	}

	virtual std::string GetName() = 0;
	virtual int GetAge() = 0;
};

class Student : public Entity {
private:
	std::string name;
public:
	Student() = default;
	Student(const std::string& name) {
		this->name = name;
	}

	std::string GetName() override {
		return name;
	}

	int GetAge() override {
		return 23;
	}
};

class Employee : public Student {
private:
	std::string name;
public:
	Employee(const std::string& name) {
		this->name = name;
	}

	std::string GetName() override {
		return name;
	}

	int GetAge() override {
		return 77;
	}
};

void PrintName(Entity* entity) {
	std::cout << entity->GetName() << std::endl;
	std::cout << entity->GetAge() << std::endl;
}

int main()
{
	Student* student = new Student("Joy Saha"); // student type pointer
	Employee* emp = new Employee("Sir");
	Entity* en = nullptr;
	en->show();

	PrintName(student);
	PrintName(emp);
}
