#include "PowerUp.h"

//Andrew Cobb
//w16015479
//PowerUp Class - KF6017 Software Architecture for Games

//Constructor, Implementation of Pointer for ObjectManager
PowerUp::PowerUp(ObjectManager* pOM)
{
	active = true;
	bCollidable = true;
	wcscpy_s(type, L"PowerUp");
	pObjectManager = pOM;
}

//Destructor
PowerUp::~PowerUp()
{

}

void PowerUp::Initialise()
{
	//Will load Power Up image in Level at random position
	LoadImage(L"./crate2.bmp");
	position = Vector2D(rand() % 1500 - 700, rand() % 1500 - 700);
	collisionShape.PlaceAt(position, 10);
}

// Gets Collision Shape of PowerUp
IShape2D* PowerUp::GetShape()
{
	return &collisionShape;
}

//Sets power up object active to false when picked up by Spaceship
void PowerUp::ProcessCollision(GameObject* pNewObject)
{
	if (typeid(*pNewObject) == typeid(Spaceship))
	{
		active = false;
	}
}

void PowerUp::Update(float frameTime)
{

}
