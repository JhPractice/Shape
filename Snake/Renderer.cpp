#include <iostream>
#include "Renderer.h"
#include "Processor.h"

void HideCursor(HANDLE h)
{
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(h, &info);
}

Renderer::Renderer()
{
	Initialize();
}

Renderer::~Renderer()
{
}

void Renderer::Initialize()
{
	consoleBuffer[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	consoleBuffer[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	currentBuffer = 0;
	HideCursor(consoleBuffer[0]);
	HideCursor(consoleBuffer[1]);
}

void Renderer::WriteBuffer()
{
	DWORD charWritten = 0;
	Processor* processor = Processor::GetInstance();
	Snake* snake = &processor->snake;

	for (int i = 0; i < kRow; i++)
	{
		for (int j = 0; j < kCullum; j++)
		{
			if (snake->IsExist(Point(j, i)))
				buffer[i][j] = '*';
			else
				buffer[i][j] = ' ';
		}
		
		WriteConsoleOutputCharacter(consoleBuffer[currentBuffer], buffer[i], kCullum, { 0, i }, &charWritten);
	}
}

void Renderer::SwapBuffer()
{
	SetConsoleActiveScreenBuffer(consoleBuffer[currentBuffer]);
	currentBuffer = (currentBuffer + 1) % 2;
}

void Renderer::Render()
{
	WriteBuffer();
	SwapBuffer();
}