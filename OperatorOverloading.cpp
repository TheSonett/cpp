#include <iostream>

class Entity {
private:
	int a, b;
public:
	Entity() {
		std::cout << "Object Created!\n";
	}

	Entity(int a, int b) {
		this->a = a;
		this->b = b;
	}

	~Entity() {
		std::cout << "Object Destroyed!\n";
	}

	friend std::ostream& operator<<(std::ostream& stream, const Entity* en);

	Entity operator()(int x, int y, Entity& en2) {
		en2.a = x;
		en2.b = y;

		return en2;
	}
};

// output stream
std::ostream& operator<<(std::ostream& stream, const Entity* en) {
	stream << en->a << " , " << en->b << std::endl;
	return stream;
}

int main()
{
	Entity *en = new Entity(2, 3);
	std::cout << en << std::endl;
	
	/*Entity en2;
	en2(7, 8, en2);
	std::cout << en2 << std::endl;*/

	std::cin.get();
}