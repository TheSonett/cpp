#include <iostream>
#include <random>

int main()
{
    // Here default_random_engine object is used as source of randomness
    // We can give seed also to default_random_engine if psuedorandom numbers are required
  
	std::default_random_engine randomNumberGenerator;
    std::mt19937 randomNumberGenerator;
    //std::random_device randomNumberGenerator;

    // Give a seed value or starting value
    randomNumberGenerator.seed(std::random_device{}());


    // giving the range of random number
    int a = 0, b = 10;
    std::uniform_int_distribution<int> distribution(a, b);
    std::uniform_real_distribution<double> disDouble(a, b);

    // give random values to operator()
    for (int i = 1; i <= 20; i++) {
        int number = distribution(randomNumberGenerator);
        std::cout << "Random Number: " << number;
        std::cout << std::endl;
    }
    std::cout << std::endl;

    std::cout << "Lower bound: " << disDouble.a();
    std::cout << "\nUpper bound: " << disDouble.b();
    std::cin.get();
}