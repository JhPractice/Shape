#include "ResourceMgr.h"

ResourceMgr* ResourceMgr::_instance = NULL;

ResourceMgr::ResourceMgr()
{
	Initialize();
}


ResourceMgr::~ResourceMgr()
{
}

void ResourceMgr::Initialize()
{
}

Shape* ResourceMgr::CreateInstance(ShapeType type)
{
	switch (type)
	{
	case type_Circle:
		return new Circle();
	case type_Cross:
		return new Cross();
	}

	return NULL;
}

ResourceMgr* ResourceMgr::GetInstance()
{
	if (_instance == NULL)
		_instance = new ResourceMgr();
	return _instance;
}
