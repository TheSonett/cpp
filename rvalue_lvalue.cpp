/* L - value: “l - value” refers to memory location which identifies an object.l -
   value may appear as either left hand or right hand side of an assignment operator( = ).
   l - value often represents as identifier. 
*/

/*
* && is new in C++11. int&& a means "a" is an r-value reference. 
  && is normally only used to declare a parameter of a function. 
  And it only takes a r-value expression. 
  If you don't know what an r-value is, the simple explanation is that it doesn't have a 
  memory address. E.g. the number 6, and character 'v' are both r-values. 
  int a, a is an l-value, however (a+2) is an r-value.
*/

/*
* r-value” refers to data value that is stored at some address in memory. 
  A r-value is an expression that can’t have a value assigned to it which means r-value can 
  appear on right but not on left hand side of an assignment operator(=).
*/

#include <iostream>

int val(int&& x) {
	return x;
}

int val(int& x) {
	return x;
}

int main()
{
	int b = 8;
	int res = val(7); // r-value doesn't have any memory address like 7
	int res2 = val(b); // l-value
	std::cout << res << std::endl;
	std::cout << res2 << std::endl;
	std::cin.get();
}