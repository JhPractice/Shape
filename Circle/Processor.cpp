#include "Processor.h"
#include <Windows.h>

#define _USE_MATH_DEFINES
#include <math.h>

Processor* Processor::instance = NULL;

Processor::Processor()
{
	Initialize();
}


Processor::~Processor()
{
}

void Processor::Initialize()
{
	Point center(10, 9);
	InitCirclePoint(innerCircle, center, 5);
	InitCirclePoint(outerCircle, center, 8);
	InitCrossPoint(cross, center, 5);
}

bool Processor::Process()
{
	if (GetAsyncKeyState(VK_ESCAPE))
		return false;
	return true;
}

void Processor::InitCirclePoint(std::vector<Point>& v, Point center, int r)
{
	for (int i = 0; i < 360; ++i)
	{
		int x = (int)round(cos(i * M_PI / 180) * r + center.x);
		int y = (int)round(sin(i * M_PI / 180) * r + center.y);


		if (!(x < 0 || y < 0 || x > kCullum || y > kRow))
		{
			bool isExist = false;
			for (unsigned int j = 0; j < v.size(); ++j)
			{
				if (v[j].x == x && v[j].y == y)
					isExist = true;
			}
			if (!isExist)
				v.push_back(Point(x, y));
		}
	}
}

void Processor::InitCrossPoint(std::vector<Point>& v, Point center, int r)
{
	v.push_back(center);

	for (int i = 1; i < r; i++)
	{
		v.push_back(Point(center.x, center.y + i));
		v.push_back(Point(center.x, center.y - i));
		v.push_back(Point(center.x + i, center.y));
		v.push_back(Point(center.x - i, center.y));
	}
}

bool Processor::IsInnerCircle(Point p)
{
	for (unsigned int j = 0; j < innerCircle.size(); ++j)
	{
		if (innerCircle[j].x == p.x && innerCircle[j].y == p.y)
			return true;
	}
	return false;
}

bool Processor::IsOuterCircle(Point p)
{
	for (unsigned int j = 0; j < outerCircle.size(); ++j)
	{
		if (outerCircle[j].x == p.x && outerCircle[j].y == p.y)
			return true;
	}
	return false;
}

bool Processor::IsCross(Point p)
{
	for (unsigned int j = 0; j < cross.size(); ++j)
	{
		if (cross[j].x == p.x && cross[j].y == p.y)
			return true;
	}
	return false;
}