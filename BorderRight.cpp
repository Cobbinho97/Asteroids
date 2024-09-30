#include "BorderRight.h"
#include "mydrawengine.h"
#include "gamecode.h"
#include "Explosion.h"

//w16015479
//BorderRight Class - KF6017 Software Architecture for Games

//Constructor
BorderRight::BorderRight()
{
	bCollidable = true;
	active = false;
	wcscpy_s(type, L"borderRight");
}

//Destructor
BorderRight::~BorderRight()
{

}


//Sets Border Measurements
IShape2D* BorderRight::GetShape()
{
	borderRight.PlaceAt(1000, 1800, -1200, 1650);

	return&borderRight;
}

void BorderRight::ProcessCollision(GameObject* pNewObject)
{
	if (typeid(*pNewObject) == typeid(Rock))
	{

	}
	if (typeid(*pNewObject) == typeid(Spaceship))
	{
	}
}

void BorderRight::Initialise()
{
	active = true;
}

//Renders border with collison in Level
void BorderRight::Render()
{
	MyDrawEngine* pDE = MyDrawEngine::GetInstance();

}

void BorderRight::Update(float frameTime)
{
	collisionShape.PlaceAt(position, 60);
}
