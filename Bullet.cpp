#include "Bullet.h"
#include "Rock.h"

//w16015479
//Bullet Class - KF6017 Software Architecture for Games

//Constructor
Bullet::Bullet()
{
	active = false;
	wcscpy_s(type, L"bullet");
	bCollidable = true;
}

//Destructor
Bullet::~Bullet()
{

}

void Bullet::Initialise(Vector2D startPosition, float sAngle, Vector2D launcherVelocity)
{
	active = true;

	//Gets pointer of Draw Engine and loads picture of Bullet
	MyDrawEngine* pDE = MyDrawEngine::GetInstance();
	bullet = pDE->LoadPicture(L"bullet.bmp");

	//Bullets Variables
	bulletSpeed = 300.0f;
	position = startPosition;
	angle = sAngle;
	velocity.setBearing(angle, bulletSpeed);
	actTimer = 1.0f;
	velocity = velocity + launcherVelocity;
}

IShape2D* Bullet::GetShape()
{
	return &collisionShape;
}

void Bullet::ProcessCollision(GameObject* pNewObject)
{
	if (typeid(*pNewObject) == typeid(Rock))
	{
		active = false;
	}
}
//When Bullet is fired, collision is attached to Bullet Object
void Bullet::Update(float frameTime)
{
	position += velocity * frameTime;

	if (actTimer <= 0)
	{
		active = false;
	}
	actTimer = actTimer - 0.005f;
	collisionShape.PlaceAt(position, 5);
}

//Will draw a bullet image at position of SpaceShip
void Bullet::Render()
{
	if (active == true)
	{
		MyDrawEngine* pDE = MyDrawEngine::GetInstance();
		pDE->DrawAt(position, bullet, 1.0f, angle, 0);
	}
}
