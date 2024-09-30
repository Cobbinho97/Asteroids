#include "LevelDisplay.h"
#include "GameObject.h"

//Andrew Cobb
//w16015479
//Level Display Class - KF6017 Software Architecture for Games

//Constructor
LevelDisplay::LevelDisplay()
{
	bCollidable = false;
	active = false;
}

//Destructor
LevelDisplay::~LevelDisplay()
{

}

void LevelDisplay::Initialise()
{
	active = true;
	MyDrawEngine* pDE = MyDrawEngine::GetInstance();
	LoadImage(L"./space.bmp");
	position.set(0, 0);
	angle = 0;
}

//Loads Background Image to Game upon being started
void LevelDisplay::Render()
{
	if (active == true)
	{
		MyDrawEngine* pDE = MyDrawEngine::GetInstance();
		pDE->DrawAt(position, image, 3.3f, angle);
	}
}

void LevelDisplay::Update(float frameTime)
{
	MyDrawEngine* pDE = MyDrawEngine::GetInstance();

	position.set(position + (velocity * frameTime));
}

//Sets Collision of Background to false
IShape2D* LevelDisplay::GetShape()
{
	return &collisionShape;
}

void LevelDisplay::ProcessCollision(GameObject* pNewObject)
{

}
