#include "BorderDown.h"
#include "mydrawengine.h"
#include "gamecode.h"
#include "Explosion.h"

//w16015479
//BorderDown Class - KF6017 Software Architecture for Games

//Constructor
BorderDown::BorderDown()
{
	bCollidable = true;
	active = false;
	wcscpy_s(type, L"borderDown");
}

//Destructor
BorderDown::~BorderDown()
{

}


//Sets Border Measurements
IShape2D* BorderDown::GetShape()
{
	borderDown.PlaceAt(-900, -1800, -1200, 1800);

	return&borderDown;

}

void BorderDown::ProcessCollision(GameObject* pNewObject)
{
	if (typeid(*pNewObject) == typeid(Rock))
	{
		
	}
	if (typeid(*pNewObject) == typeid(Spaceship))
	{

	}
}

void BorderDown::Initialise()
{
	active = true;
}

//Renders border with collison in Level
void BorderDown::Render()
{
	MyDrawEngine* pDE = MyDrawEngine::GetInstance();

}

void BorderDown::Update(float frameTime)
{
	collisionShape.PlaceAt(position, 60);
}
