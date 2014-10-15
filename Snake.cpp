#include "Snake.h"
#include "Common.h"


Snake::Snake()
{
	Point none;
	none.x = -1;
	none.y = -1;
	for (int i = 1; i < kMaxLength; i++)
	{
		body[i] = none;
	}
	head = 0;
	body[head].x = kCullum / 2;
	body[head].y = kRow / 2;
}

Snake::~Snake()
{
}

bool Snake::IsExist(Point& p)
{
	for (int i = 0; i < Snake::kMaxLength; i++)
	{
		if (body[i].x == p.x && body[i].y == p.y)
		{
			return true;
		}
	}
	return false;
}

bool Snake::Move(Point& p)
{
	head = (head+1) % kMaxLength;
	body[head] = p;
	return true;
}
