#include <iostream>

class Vehicle
{
public:
	Vehicle() : Vehicle(0, "") {} // delegatioon constructor
	Vehicle(int id, std::string name) {
		m_ID = id;
		m_Name = name;
	}
	~Vehicle() {}
public:
	virtual void PrintDetails() {
		std::cout << "Vehicle: " << m_ID << " , " << m_Name << std::endl;
	}

private:
	int m_ID;
	std::string m_Name;
};

class Tata : public Vehicle
{
public:
	Tata(int id, std::string name, std::string color) : Vehicle(id, name) {
		m_Color = color;
	}
	void PrintDetails() override {
		std::cout << "Tata: " << m_ID << " , " << m_Name << " , " << m_Color << std::endl;
	}
	~Tata() {}

private:
	int m_ID;
	std::string m_Name;
	std::string m_Color;
};


int main()
{
	Tata tata(1, "Tata", "Black");
	tata.PrintDetails();

	Vehicle vehi(0, "Vehile");
	vehi.PrintDetails();

	tata.PrintDetails();

	std::cin.get();
}