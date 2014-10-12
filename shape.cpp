#include <iostream>
#include "point.h"
#include "Renderer.h"
#include "Processor.h"

int main()
{
	Renderer renderer;
	Processor processor;

	renderer.Render();

	while (processor.Process())
	{
		renderer.Render();
	}

	system("PAUSE");
	return 0;
}