#include "Explosion.h"

//w16015479
//Explosion Class - KF6017 Software Architecture for Games

//Constructor
Explosion::Explosion()
{
	bCollidable = false;
}

//Destructor
Explosion::~Explosion()
{

}

//Initialises a array of Explosions, will play explosion upon Collision Occuring
void Explosion::Initialise(Vector2D position)
{
	MyDrawEngine* pDE = MyDrawEngine::GetInstance(); 

	//Array of Explosion Images
	images[0] = pDE->LoadPicture(L"explosion1.bmp");
	images[1] = pDE->LoadPicture(L"explosion2.bmp");
	images[2] = pDE->LoadPicture(L"explosion3.bmp");
	images[3] = pDE->LoadPicture(L"explosion4.bmp");
	images[4] = pDE->LoadPicture(L"explosion5.bmp");
	images[5] = pDE->LoadPicture(L"explosion6.bmp");
	images[6] = pDE->LoadPicture(L"explosion7.bmp");
	images[7] = pDE->LoadPicture(L"explosion8.bmp");

	currentImage = 0;
	this->position = position;
}


IShape2D* Explosion::GetShape()
{
	return &collisionShape;
}


void Explosion::ProcessCollision(GameObject* pNewObject)
{

}

void Explosion::Update(float frameTime)
{
	//Will Place Explosion at the the position of the Current Collision
	currentImage = currentImage + 1.0 * frameTime;

	if (currentImage >= 8)
	{
		active = false;
	}
	collisionShape.PlaceAt(position, 5);
}

void Explosion::Render()
{
	//If currentImage is less than the array size, the explosion image will be played as
	//the currentImage variable is incremented
	if (currentImage < 8)
	{
		MyDrawEngine* pDE = MyDrawEngine::GetInstance();
		pDE->DrawAt(position, images[(int)currentImage], 1.0f);
		currentImage ++;
	}
}