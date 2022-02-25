#include <iostream>

typedef void(*SahaFunction)(); // making a void type function pointer called SahaFunction

void Fun()
{
    std::cout << "Fun function" << std::endl;
}

static SahaFunction function() // It is function pointer type function which return a pointer of Fun() function
{
    return Fun;
}

int main()
{
    function()();

    std::cin.get();
}