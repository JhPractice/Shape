#include "Shape.h"

#define _USE_MATH_DEFINES
#include <math.h>

#include <algorithm>


void Rotate(Shape* outModel, Shape* inModel, float angle)
{
	std::vector<ColorPoint>& original = inModel->_points;
	int outModelSize = outModel->_points.size();
	int originalModelSize = original.size();
	for (int i = 0; i < originalModelSize; i++)
	{
		outModel->_points.push_back(original[i].Rotate(angle));
	}
	for (int i = 0; i < outModelSize; ++i)
	{
		outModel->_points.erase(outModel->_points.begin());
	}
}

void Translate(Shape* outModel, Shape* inModel, Point distance)
{
	std::vector<ColorPoint>& original = inModel->_points;
	int outModelSize = outModel->_points.size();
	int originalModelSize = original.size();
	for (int i = 0; i < originalModelSize; i++)
	{
		outModel->_points.push_back(original[i] + distance);
	}
	for (int i = 0; i < outModelSize; ++i)
	{
		outModel->_points.erase(outModel->_points.begin());
	}

}

Shape::Shape()
{
}

Shape::~Shape()
{
}

void Shape::Initialize(int r, int colorId)
{

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

		if (std::find(_points.begin(), _points.end(), Point(x, y)) == _points.end())
		{
			_points.push_back(ColorPoint(x, y, colorId));
		}
	}
}

Cross::Cross(int r, int colorId) : Shape()
{

}

void Cross::Initialize(int r, int colorId)
{
	_points.push_back(ColorPoint(0, 0, colorId));

	for (int i = 1; i < r; i++)
	{
		_points.push_back(ColorPoint(0, i, colorId));
		_points.push_back(ColorPoint(0, -i, colorId));
		_points.push_back(ColorPoint(i, 0, colorId));
		_points.push_back(ColorPoint(-i, 0, colorId));
	}
}
