#include "DataSequenceMgr.h"

DataSequenceMgr* DataSequenceMgr::_instance = NULL;


DataSequenceMgr::DataSequenceMgr()
{
}


DataSequenceMgr::~DataSequenceMgr()
{
}

void DataSequenceMgr::Clear()
{
	_shapes.clear();
}

void DataSequenceMgr::Append(Shape* shape)
{
	_shapes.push_back(shape);
}