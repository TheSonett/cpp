#include <iostream>
#include <string>

struct vector2
{
	int x, y;
};

struct vector4
{
	union
	{
		struct 
		{
			int x, y, z, w;
		}; // 16 bytes

		struct
		{
			vector2 a, b; // a -> x, y | b -> z, w 
		}; // 16 bytes
	};
};

void PrintVector2(const vector2& vec) {
	std::cout << vec.x << " , " << vec.y << std::endl;
}

int main()
{
	vector4 vector;
	vector.x = 2;
	vector.y = 3;
	vector.z = 4;
	vector.w = 5;

	PrintVector2(vector.a);
	PrintVector2(vector.b);
	vector.z = 200;
	std::cout << "---------------------" << std::endl;
	PrintVector2(vector.a);
	PrintVector2(vector.b);

	std::cin.get();
}