#include "Shape.h"

#define _USE_MATH_DEFINES
#include <math.h>

#include <algorithm>

Shape::Shape()
{
}


Shape::~Shape()
{
}


Circle::Circle(int r, int colorId) : Shape()
{
	for (int i = 0; i < 360; ++i)
	{
		int x = (int)round(cos(i * M_PI / 180) * r);
		int y = (int)round(sin(i * M_PI / 180) * r);

		if (std::find(points.begin(), points.end(), Point(x, y)) == points.end())
		{
			points.push_back(ColorPoint(x, y, colorId));
		}
	}
}

Cross::Cross(int r, int colorId) : Shape()
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