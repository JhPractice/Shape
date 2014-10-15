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


	for (int i = 0; i < kRow; i++)
	{
		for (int j = 0; j < kCullum; j++)
		{
			Point p(j, i);
			if (processor->IsInnerCircle(p))
			{
				SetConsoleTextAttribute(consoleBuffer[currentBuffer], 15);
				SetConsoleCursorPosition(consoleBuffer[currentBuffer], { j * 2, i });
				WriteConsole(consoleBuffer[currentBuffer], "* ", 2, &charWritten, NULL);
			}
			else if (processor->IsOuterCircle(p))
			{
				SetConsoleTextAttribute(consoleBuffer[currentBuffer], 10);
				SetConsoleCursorPosition(consoleBuffer[currentBuffer], { j * 2, i });
				WriteConsole(consoleBuffer[currentBuffer], "* ", 2, &charWritten, NULL);
			}
			else if (processor->IsCross(p))
			{
				SetConsoleTextAttribute(consoleBuffer[currentBuffer], 12);
				SetConsoleCursorPosition(consoleBuffer[currentBuffer], { j * 2, i });
				WriteConsole(consoleBuffer[currentBuffer], "* ", 2, &charWritten, NULL);
			}
			else
			{
				SetConsoleTextAttribute(consoleBuffer[currentBuffer], 15);
				SetConsoleCursorPosition(consoleBuffer[currentBuffer], { j * 2, i });
				WriteConsole(consoleBuffer[currentBuffer], "  ", 2, &charWritten, NULL);
			}
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