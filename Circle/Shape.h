#pragma once

#ifndef _SHAPE_
#define _SHAPE_

#include "Common.h"
#include <vector>


class Shape
{
public:
	Shape();
	~Shape();

	std::vector<ColorPoint> _points;

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

class GameObject
{
private:
	Shape* _shape;
	Point _translation;
	float _rotation;
public:
	GameObject(Shape* shape) : _shape(shape), _translation(Point(0, 0)), _rotation(0.f) {}
	Shape* GetShape() { return _shape; }
	Point GetTranslation() { return _translation; }
	float GetRotation() { return _rotation; }
	void Translate(Point translation) { _translation = _translation + translation; }
	void Rotate(float roation)
	{
		_rotation += roation;
		if (_rotation >= 360)
			_rotation -= 360;
		if (_rotation < 0)
			_rotation += 360;
	}
};


void Rotate(Shape* outModel, Shape* inModel, float angle);
void Translate(Shape* outModel, Shape* inModel, Point distance);

#endif