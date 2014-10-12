#pragma once

#ifndef _PROCESSOR_
#define _PROCESSOR_

#include "point.h"

class Processor
{
private:
	Point m_Current;
	static Processor* instance;

public:
	Processor();
	~Processor();
	static Processor* GetInstance(){}

	void Initialize();

	bool Process();
};

#endif
