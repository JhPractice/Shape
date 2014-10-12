#include <iostream>
#include "Renderer.h"
#include "Processor.h"


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
}

void Renderer::SwapBuffer()
{
	SetConsoleActiveScreenBuffer(consoleBuffer[currentBuffer]);
	currentBuffer = (currentBuffer + 1) % 2;
}

void Renderer::WriteBuffer()
{
	Processor* processor = Processor::GetInstance();

	for (int i = 0; i < kRow; i++)
	{
		for (int j = 0; j < kCullum; j++)
		{
			if (processor->m_Current.x == j && processor->m_Current.y == i)
				buffer[i][j] = '*';
			else
				buffer[i][j] = ' ';
		}
		buffer[i][kCullum] = '\n';
	}

	WriteConsoleOutputCharacter(consoleBuffer[currentBuffer], buffer[0], strlen(buffer[0]), { 0, 0 }, NULL);
}

void Renderer::Render()
{
	WriteBuffer();
	SwapBuffer();

	/*
	system("cls");
	Processor* processor = Processor::GetInstance();

	for (int i = 0; i < kRow; i++)
	{
		for (int j = 0; j < kCullum; j++)
		{
			if (processor->m_Current.x == j && processor->m_Current.y == i)
				std::cout << "*";
			else
				std::cout << " ";
			//std::cout << buffer[i][j];
		}
		std::cout << std::endl;
	}
	*/
}
