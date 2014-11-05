#include "Processor.h"
#include <Windows.h>

#define _USE_MATH_DEFINES
#include <math.h>
#include "ResourceMgr.h"

#include "DataSequenceMgr.h"

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

	_gameObjects.push_back(new GameObject(innerCircle));
	_gameObjects.push_back(new GameObject(outerCircle));
	_gameObjects.push_back(new GameObject(cross));

	for (unsigned int i = 0; i < _gameObjects.size(); ++i)
	{
		_gameObjects[i]->Translate(Point(10, 9));
	}
}

bool Processor::Process()
{
	if (GetAsyncKeyState(VK_ESCAPE))
		return false;

	DataSequenceMgr::GetInstance()->Clear();
	for (unsigned int i = 0; i < _gameObjects.size(); i++)
	{
		_gameObjects[i]->Rotate(i == 0 ? -3.f : 3.f);

		Shape* procesedShape = new Shape();
		Rotate(procesedShape, _gameObjects[i]->GetShape(), _gameObjects[i]->GetRotation());
		Translate(procesedShape, procesedShape, _gameObjects[i]->GetTranslation());
		DataSequenceMgr::GetInstance()->Append(procesedShape);
	}

	return true;
}