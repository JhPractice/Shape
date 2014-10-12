#pragma once

#ifndef _RENDERER_
#define _RENDERER_

#include <Windows.h>

const int kRow = 20;
const int kCullum = 50;

class Renderer
{
private:
	char buffer[kRow][kCullum + 1];

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
