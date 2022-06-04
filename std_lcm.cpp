// 8.	WAP to find out LCM of two numbers

#include <iostream>
#include <numeric>

int main()
{
    int a, b;
    std::cout << "Enter first number: " << "\n";
    std::cin >> a;

    std::cout << "Enter second number: " << "\n";
    std::cin >> b;

    std::cout << "The LCM of " << a << " and " << b << " is: " << std::lcm(a, b) << std::endl;
    return 0;
}