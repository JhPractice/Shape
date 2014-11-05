#pragma once

#ifndef _COMMON_
#define _COMMON_

#define _USE_MATH_DEFINES
#include <math.h>

const int kRow = 20;
const int kCullum = 30;

#ifndef _POINT_
#define _POINT_

typedef struct _Point
{
	int x, y;
	_Point() : x(0), y(0) {}
	_Point(int _x, int _y) : x(_x), y(_y) {}

	bool operator == (const _Point &p) const
	{
		return x == p.x && y == p.y;
	}

	_Point operator + (const _Point &p) const
	{
		return _Point(x + p.x, y + p.y);
	}

	_Point Rotate(float angle) const
	{
		return Point((int)round(x * cos(angle * M_PI / 180) + y * sin(angle * M_PI / 180)),
			(int)round(x * -sin(angle * M_PI / 180) + y * cos(angle * M_PI / 180)));
	}

} Point;

typedef struct _ColorPoint
{
	int colorId;
	Point point;
	_ColorPoint(Point _point, int _colorId) : point(_point), colorId(_colorId) {}
	_ColorPoint(int _x, int _y, int _colorId) : colorId(_colorId), point(Point(_x, _y)) {}

	bool operator == (const _Point &p) const
	{
		return point == p;
	}

	bool operator == (const _ColorPoint &p) const
	{
		return point == p.point && colorId == p.colorId;
	}

	_ColorPoint operator + (const _Point &p) const
	{
		return _ColorPoint(point + p, colorId);
	}

	_ColorPoint Rotate(float angle) const
	{
		return _ColorPoint(point.Rotate(angle), colorId);
	}

} ColorPoint;

#endif


#endif