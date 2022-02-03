/* Types of Threads in C++11.
* 
* There are 5 different types we can create thread in C++11 using callable objects.
* 
* NOTE:
* If we create multiple thread at the same time it doen't guarantee which one will start first.
* 
*/

#include <iostream>
#include <thread>

// 1. Function Pointer. This is the very basic from of thread creation.
//void fun(int x)
//{
//	while (x --> 0) // while( (x--) > 0 ) here, first decreament will happen (x--) & then comparison if it is greater than 0.
//	{
//		std::cout << x << " ";
//	}
//}
//
//int main()
//{
//	std::thread t1(fun, 11);
//
//	t1.join();
//	std::cin.get();
//}



// 2. Lambda Expressions
//int main()
//{
//	auto fun = [](int x) {
//		while (x --> 0) {
//			std::cout << x << " ";
//		}
//	};
//
//	std::thread t(fun, 11);
//
//	std::thread t2([](int x) {
//		while (x-- > 0) {
//			std::cout << x << " ";
//		}
//	}, 11);
//
//	t.join();
//	t2.join();
//	std::cin.get();
//}



// 3. Functor (Function Object)
//class Joy {
//public:
//	void operator()(int x) {
//		while (x-- > 0) {
//			std::cout << x << " ";
//		}
//	}
//};
//
//int main() {
//	std::thread t(Joy(), 11);
//
//	t.join();
//	std::cin.get();
//}



// 4. Non-static member function
//class Joy {
//public:
//	void run(int x) {
//		while (x-- > 0) {
//			std::cout << x << " ";
//		}
//	}
//};
//
//int main()
//{
//	Joy j;
//	std::thread t(&Joy::run, &j, 11); // we need the reference of that function + the obj as it is non-static.
//	t.join();
//	std::cin.get();
//}



// 5. Static member function
class Joy {
public:
	static void run(int x) {
		while (x-- > 0) {
			std::cout << x << " ";
		}
	}
};

int main()
{
	std::thread t(&Joy::run, 11); // we don't the obj + reference because of static
	t.join();
	std::cin.get();
}