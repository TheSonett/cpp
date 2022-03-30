/* It provides a hint to the Optimizer that the labeled statement is likely / unlikely to have its body executed.
Both attributes allow giving the Optimizer a hint, whether the path of execution is more or less likely.*/


#include <iostream>

int main() 
{
    int n = 40;
    [[likely]] if (n < 100) { 
        std::cout << n * 2 << " ";
    }

    [[unlikely]] while (n > 100) {
        n = n / 2;
        std::cout << n << " ";
    }

    std::cout << std::endl;
    std::cout << "---------------------------" << std::endl;

    n = 500;
    [[likely]] if (n < 100) { 
        std::cout << n * 2; 
    }

    [[unlikely]] while (n > 100) {
        n = n / 2;
        std::cout << n << " ";
    }
    
    std::cin.get();
}