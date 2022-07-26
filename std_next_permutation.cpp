#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>

int main()
{
    std::string binary = "0001";
    do {
        std::cout << binary << "\n";
    } while (std::next_permutation(binary.begin(), binary.end()));

    return 0;
}