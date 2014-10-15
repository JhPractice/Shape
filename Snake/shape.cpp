#include <iostream>
#include "point.h"
#include "Renderer.h"
#include "Processor.h"

int main()
{
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