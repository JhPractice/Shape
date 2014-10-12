#include <iostream>
#include "Renderer.h"


Renderer::Renderer()
{
	Initialize();
}


Renderer::~Renderer()
{
}

void Renderer::Initialize()
{
}

void Renderer::Render()
{
	system("cls");
	for (int i = 0; i < kRow; i++)
	{
		for (int j = 0; j < kCullum; j++)
		{
			std::cout << buffer[i][j];
		}
		std::cout << std::endl;
	}
}
