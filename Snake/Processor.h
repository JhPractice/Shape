#pragma once

#ifndef _PROCESSOR_
#define _PROCESSOR_

#include "Snake.h"

class Processor
{
private:
	static Processor* instance;
	Processor();
	~Processor();
public:
	Snake snake;
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
