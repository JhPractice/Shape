#pragma once

#ifndef _SNAKE_
#define _SNAKE_

#include "point.h"

class Snake
{
private:
	int head;
	static const int kMaxLength = 5;
	Point body[kMaxLength];

public:
	Snake();
	~Snake();

	bool Move(Point& p);

	bool IsExist(Point& p);

	inline Point GetHeadPlace()
	{
		return body[head];
	}
};

#endif