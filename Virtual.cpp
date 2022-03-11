#include <iostream>

class AbstractClass
{
public:
	AbstractClass() : m_Val(0) {}
	AbstractClass(int val) { m_Val = val; }

	virtual void print() = 0;
	void setVal(int val) { m_Val = val; }
	int getVal() { return m_Val; }
protected:
	int m_Val;
};

class AbstractClass2 : public AbstractClass
{
public:
	virtual void print2() = 0;
};


class NonAbstractClass : public AbstractClass2
{
public:
	void print() override { std::cout << "Printing something!!" << std::endl; }
	void print2() override { std::cout << "Printing  2 something!!" << std::endl; std::cout << m_Val << std::endl; }
};

int main()
{
	NonAbstractClass n;
	n.print();
	n.print2();

	n.setVal(2);
	int i = n.getVal();
	std::cout << i << std::endl;

	std::cin.get();
}