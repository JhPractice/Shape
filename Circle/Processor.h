#pragma once

#ifndef _PROCESSOR_
#define _PROCESSOR_

#include "Common.h"
#include <vector>
#include "Shape.h"

class Processor
{
private:
	static Processor* instance;
	Processor();
	~Processor();

	Point translatePoint;
	Circle innerCircle;
	Circle outerCircle;
	Cross cross;

	std::vector<ColorPoint> points;

public:
	static Processor* GetInstance()
	{
		if (!instance)
			instance = new Processor();
		return instance;
	}

	std::vector<ColorPoint>& GetPoints() { return points; }

	void Initialize();

	bool Process();
};

#endif
