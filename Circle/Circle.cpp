#include <iostream>

#include "Processor.h"
#include "Renderer.h"


int main()
{
	//HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	//SetConsoleTextAttribute(hConsole, 1);

	Renderer renderer;
	Processor* processor = Processor::GetInstance();
	renderer.Render();

	while (processor->Process())
	{
		renderer.Render();
		Sleep(100);
	}

	system("PAUSE");
	return 0;
}