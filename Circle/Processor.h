#pragma once

#ifndef _PROCESSOR_
#define _PROCESSOR_

#include "Common.h"
#include <vector>

class GameObject;

class Processor
{
private:
	static Processor* _instance;
	Processor();
	~Processor();

	std::vector<GameObject*> _gameObjects;

public:
	static Processor* GetInstance()
	{
		if (!_instance)
			_instance = new Processor();
		return _instance;
	}

	std::vector<GameObject*>& GetGameObjects() { return _gameObjects; }

	void Initialize();

	bool Process();
};

#endif
