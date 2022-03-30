#include <iostream>
#include <array> // for std::to_array in C++ 20
#include <algorithm>

using namespace std;

// Driver Code
int main()
{
    std::array<char, 4> val = std::to_array("Joy"); // 'J', 'o', 'y', '\0'
    std::array<int, 3> arr = std::to_array<int>({ 1, 2, 3 });
    arr.fill(1);

    std::for_each(val.begin(), val.end(), [](char& x) {
        if (x != '\0') {
            std::cout << x << " ";
        }
     });

    std::cin.get();
}