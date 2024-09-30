#include "spaceship.h"
#include "LevelManager.h"

//Andrew Cobb
//w16015479
//Spaceship Class - KF6017 Software Architecture for Games

Spaceship::Spaceship(ObjectManager* pOM, LevelManager* pLM): pObjectManager(pOM) //Constructor, Implementation of Pointer for ObjectManager,LevelManager
{
	active = false;
	wcscpy_s(type, L"spaceship");
	bCollidable = true;
	pLevelManager = pLM;
	pObjectManager = pOM;
}

//Destructor
Spaceship::~Spaceship()
{

}
//Initialises Spaceships Object and its Properties
void Spaceship::Initialise()
{
	active = true;
	position;
	velocity;
	angle = 0;
	powerUp = false;
	powerUpTimer = 0;
	shootDelay = 0.5f;
	noDamageTimer = 2.0f;
	health = 100;
	shipFront.setBearing(angle, 60.0f);
	//Loads Sounds to be played upon certain actions
	shootSound = MySoundEngine::GetInstance()->LoadWav(L"shoot.wav");
	explosionSound = MySoundEngine::GetInstance()->LoadWav(L"explosion.wav");
	music = MySoundEngine::GetInstance()->LoadWav(L"halo.wav");
	boostSound = MySoundEngine::GetInstance()->LoadWav(L"thrustloop2.wav");
	//Loads Image of Spaceship to be Initialised upon Game Creation
	LoadImage(L"./spaceship.bmp");  

}
//Pointer of IShape2D, returns collision shape for Spaceship
//return Collision Shape
IShape2D* Spaceship::GetShape() 
{
	collisionShape.PlaceAt(position, 40);
	return &collisionShape;
}
void Spaceship::ProcessCollision(GameObject* pNewObject)
{
	//Pointer to Sound Engine
	MySoundEngine* pSE = MySoundEngine::GetInstance();

	//If Collison with Rock Occurs, Explosion Occurs and is added to ObjectManager
	if (health <= 0)
	{
		Message msg;
		msg.type = SPACESHIPWASDESTROYED;
		msg.position = position;
		msg.pSource = this;
		pLevelManager->HandleMessage(msg);
		pSE->Play(explosionSound);
		pSE->SetVolume(explosionSound, 0);

		pExp = new Explosion();
		pExp->Initialise(position);
		pObjectManager->AddObject(pExp);
		active = false;
	}

	if (typeid(*pNewObject) == typeid(Rock) && noDamageTimer <= 0)
	{
		health = health - 100;
		noDamageTimer = 3.0f;
	}

	//If Collison with an Border Occurs, Explosion Occurs and is added to ObjectManager

	if (typeid(*pNewObject) == typeid(BorderUp))
	{
		health = health - 100;
		noDamageTimer = 3.0f;
	}
	if (typeid(*pNewObject) == typeid(BorderDown))
	{
		health = health - 100;
		noDamageTimer = 3.0f;
	}
	if (typeid(*pNewObject) == typeid(BorderLeft))
	{
		health = health - 100;
		noDamageTimer = 3.0f;
	}
	if (typeid(*pNewObject) == typeid(BorderRight))
	{
		health = health - 100;
		noDamageTimer = 3.0f;
	}
	if (typeid(*pNewObject) == typeid(PowerUp))
	{
		powerUp = true;
		powerUpTimer = 5;

		Message msg;
		msg.type = POWERUPACTIVATED;
		msg.position = position;
		msg.pSource = this;
		pLevelManager->HandleMessage(msg);

	}
}
void Spaceship::Update(float frameTime)
{
	shootDelayTimer = shootDelayTimer - frameTime;
	double myFrameTime = frameTime;
	MyInputs* pInputs = MyInputs::GetInstance();
	//Gets Pointer to myInputs, processing User Inputs
	pInputs->SampleKeyboard();
	//Gets Pointer to Draw Engine, to process Images
	MyDrawEngine* pDE = MyDrawEngine::GetInstance();

	//Gets Pointer to Sound Engine, to process Sounds
	MySoundEngine* pSE = MySoundEngine::GetInstance();

	noDamageTimer = noDamageTimer - frameTime;

	powerUpTimer = powerUpTimer - frameTime;
	//Creates short timer upon loading into level, so that player is not immediatly destroyed
	if (noDamageTimer > 0)
	{
		seeThrough = (noDamageTimer * 2) - (int)(noDamageTimer * 2);
	}
	else
	{
		seeThrough = 0;
	}

	if (powerUpTimer <= 0)
	{
		powerUp = false;
	}
	//If active and spacebar is pressed, bullet will fire
if (pInputs->KeyPressed(DIK_SPACE)&& active == true &&shootDelayTimer<=0 && powerUp == false) 
	{
		pSE->Play(shootSound);
		pSE->SetVolume(shootSound, 0);

		pBullet = new Bullet();
		pBullet->Initialise(position, angle, velocity);
		pObjectManager->AddObject(pBullet);
		shootDelayTimer = shootDelay;

	}
//If active and spacebar is pressed while powerup is active , plasma bullet will fire
if (pInputs->KeyPressed(DIK_SPACE) && active == true && shootDelayTimer <= 0 && powerUp == true)
{
	pSE->Play(shootSound);
	pSE->SetVolume(shootSound, 0);

	plasBullet = new PlasmaBullet();
	plasBullet->Initialise(position, angle, velocity);
	pObjectManager->AddObject(plasBullet);
	shootDelayTimer = shootDelay;

}
	if (pInputs->KeyPressed(DIK_RIGHT)) 
	{
		angle = angle + 2.0f * frameTime;
	}
	else if (pInputs->KeyPressed(DIK_LEFT)) 
	{
		angle = angle -2.0f * frameTime;
	}
	else if (pInputs->KeyPressed(DIK_UP)) 
	{
		acceleration.setBearing(angle, 150);
		velocity = velocity + acceleration * frameTime;
		pSE->Play(boostSound);
		pSE->SetVolume(boostSound, 0);
	}
	else if (pInputs->KeyPressed(DIK_DOWN)) 
	{
		acceleration.setBearing(angle, -150);
		velocity = velocity + acceleration * frameTime;
	}
	else if (!(pInputs->KeyPressed(DIK_UP))) 
	{
		Vector2D friction = -0.5 * velocity;
		velocity = velocity + friction *frameTime;
	}
	else if (!(pInputs->KeyPressed(DIK_DOWN))) 
	{
		Vector2D friction = 0.5 * velocity;
		velocity = velocity + friction * frameTime;
	}
	position = position + velocity * frameTime;
}