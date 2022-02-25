//decltype is a way to specify a type : You give it an expression, and decltype gives you back a type which corresponds to the type of the expression.Specifically, decltype(e) is the following type :
//
//If e is the name of a variable, i.e.an "id-expression", then the resulting type is the type of the variable.
//
//Otherwise, if e evaluates to an lvalue of type T, then the resulting type is T&, and if e evaluates to an rvalue of type T, then the resulting type is T.
//
//Combining these rules with reference collapsing rules allows you to make sense of decltype(e)&&, which is always a "suitable" reference. (C++14 also adds decltype(auto) to give you the type - deduction of auto combined with the value category semantics of decltype.)
//
//Examples:
//
//int foo();
//int n = 10;
//
//decltype(n) a = 20;             // a is an "int" [id-expression]
//
//decltype((n)) b = a;            // b is an "int &" [(n) is an lvalue]
//
//decltype(foo()) c = foo();      // c is an "int" [rvalue]
//
//decltype(foo()) && r1 = foo();  // int &&
//decltype((n)) && r2 = n;        // int & [& && collapses to &]
//It might be worth stressing the difference between autoand decltype: auto works on types, and decltype works on expressions.
//
//You shouldn't be seeing or using decltype in "day-to-day" programming. It is most useful in generic (templated) library code, where the expression in question is not known and depends on a paramater.
//
//
//int foo();
//int n = 10;
//
//decltype(n) a = 20;             // a is an "int" [id-expression]
//
//decltype((n)) b = a;            // b is an "int &" [(n) is an lvalue]
//
//decltype(foo()) c = foo();      // c is an "int" [rvalue]
//
//decltype(foo()) && r1 = foo();  // int &&
//decltype((n)) && r2 = n;        // int & [& && collapses to &]



#include <iostream>

int add() { return 3 + 4; }
int multi() { return 3 * 4; }

int main()
{
	add();
	const char* n = "Saha";
	//decltype(n) a = 20;
	decltype(n) str = "Joy";
	decltype(add()) c = multi();

	std::cout << n << std::endl;
	std::cout << str << std::endl;
	std::cout << c << std::endl;
	std::cin.get();
}