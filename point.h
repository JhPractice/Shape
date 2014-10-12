#pragma once


#ifndef _POINT_
#define _POINT_

typedef struct _Point
{
	float x, y;
	_Point() : x(0.f), y(0.f) {}
} Point;

#endif