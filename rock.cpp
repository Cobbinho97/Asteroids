#include "rock.h"
#include "GameObject.h"
#include "LevelManager.h"

//Andrew Cobb
//w16015479
//Rock Class - KF6017 Software Architecture for Games

//Constructor, Implementation of Pointer for ObjectManager,LevelManager
Rock::Rock(ObjectManager* pOM, LevelManager* pLM) 
{
	active = false;
	wcscpy_s(type, L"rock");
	bCollidable = true;
	pLevelManager = pLM;
	pObjectManager = pOM;
}

//Destructor
Rock::~Rock()
{

}

void Rock::Initialise()
{
	damageTimer = 0;
	active = true;
	position = Vector2D (rand()%1500-700,rand()%1500-700); //Creates Random positions of Rocks within Game Boundaries
	velocity = Vector2D(rand() % 2 - 1, rand() % 2 - 1); //Creates Random Velocities of the Rocks
	angle = rand()% 4; //Creates random angles fo Rocks
	rockHealth = 100;
	int imgName = rand() % 4;
	explosionSound = MySoundEngine::GetInstance()->LoadWav(L"explosion.wav");
	//Random Generation of Rock Images
	if (imgName == 0)
	{
		LoadImage(L"rock1.bmp");
	}
	if (imgName == 1)
	{
		LoadImage(L"rock2.bmp");
	}
	if (imgName == 2)
	{
		LoadImage(L"rock3.bmp");
	}
	if (imgName == 3)
	{
		LoadImage(L"rock4.bmp");
	}

}

void Rock::ProcessCollision(GameObject* pNewObject)
{

	MySoundEngine* pSE = MySoundEngine::GetInstance();

	// Processes Collsions of Rocks and produces Velocity based on Collision Speed
	if (typeid(*pNewObject) == typeid(Rock))
	{
		Vector2D DIR = pNewObject->GetPosition() - position;
		if (DIR * velocity > 0)
		{
			Vector2D n = -DIR;
			n = n.unitVector();
			velocity = velocity - 2 * (velocity * n) * n;
		}
	}
	//Rock will explode upon Collision with a Bullet, Producing a Explosion
	else if (typeid(*pNewObject) == typeid(Bullet))
	{
		damageTimer = 0.5;
		rockHealth = rockHealth - 25;

		if (rockHealth <= 0)
		{
			pSE->Play(explosionSound);
			pSE->SetVolume(explosionSound, 0);
			Message msg;
			msg.type = ROCKWASDESTROYED;
			msg.position = position;
			msg.pSource = this;
			pLevelManager->HandleMessage(msg);
			active = false;
			pExp = new Explosion();
			pExp->Initialise(position);
			pObjectManager->AddObject(pExp);
		}
	}
	//Rock will explode upon Collision with a Plasma Bullet, Producing a Explosion
	else if (typeid(*pNewObject) == typeid(PlasmaBullet))
	{
		rockHealth = rockHealth - 100;

		if (rockHealth <= 0)
		{
			pSE->Play(explosionSound);
			pSE->SetVolume(explosionSound, 0);
			Message msg;
			msg.type = ROCKWASDESTROYED;
			msg.position = position;
			msg.pSource = this;
			pLevelManager->HandleMessage(msg);
			active = false;
			pExp = new Explosion();
			pExp->Initialise(position);
			pObjectManager->AddObject(pExp);
		}
	}

	// When Rock collide with Borders, Will provide accurate velocity upon Collision
	else if (typeid(*pNewObject) == typeid(BorderDown))
	{
		velocity.YValue = -velocity.YValue;
	}
	else if (typeid(*pNewObject) == typeid(BorderUp))
	{
		velocity.YValue = -velocity.YValue;
	}
	else if (typeid(*pNewObject) == typeid(BorderRight))
	{
		velocity.XValue = -velocity.XValue;
	}
	else if (typeid(*pNewObject) == typeid(BorderLeft))
	{
		velocity.XValue = -velocity.XValue;
	}
}
// Gets Collision Shape of Rock
IShape2D* Rock::GetShape()
{
	return &collisionShape;
}

//If Rock is Active, will Display in level until Collision
void Rock::Update(float frameTime)
{
	if (active == true)
	{
		damageTimer = damageTimer - frameTime;
		if (damageTimer > 0)
		{
			seeThrough = damageTimer - (int)damageTimer;
		}
		else
		{
			seeThrough = 0;
		}
	}
	position = position + velocity;

	collisionShape.PlaceAt(position, 60);
}