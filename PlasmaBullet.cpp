#include "PlasmaBullet.h"
#include "rock.h"

//Andrew Cobb
//w16015479
//Plasma Bullet Class - KF6017 Software Architecture for Games

//Constructor
PlasmaBullet::PlasmaBullet()
{
	active = false;
	wcscpy_s(type, L"plasmabullet");
	bCollidable = true;
}

//Destructor
PlasmaBullet::~PlasmaBullet()
{

}

void PlasmaBullet::Initialise(Vector2D startPosition, float sAngle, Vector2D launcherVelocity)
{
	active = true;

	//Gets pointer of Draw Engine and loads picture of Bullet
	MyDrawEngine* pDE = MyDrawEngine::GetInstance();
	plasmabullet = pDE->LoadPicture(L"plasma.bmp");

	//Bullets Variables
	bulletSpeed = 300.0f;
	position = startPosition;
	angle = sAngle;
	velocity.setBearing(angle, bulletSpeed);
	actTimer = 1.0f;
	velocity = velocity + launcherVelocity;
}

//Gets collision shape of Plasma Bullet
IShape2D* PlasmaBullet::GetShape()
{
	return &collisionShape;
}

//If a Object of Plasma Bullet colldies with Rock, Object gets set to inactive 
void PlasmaBullet::ProcessCollision(GameObject* pNewObject)
{
	if (typeid(*pNewObject) == typeid(Rock))
	{
		active = false;
	}
}
//When Bullet is fired, collision is attached to Bullet Object
void PlasmaBullet::Update(float frameTime)
{
	position += velocity * frameTime;

	if (actTimer <= 0)
	{
		active = false;
	}
	actTimer = actTimer - 0.005f;
	collisionShape.PlaceAt(position, 5);
}

//If Bullet Object is set to active a bullet image will render
void PlasmaBullet::Render()
{
	if (active == true)
	{
		MyDrawEngine* pDE = MyDrawEngine::GetInstance();
		pDE->DrawAt(position, plasmabullet, 1.0f, angle, 0);
	}
}