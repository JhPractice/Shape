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
	translatePoint = Point(10, 9);
	innerCircle = Circle(5, 15);
	outerCircle = Circle(8, 10);
	cross = Cross(5, 12);
}

bool Processor::Process()
{
	if (GetAsyncKeyState(VK_ESCAPE))
		return false;

	points.clear();

	static float innerCircleRotate = 0.f;
	static float outerCircleRotate = 0.f;
	static float crossRotate = 0.f;

	for (unsigned int i = 0; i < innerCircle.points.size(); i++)
	{
		points.push_back(innerCircle.points[i].Rotate(innerCircleRotate) + translatePoint);
	}
	for (unsigned int i = 0; i < outerCircle.points.size(); i++)
	{
		points.push_back(outerCircle.points[i].Rotate(outerCircleRotate) + translatePoint);
	}
	for (unsigned int i = 0; i < cross.points.size(); i++)
	{
		points.push_back(cross.points[i].Rotate(crossRotate) + translatePoint);
	}

	innerCircleRotate -= 3.f;
	outerCircleRotate += 3.f;
	crossRotate += 3.f;

	if (innerCircleRotate <= -360.f)
		innerCircleRotate = 0.f;
	if (outerCircleRotate >= 360.f)
		outerCircleRotate = 0.f;
	if (crossRotate >= 360.f)
		crossRotate = 0.f;
	return true;
}