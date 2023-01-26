#include <iostream>

struct Point
{
	double x, y, z;
};

class Circle
{
	double radius;
public:

	Circle(double radius) : radius{ radius } {};

	Point& getPoint(double t)
	{

	}
};

class Ellipse
{
	double radius1;
	double radius2;
public:

	Ellipse(double radius1, double radius2) : radius1{ radius1 }, radius2{ radius2 }{};

	Point& getPoint(double t)
	{

	}
};

class Helix
{
	double radius;
	double step;
public:

	Helix(double radius, double step) : radius{ radius }, step{ step }{};

	Point& getPoint(double t)
	{

	}
};

int main()
{
	setlocale(0, "");

	return 0;
}