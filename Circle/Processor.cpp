#include "Processor.h"
#include <Windows.h>

#define _USE_MATH_DEFINES
#include <math.h>
#include "ResourceMgr.h"

Processor* Processor::_instance = NULL;

Processor::Processor()
{
	Initialize();
}


Processor::~Processor()
{
}

void Processor::Initialize()
{
	ResourceMgr* resourceMgr = ResourceMgr::GetInstance();

	Shape* innerCircle = resourceMgr->CreateInstance(ShapeType::type_Circle);
	innerCircle->Initialize(5, 15);

	Shape* outerCircle = resourceMgr->CreateInstance(ShapeType::type_Circle);
	outerCircle->Initialize(8, 10);

	Shape* cross = resourceMgr->CreateInstance(ShapeType::type_Cross);
	cross->Initialize(5, 12);

	_shapes.push_back(innerCircle);
	_shapes.push_back(outerCircle);
	_shapes.push_back(cross);

	_translatePoint = Point(10, 9);

	for (unsigned int i = 0; i < _shapes.size(); i++)
	{
		_shapes[i]->Translate(_translatePoint);
	}
}

bool Processor::Process()
{
	if (GetAsyncKeyState(VK_ESCAPE))
		return false;

	_shapes[0]->Rotate(-3.f);
	_shapes[1]->Rotate(3.f);
	_shapes[2]->Rotate(3.f);

	for (unsigned int i = 0; i < _shapes.size(); i++)
	{
		_shapes[i]->ApplyMatrix();
	}

	return true;
}