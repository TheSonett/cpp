#include <iostream>

struct Student
{
	int age;
	std::string name;

	void SetNameAge(const int& age, const std::string& name) {
		this->age = age;
		this->name = name;
	}

	void ShowDetails() {
		std::cout << name << " , " << age << std::endl;
	}
};


int main()
{
	static Student student1, student2;

	std::cout << "Student1 Details ::::" << std::endl;
	student1.SetNameAge(23, "Joy Saha");
	student1.ShowDetails();

	printf("\n\n");

	std::cout << "Student1 Details ::::" << std::endl;
	student2.SetNameAge(18, "Apurba");
	student2.ShowDetails();

	std::cin.get();
}