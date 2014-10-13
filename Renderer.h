#pragma once

#ifndef _RENDERER_
#define _RENDERER_

#include <Windows.h>

#include "Common.h"

class Renderer
{
private:
	char buffer[kRow][kCullum];

	HANDLE consoleBuffer[2];
	int currentBuffer;

	void WriteBuffer();
	void SwapBuffer();

public:
	Renderer();
	~Renderer();

	void Initialize();

	void Render();
};

#endif
