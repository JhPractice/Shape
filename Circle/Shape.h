#pragma once

#ifndef _SHAPE_
#define _SHAPE_

#include "Common.h"
#include <vector>

class Shape
{
private:
	float _rotationAngle;
	Point _tranlationPoint;
	std::vector<ColorPoint> appliedPoints;
protected:
	std::vector<ColorPoint> points;
public:

	Shape();
	~Shape();

	void Rotate(float angle);
	void Translate(Point point);
	void ApplyMatrix();

	std::vector<ColorPoint>& GetPoints() { return appliedPoints; }

	virtual void Initialize(int r, int colorId);
};

class Circle : public Shape
{
public:
	Circle(){}
	Circle(int r, int colorId);

	void Initialize(int r, int colorId);
};

class Cross : public Shape
{
public:
	Cross(){}
	Cross(int r, int colorId);

	void Initialize(int r, int colorId);
};

#endif