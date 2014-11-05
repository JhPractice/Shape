#include <iostream>
#include "Renderer.h"
#include "Processor.h"
#include <algorithm>
#include "DataSequenceMgr.h"
#include "Shape.h"

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

	for (int i = 0; i < kRow; i++)
	{
		for (int j = 0; j < kCullum; j++)
		{
			SetConsoleTextAttribute(consoleBuffer[currentBuffer], 15);
			SetConsoleCursorPosition(consoleBuffer[currentBuffer], { j * 2, i });
			WriteConsole(consoleBuffer[currentBuffer], "  ", 2, &charWritten, NULL);
		}
	}

	std::vector<Shape*>& shapes = DataSequenceMgr::GetInstance()->GetShapes();
	for (unsigned int i = 0; i < shapes.size(); i++)
	{
		for (unsigned int j = 0; j < shapes[i]->_points.size(); j++)
		{
			ColorPoint& cp = shapes[i]->_points[j];
			SetConsoleTextAttribute(consoleBuffer[currentBuffer], cp.colorId);
			SetConsoleCursorPosition(consoleBuffer[currentBuffer], { cp.point.x * 2, cp.point.y });
			WriteConsole(consoleBuffer[currentBuffer], "* ", 2, &charWritten, NULL);
		}
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