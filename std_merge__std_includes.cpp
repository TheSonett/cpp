#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
    std::vector<int> v1 = { 1, 3, 4, 5, 20, 30 };
    std::vector<int> v2 = { 1, 5, 6, 7, 25, 30 };

    std::vector<int> v3(12);

    std::merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());

  
    std::cout << "The new container after merging is :\n";
    for (int& x : v3)
        std::cout << x << " ";
    std::cout << std::endl;

    std::vector<int> v4 = { 1, 3, 4, 5, 6, 20, 25, 30 };

    // Using include() to check if v4 contains v1
    std::includes(v4.begin(), v4.end(), v1.begin(), v1.end()) ?
        std::cout << "v4 includes v1" :
        std::cout << "v4 does'nt include v1";

    return 0;
}