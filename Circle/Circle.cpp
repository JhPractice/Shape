#include <iostream>

#include "Processor.h"
#include "Renderer.h"

int main()
{
	Renderer renderer;
	Processor* processor = Processor::GetInstance();

	while (processor->Process())
	{
		renderer.Render();
		Sleep(100);
	}

	system("PAUSE");
	return 0;
}