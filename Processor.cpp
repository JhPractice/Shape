#include "Processor.h"
#include <Windows.h>

const int kRow = 20;
const int kCullum = 50;

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
	m_Current.x = kCullum / 2;
	m_Current.y = kRow / 2;
}

bool Processor::Process()
{
	if (GetAsyncKeyState(VK_ESCAPE))
		return false;

	if (GetAsyncKeyState(VK_LEFT))
		m_Current.x = max(m_Current.x - 1, 0);

	if (GetAsyncKeyState(VK_RIGHT))
		m_Current.x = min(m_Current.x + 1, kCullum - 1);

	if (GetAsyncKeyState(VK_UP))
		m_Current.y = max(m_Current.y - 1, 0);

	if (GetAsyncKeyState(VK_DOWN))
		m_Current.y = min(m_Current.y + 1, kRow - 1);

	return true;
}
