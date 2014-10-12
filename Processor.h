#pragma once

#ifndef _PROCESSOR_
#define _PROCESSOR_

#include "point.h"

class Processor
{
private:
	static Processor* instance;
	Processor();
	~Processor();

public:
	Point m_Current;
	static Processor* GetInstance()
	{
		if (!instance)
			instance = new Processor();
		return instance;
	}

	void Initialize();

	bool Process();
};

#endif
