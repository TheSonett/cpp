/*
* 5. partition_copy(beg, end, beg1, beg2, condition) :- This function copies the partitioned elements in the different containers mentioned in its arguments. 
    It takes 5 arguments. Beginning and ending position of container, beginning position of new container where elements
    have to be copied (elements returning true for condition), beginning position of new container where other elements have to be copied 
    (elements returning false for condition) and the condition. Resizing new containers is necessary for this function.
* 
*/


#include <iostream>
#include <algorithm>
#include <vector>


int main()
{
    std::vector<int> vect = { 2, 1, 5, 6, 8, 7 };
    std::vector<int> vect1;
    std::vector<int> vect2;


    // Resizing vectors to suitable size using count_if() and resize()
    int n = std::count_if(vect.begin(), vect.end(), [](int x) {
            return x % 2 == 0;
    });

    vect1.resize(n);
    vect2.resize(vect.size() - n);

    // Using partition_copy() to copy partitions
    std::partition_copy(vect.begin(), vect.end(), vect1.begin(), vect2.begin(), [](int x) {
           return x % 2 == 0;
    });


    std::cout << "The elements that return true for condition are : ";
    for (int& x : vect1)
        std::cout << x << " ";
    std::cout << std::endl;


    std::cout << "The elements that return false for condition are : ";
    for (int& x : vect2)
        std::cout << x << " ";
    std::cout << std::endl;

    return 0;
}