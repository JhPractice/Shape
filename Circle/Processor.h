#pragma once

#ifndef _PROCESSOR_
#define _PROCESSOR_

#include "Common.h"
#include <vector>
#include "Shape.h"

class Processor
{
private:
	static Processor* _instance;
	Processor();
	~Processor();

	Point _translatePoint;


	std::vector<Shape*> _shapes;

public:
	static Processor* GetInstance()
	{
		if (!_instance)
			_instance = new Processor();
		return _instance;
	}

	std::vector<Shape*>& GetShapes() { return _shapes; }

	void Initialize();

	bool Process();
};

#endif
