#include <iostream>

using namespace std;

int func() {
    return 5;
}

int func2() {
    return 2;
}

int main()
{
    int k;
    const char* array[] = { "Red", "Blue", "Green", "Yellow" };
    const char* (*p)[4] = &array;

    cout << ++(*p)[2] << std::endl;

    // b is an array of pointer to function
    int (*b [5])() = {func, func2};
    std::cout << (*b [1])();

    return 0;
}