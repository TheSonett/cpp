#include <iostream>
#include <numeric> // std::iota, std::accumulate, std::reduce, std::inner_product, std::partial_sum

int myfun(int x, int y)
{
    return x * y;
}

int main()
{
    int sum = 1;
    int a[] = { 10, 10, 10 };

    std::cout << "Result using accumulate: ";
    std::cout << std::accumulate(a, a + 3, sum); // sum = 10 + 10 + 10 + 1 = 31

    std::cout << "\nResult using accumulate with user-defined function: ";
    std::cout << std::accumulate(a, a + 3, sum, myfun); // 10 * 10 * 10 * 1 = 1000

    std::cout << "\nResult using accumulate with pre-defined function: ";
  
    std::cout << std::accumulate(a, a + 3, sum, std::minus<int>()); // - 10 - 10 - 10 - (1 + 1) = -29

    printf("\n\n");

    return 0;
}