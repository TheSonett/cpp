// Multiple Returns in C++

// using struct
// using std::array & std::vector
// using std::string
// using std::tuple
// using std::pair

#include <iostream>

struct Entity {
	int dx, dy;

	int x = 10;
	int y = 20;
};

static Entity GetValue() {
	Entity e;
	return { e.x, e.y };
}

static std::string* GetName() {
	std::string first = "Joy";
	std::string last = "Saha";
	return new std::string[]{ first, last }; // We're creating a whole new string array & returning it's pointer because new keyword return a pointer to the first value.
}


// Operator Overloading
std::ostream& operator<<(std::ostream& stream, const Entity& other) {
	stream << other.x << "," << other.y << std::endl;
	return stream;
}

std::istream& operator>>(std::istream& stream, Entity& other) {
	std::cout << "Enter dx value: ";
	stream >> other.dx;

	std::cout << "Enter dy value: ";
	stream >> other.dy;
	return stream;
}

int main()
{
	std::cout << GetValue() << "\n"; // Think of like -> std::ostream << Entity GetValue();

	Entity e;
	std::cin >> e; // Think of like -> std::istream >> Entity e
	std::cout << e.dx << "," << e.dy << std::endl;


	std::string* str = GetName();
	std::cout << *str << " " << *(str+1);


	std::cin.get();
}