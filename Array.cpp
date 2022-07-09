#include <iostream>
#include <vector>
#include <set>

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
    std::cout << (*b [1])() << std::endl;

    std::vector<int> nums = { 1, 2, 3, 3, 4, 5, 1, 1, 2, 8, 9, 5 };
    std::set<int> s(nums.begin(), nums.end());
    nums.assign(s.begin(), s.end());

    for (auto i : nums) {
        std::cout << i << " ";
    }

    return 0;
}