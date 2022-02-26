#include <iostream>

class Entity
{
public:
	Entity(const std::string& name) 
		: m_Name(name), m_Age(0) 
	{
		std::cout << "Name: " << m_Name << ", Age: " << m_Age << std::endl;
	}

	explicit Entity(const int& age)
		: m_Name("None"), m_Age(age)
	{
		std::cout << "Name: " << m_Name << ", Age: " << m_Age << std::endl;
	}

private:
	std::string m_Name;
	int m_Age;
};


int main()
{
	Entity name = Entity("Joy Saha"); // explicit
	Entity age = Entity(23); // explicit

	Entity name1("Joy Saha"); // explicit
	Entity age2(23); // explicit


	//Entity age = 23; // implicit (without explicit keyword possible)


	std::cin.get();
}
