#include <iostream>

static class Test {
private:
	static int num1;
	static int num2;
	static int sum;
public:
	Test() {

	}

	static int calculateSum(int a, int b) {
		//It will not work inside static method
		/*this->num1 = num1;
		this->num2 = num2;*/

		num1 = a;
		num2 = b;

		sum = a + b;

		return sum;
	}
};

int Test::num1 = 0;
int Test::num2 = 0;
int Test::sum = 0;

int main()
{
	//std::cout << Test::calculateSum(2, 3);
	Test::Test();
	std::cout << Test::calculateSum(2, 3);
	std::cin.get();
}