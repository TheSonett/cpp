#include <iostream>
#include <random>

// REMEMBER: 
// 1. A static method can have only static members.
// 2. We have to initialize static members outside a class or use constexprt/const to initialize inside a class

class Random
{
public:
	static void Init() {
		m_RandomGenerator.seed(std::random_device{}());
	}

	static float RandomFloatNumber() { // generator between 0 & 1;
		return ((float)m_Distribution(m_RandomGenerator) / (float)std::numeric_limits<uint32_t>::max());
	}

private:
	static std::mt19937 m_RandomGenerator;
	static std::uniform_int_distribution<std::mt19937::result_type> m_Distribution;
};

// Initialization of static members of Random class
std::mt19937 Random::m_RandomGenerator;
std::uniform_int_distribution<std::mt19937::result_type> Random::m_Distribution;


int main() 
{
	Random random;
	random.Init();
	std::cout << "Random Number: " << random.RandomFloatNumber();

	std::cin.get();
}