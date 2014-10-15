#pragma once

#ifndef _COMMON_
#define _COMMON_

const int kRow = 20;
const int kCullum = 30;

#ifndef _POINT_
#define _POINT_

typedef struct _Point
{
	int x, y;
	_Point() : x(0), y(0) {}
	_Point(int _x, int _y) : x(_x), y(_y) {}
} Point;

#endif

#endif