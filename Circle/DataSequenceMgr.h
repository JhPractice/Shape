#pragma once


#ifndef _DATASEQUENCEMGR_
#define _DATASEQUENCEMGR_

#include <vector>
class Shape;

class DataSequenceMgr
{
private:
	std::vector<Shape*> _shapes;
	static DataSequenceMgr* _instance;
	DataSequenceMgr();
	~DataSequenceMgr();
public:
	static DataSequenceMgr* GetInstance()
	{
		if (_instance == NULL)
			_instance = new DataSequenceMgr();
		return _instance;
	}

	void Clear();
	void Append(Shape*);
	std::vector<Shape*>& GetShapes(){ return _shapes; }
};


#endif