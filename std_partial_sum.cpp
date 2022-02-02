#include <iostream>
#include <numeric> // std::iota, std::accumulate, std::reduce, std::inner_product, std::partial_sum

int myfun(int x, int y)
{
    return x + 2 * y;
}

int main()
{
    int a[] = { 1, 2, 3, 4, 5 };
    int b[5];

    std::partial_sum(a, a + 5, b);

    std::cout << "Partial Sum - Using Default function: ";
    for (int i = 0; i < 5; i++)
        std::cout << b[i] << ' ';
    std::cout << '\n';

    // Using user defined function
    std::partial_sum(a, a + 5, b, myfun);

    std::cout << "Partial sum - Using user defined function: ";
    for (int i = 0; i < 5; i++)
        std::cout << b[i] << ' ';
    std::cout << '\n';

    return 0;
}


/* Note:
* first, last: first and last element of range whose elements are to be added
  b: index of array where  corresponding partial sum will be stored
  myfun: a user-defined function for performing any specific task
*
* 
* Partial sum pattern =>
* y0 = x0 
  y1 = x0 + x1 
  y2 = x0 + x1 + x2 
  y3 = x0 + x1 + x2 + x3 
  y4 = x0 + x1 + x2 + x3 + x4
*/