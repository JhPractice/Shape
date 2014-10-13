#include "Processor.h"
#include <Windows.h>
#include "Common.h"

Processor* Processor::instance = NULL;

Processor::Processor()
{
	Initialize();
}


Processor::~Processor()
{
}

void Processor::Initialize()
{
}

bool Processor::Process()
{
	if (GetAsyncKeyState(VK_ESCAPE))
		return false;

	Point oldPoint = snake.GetHeadPlace();
	Point newPoint = oldPoint;
	if (GetAsyncKeyState(VK_LEFT))
		newPoint.x = max(oldPoint.x - 1, 0);

	if (GetAsyncKeyState(VK_RIGHT))
		newPoint.x = min(oldPoint.x + 1, kCullum - 1);

	if (GetAsyncKeyState(VK_UP))
		newPoint.y = max(oldPoint.y - 1, 0);

	if (GetAsyncKeyState(VK_DOWN))
		newPoint.y = min(oldPoint.y + 1, kRow - 1);

	if (newPoint.x != oldPoint.x || newPoint.y != oldPoint.y)
		snake.Move(newPoint);

	return true;
}
