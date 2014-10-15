#pragma once

#ifndef _PROCESSOR_
#define _PROCESSOR_

#include "Common.h"
#include <vector>

class Processor
{
private:
	static Processor* instance;
	Processor();
	~Processor();

	std::vector<Point> innerCircle;
	std::vector<Point> outerCircle;
	std::vector<Point> cross;

	void InitCirclePoint(std::vector<Point>& point, Point center, int r);
	void InitCrossPoint(std::vector<Point>& point, Point center, int r);

public:
	static Processor* GetInstance()
	{
		if (!instance)
			instance = new Processor();
		return instance;
	}

	bool IsInnerCircle(Point p);
	bool IsOuterCircle(Point p);
	bool IsCross(Point p);

	void Initialize();

	bool Process();
};

#endif
