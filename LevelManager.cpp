#include "LevelManager.h"
#include "gamecode.h"

//Andrew Cobb
//w16015479
//LevelManager Class - KF6017 Software Architecture for Games

//Constructor, Implementation of Pointer for ObjectManager,LevelManager
LevelManager::LevelManager(ObjectManager* pOM) : pObjectManager(pOM)
{
	score = 0;
	lives = 3;
	LevelCompletedActive = false;
	GameOverActive = false;
	PlasmaBulletActive = false;
}

//Destructor
LevelManager::~LevelManager()
{
}

void LevelManager::Initialise()
{
	//Sets the original number of rocks to 0
	numAsteroids = 0;
	active = true;
	music = MySoundEngine::GetInstance()->LoadWav(L"./halo.wav");
	srand(10);
	gt.mark();
	gt.mark();
	
	//Creates Objects for each Game Object to be added to Game
	pLevelDisplay = new LevelDisplay;
	pLevelDisplay->Initialise();
	pObjectManager->AddObject(pLevelDisplay);

	bordD = new BorderDown;
	bordD->Initialise();
	pObjectManager->AddObject(bordD);

	bordU = new BorderUp;
	bordU->Initialise();
	pObjectManager->AddObject(bordU);

	bordL = new BorderLeft;
	bordL->Initialise();
	pObjectManager->AddObject(bordL);
	
	bordR = new BorderRight;
	bordR->Initialise();
	pObjectManager->AddObject(bordR);

	//Array for rocks to be Intialised in Level
	for (int i = 0; i < 10; i++)
	{
		rock_1 = new Rock(pObjectManager, this);
		rock_1->Initialise();
		pObjectManager->AddObject(rock_1);
		numAsteroids++;
	}
}

IShape2D* LevelManager::GetShape()
{
	return &shape;
}

void LevelManager::ProcessCollision(GameObject* pNewObject)
{

}

//Will Display power up into level when Rocks left in level is half
void LevelManager::Update(float frameTime)
{
	MySoundEngine* pSE = MySoundEngine::GetInstance();
	pSE->Play(music);
	pSE->SetVolume(music, 1);

	if (numAsteroids == 5 && powerUpActive == false)
	{
		powerUp = new PowerUp(pObjectManager);
		powerUp->Initialise();
		pObjectManager->AddObject(powerUp);
		powerUpActive = true;
	}
		if (powerUpActive == true)
		{
			PlasmaBulletActive = true;
			powerUpDisplayTimer = powerUpDisplayTimer - frameTime;

			if (powerUpDisplayTimer <= 0)
			{
				PlasmaBulletActive = false;
			}
		}
		//If Spaceship is destroyed but still has lives remaining, spaceship will respawn
	if (spaceshipActive == false && lives > 0)
	{
		spawnTimer = spawnTimer - frameTime;

		if (spawnTimer <= 0)
		{
			ship_1 = new Spaceship(pObjectManager, this);
			ship_1->Initialise();
			pObjectManager->AddObject(ship_1);
			spaceshipActive = true;
		}
		
	}
	//If no lives remaining, Game Over Screen will be displayed
	if (lives <= 0)
	{
		{
			GameOverActive = true;
			MyDrawEngine* pDE = MyDrawEngine::GetInstance();
			LoadImage(L"./GameOver.bmp");
			position.set(0, 0);
			angle = 0;

		}
	}
	//If no rocks remaininf, Completed Level Screen will be displayed
	if (numAsteroids == 0)
	{
		LevelCompletedActive = true;
		MyDrawEngine* pDE = MyDrawEngine::GetInstance();
		LoadImage(L"./LevelCompleted.bmp");
		position.set(0, 0);
		angle = 0;
		endoflevelTimer -= frameTime;
		if (endoflevelTimer <= 0)
		{
			LevelCompletedActive = false;
			for (int i = 0; i < 15; i++)
			{
				rock_1 = new Rock(pObjectManager, this);
				rock_1->Initialise();
				pObjectManager->AddObject(rock_1);
				numAsteroids++;
			}
			powerUpActive = false;
		}
	}
}

//Will Render score and lives system into level, will display game over/level completed screen based upon actions above
void LevelManager::Render()
{
	MyDrawEngine* pDE = MyDrawEngine::GetInstance();
	MyDrawEngine::GetInstance()->WriteText(250, 100, L"Score:", MyDrawEngine::WHITE);
	MyDrawEngine::GetInstance()->WriteInt(350, 100, score, MyDrawEngine::WHITE);

	MyDrawEngine::GetInstance()->WriteText(500, 100, L"Lives:", MyDrawEngine::WHITE);
	MyDrawEngine::GetInstance()->WriteInt(750, 100, lives, MyDrawEngine::WHITE);

	if (GameOverActive == true)
	{
		MyDrawEngine* pDE = MyDrawEngine::GetInstance();
		pDE->DrawAt(position, image, 3.3f, angle);
	}
	if (LevelCompletedActive == true)
	{
		MyDrawEngine* pDE = MyDrawEngine::GetInstance();
		pDE->DrawAt(position, image, 3.3f, angle);
	}
	if (PlasmaBulletActive == true)
	{
		MyDrawEngine* pDE = MyDrawEngine::GetInstance();
		MyDrawEngine::GetInstance()->WriteText(200, 200, L"Power Up Available", MyDrawEngine::WHITE);
	}
}

void LevelManager::EndGame()
{

}

//Messaging System for Level Manager - Sends messages between classes
void LevelManager::HandleMessage(Message msg)
{
	if (msg.type == ROCKWASDESTROYED)
	{
		score = score + 10;
		numAsteroids = numAsteroids - 1;
		if (numAsteroids == 0)
		{
			endoflevelTimer = 10.0f;
			LevelCompletedActive = false;
		}
	}
	if (msg.type == SPACESHIPWASDESTROYED)
	{
		lives = lives - 1;
		spaceshipActive = false;
		spawnTimer = 3.0f;
	}
	if (msg.type == POWERUPACTIVATED)
	{
		if (PlasmaBulletActive == true)
		{ 
			powerUpDisplayTimer = 2.0f;
		}
		
	}
}
