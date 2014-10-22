#pragma once

#ifndef _DATAMGR_
#define _DATAMGR_

#include "Shape.h"

enum ShapeType
{
	type_Circle,
	type_Cross,
	end_shape,
	begin_shape = type_Circle
};

class ResourceMgr
{
private:
	static ResourceMgr* _instance;

	ResourceMgr();
	~ResourceMgr();
public:

	void Initialize();
	Shape* CreateInstance(ShapeType type);
	static ResourceMgr* GetInstance();
};

#endif