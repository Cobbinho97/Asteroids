#include "BorderLeft.h"
#include "mydrawengine.h"
#include "gamecode.h"
#include "Explosion.h"


//w16015479
//BorderLeft Class - KF6017 Software Architecture for Games

//Constructor
BorderLeft::BorderLeft()
{
	bCollidable = true;
	active = false;
	wcscpy_s(type, L"borderLeft");
}

//Destructor
BorderLeft::~BorderLeft()
{

}


//Sets Border Measurements
IShape2D* BorderLeft::GetShape()
{
	borderLeft.PlaceAt(-1000, -1800, 1200, -1650);

	return&borderLeft;

}

void BorderLeft::ProcessCollision(GameObject* pNewObject)
{
	if (typeid(*pNewObject) == typeid(Rock))
	{

	}
	if (typeid(*pNewObject) == typeid(Spaceship))
	{
	}
}

void BorderLeft::Initialise()
{
	active = true;
}

//Renders border with collison in Level
void BorderLeft::Render()
{
	MyDrawEngine* pDE = MyDrawEngine::GetInstance();
}

void BorderLeft::Update(float frameTime)
{
	collisionShape.PlaceAt(position, 60);
}
