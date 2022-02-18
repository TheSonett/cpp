/* Constructor Delegation:
* 
*   Sometimes it is useful for a constructor to be able to call another constructor of the same class. 
	This feature, called Constructor Delegation, was introduced in C++ 11.
*	
*	
*/


#include <iostream>
#include <cassert>

class Point2D 
{
public:
	constexpr static int val = 0;

	void SetX(int x);
	void SetY(int y);

	Point2D();
	Point2D(int x, int y);

	Point2D(const Point2D& other) {
		mX = 22;//other.mX;
		mY = 44;//other.mY;
	}

	~Point2D() { std::cout << "Object Destroyed!" << std::endl; }

	int GetX();
	int GetY();

	void Display();

	static void msgPrint() { std::cout << val << std::endl; }

	Point2D& GetRef();
	Point2D* GetPointer();

private:
	int mX;
	int mY;
};


class Point3D
{
public:
	Point3D() : p(0, 0) {}
	Point3D(int val) { p.SetX(val); }

	int Get3DX() { return p.GetX(); }

private:
	Point2D p;
};

// Comstructor Delegation
Point2D::Point2D() : Point2D(0, 0) { std::cout << "Constructor Created!" << std::endl; }

Point2D::Point2D(int x, int y) : mX(x), mY(y) { }


void Point2D::SetX(int x) {
	mX = x;
}

void Point2D::SetY(int y) {
	mY = y;
}

int Point2D::GetX() {
	return mX;
}

int Point2D::GetY() {
	return mY;
}

void Point2D::Display() {
	std::cout << "X: " << mX << ", Y: " << mY << std::endl;
}

// this keyword
Point2D& Point2D::GetRef() {
	return *this;
}

Point2D* Point2D::GetPointer() {
	return this;
}

void Func(Point2D p) {
	p.Display();
}

std::ostream& operator<<(std::ostream& stream, Point2D& object) {
	stream << object.GetX() << " , " << object.GetY();
	return stream;
}

int main()
{
	/*Point2D myPoint(2, 3);

	std::cout << "Size of my point: " << sizeof(myPoint) << std::endl;
	std::cout << "X: " << myPoint.GetX() << " , Y: " << myPoint.GetY() << std::endl;

	printf("\n\n");

	Point2D* myPointer = myPoint.GetPointer();
	Point2D& myRef = myPoint.GetRef();

	myPointer->Display();
	myRef.Display();

	std::cout << &myPoint << " :: " << &myPointer << " :: " << &myRef << std::endl;


	printf("\n");


	Point3D my3dPoint;
	std::cout << my3dPoint.Get3DX() << std::endl;*/


	/*Point2D pp[5];

	pp[0].SetX(2);
	pp[0].SetY(4);

	pp[1].SetX(10);
	pp[1].SetY(20);

	std::cout << "X: " << pp[0].GetX() << " , Y: " << pp[0].GetY() << std::endl;
	std::cout << "X: " << pp[1].GetX() << " , Y: " << pp[1].GetY() << std::endl;*/
	

	Point2D p;
	//std::cout << p << std::endl;
	//std::cout << Point2D::val << std::endl;
	//p.Display();
	//Func(p);

	std::cout << "End of Program" << std::endl;
	std::cin.get();
} 