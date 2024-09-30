#include "BorderUp.h"

//w16015479
//BorderUp Class - KF6017 Software Architecture for Games

//Constructor
BorderUp::BorderUp()
{
	bCollidable = true;
	active = false;
	wcscpy_s(type, L"borderUp");
}

//Destructor
BorderUp::~BorderUp()
{

}

void BorderUp::Initialise()
{
	active = true;
}

//Sets Border Measurements
IShape2D* BorderUp::GetShape()
{
	borderUp.PlaceAt(900, 1800, 1200, -1800);
	return&borderUp;
}

void BorderUp::ProcessCollision(GameObject* pNewObject)
{
	MySoundEngine* pSE = MySoundEngine::GetInstance();

	if (typeid(*pNewObject) == typeid(Rock))
	{

	}
	if (typeid(*pNewObject) == typeid(Spaceship))
	{

	}
}

//Renders border with collison in Level
void BorderUp::Render()
{
	MyDrawEngine* pDE = MyDrawEngine::GetInstance();

}

void BorderUp::Update(float frameTime)
{
	collisionShape.PlaceAt(position, 60);
}
