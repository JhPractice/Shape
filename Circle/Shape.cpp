#include "Shape.h"

#define _USE_MATH_DEFINES
#include <math.h>

#include <algorithm>

Shape::Shape() : _rotationAngle(0.f), _tranlationPoint(0, 0)
{
}


Shape::~Shape()
{
}

void Shape::Initialize(int r, int colorId)
{

}

void Shape::Rotate(float angle)
{
	if (abs(_rotationAngle) >= 360.f)
		_rotationAngle = 0.f;
	_rotationAngle += angle;
}

void Shape::Translate(Point point)
{
	_tranlationPoint = _tranlationPoint + point;
}

void Shape::ApplyMatrix()
{
	appliedPoints.clear();
	for (unsigned int i = 0; i < points.size(); i++)
	{
		appliedPoints.push_back(points[i].Rotate(_rotationAngle) + _tranlationPoint);
	}
}


Circle::Circle(int r, int colorId) : Shape()
{

}

void Circle::Initialize(int r, int colorId)
{
	for (int i = 0; i < 360; ++i)
	{
		int x = (int)round(cos(i * M_PI / 180.f) * r);
		int y = (int)round(sin(i * M_PI / 180.f) * r);

		if (std::find(points.begin(), points.end(), Point(x, y)) == points.end())
		{
			points.push_back(ColorPoint(x, y, colorId));
		}
	}
}

Cross::Cross(int r, int colorId) : Shape()
{

}

void Cross::Initialize(int r, int colorId)
{
	points.push_back(ColorPoint(0, 0, colorId));

	for (int i = 1; i < r; i++)
	{
		points.push_back(ColorPoint(0, i, colorId));
		points.push_back(ColorPoint(0, -i, colorId));
		points.push_back(ColorPoint(i, 0, colorId));
		points.push_back(ColorPoint(-i, 0, colorId));
	}
}
