#include <iostream>
#include <chrono>
#include <type_traits>
#include <format>


int main()
{
    std::cout << "The current time is ";
    auto start_time = std::format("{:%F %T}", std::chrono::system_clock::now());
    std::cout << start_time << "\n";

    std::cin.get();
}