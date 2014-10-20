#pragma once

#ifndef _SHAPE_
#define _SHAPE_

#include "Common.h"
#include <vector>

class Shape
{
public:
	std::vector<ColorPoint> points;

	Shape();
	~Shape();
};

class Circle : public Shape
{
public:
	Circle(){}
	Circle(int r, int colorId);
};

class Cross : public Shape
{
public:
	Cross(){}
	Cross(int r, int colorId);
};

#endif