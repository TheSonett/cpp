// [1] -> explicit keywork prohibits implicit comversion functionality. So, you cannot write like Y y = "Joy". You have to write Y y = Y("Joy")
// [2] -> temporary objects("bar") cannot be bound to non-const references like void bax(Y& y). Use R-value references or make y ref, a const ref.

#include <iostream>

struct Y {
	Y() {
		std::cout << "empty constructor Y\n";
	}

	Y(const char* txt) {
		std::cout << "init constructor\n";
	}
};


//void baz(Y&& y) {}
void baz(const Y& y) {}

int main()
{
	baz("Joy"); // temporary objects("bar") cannot be bound to non-const references. Use R-value references or make x ref, a const ref.
	std::cin.get();
}