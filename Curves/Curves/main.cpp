#include <iostream>
#include <math.h>
#include <vector>

const double PI = 3.141592653589793;


struct Point
{
	double x;
	double y;
	double z;
};

class Circle
{
private:

	double radius;

	double getX(double t)
	{
		return radius * cos(t);
	}

	double getY(double t)
	{
		return radius * sin(t);
	}

public:

	Circle(double radius)
	{
		if (radius <= 0)
		{
			throw "Radius cannot be negative or zero";
		}
		else
		{
			this->radius = radius;
		}
	}

	// Возвращаем точку.
	virtual Point& getPoint(double t)
	{
		return *(new Point{ getX(t), getY(t), 0 });
	}

	virtual double getRadius()
	{
		return radius;
	}

	virtual double getFirstDerivative(double t)
	{
		return cos(t) / sin(t);
	}
};

class Ellipse: public Circle
{
private:

	double radius2;

	double getX(double t)
	{
		return Circle::getRadius() * cos(t);
	}

	double getY(double t)
	{
		return radius2 * sin(t);
	}

public:

	Ellipse(double radius1, double radius2) : Circle{ radius1 }
	{
		if (radius2 <= 0)
		{
			throw "Radius cannot be negative or zero";
		}
		else
		{
			this->radius2 = radius2;
		}
	}

	// Возвращаем точку.
	virtual Point& getPoint(double t)
	{
		return *(new Point{ getX(t), getY(t), 0 });
	}

	virtual double getFirstDerivative(double t)
	{
		return  (-radius2 / Circle::getRadius()) * (cos(t) / sin(t));
	}
};

class Helix: public Circle
{
private:

	double step;

	double getX(double t)
	{
		return Circle::getRadius() * cos(t);
	}

	double getY(double t)
	{
		return Circle::getRadius() * sin(t);
	}

	double getZ(double t)
	{
		return t / (2 * PI) * step;
	}

public:

	Helix(double radius, double step) : Circle{ radius }
	{
		if (step < 0)
		{
			throw "Step cannot be negative";
		}
		else
		{
			this->step = step;
		}
	}

	// Возвращаем точку.
	virtual Point& getPoint(double t)
	{
		return *(new Point{ getX(t), getY(t), getZ(t) });
	}

	virtual double getFirstDerivative(double t)
	{

	}
};

int main()
{
	setlocale(0, "");

	return 0;
}