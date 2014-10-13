#pragma once


#ifndef _POINT_
#define _POINT_

typedef struct _Point
{
	int x, y;
	_Point() : x(0), y(0) {}
	_Point(int _x, int _y) : x(_x), y(_y) {}
} Point;

#endif