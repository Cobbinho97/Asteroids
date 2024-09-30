#pragma once
#include "vector2D.h"
#include "gametimer.h"
#include "GameObject.h"
#include "ObjectManager.h"
#include "mysoundengine.h"

//Creates Level Manager to creates levels, contains messaging system to send messages between classes
//Andrew Cobb
//w16015479
enum MessageType{ROCKWASDESTROYED, SPACESHIPWASDESTROYED, POWERUPACTIVATED}; //Different messages sent between classes
class Message
	{
	public:
		//Messaging System Properties
		MessageType type;
		Vector2D position;
		GameObject* pSource;
	};
class LevelManager : public GameObject
{
private:
	//LevelManager Properties
	int score;
	int level;
	int numAsteroids;
	int lives;
	//LevelManager Timers
	float spawnTimer;
	float endoflevelTimer;
	float powerUpDisplayTimer;
	//LevelManager Check Active Variables
	bool spaceshipActive;
	bool GameOverActive;
	bool PlasmaBulletActive;
	bool powerUpActive;
	bool LevelCompletedActive;

	//Propeties to display Images or play Sound Files
	PictureIndex Images;
	SoundIndex music;
	Circle2D shape;

	//Pointers
	ObjectManager* pObjectManager;
	PowerUp* powerUp;
	LevelDisplay* pLevelDisplay;
	Spaceship* ship_1;
	Rock* rock_1;
	BorderLeft* bordL;
	BorderRight* bordR;
	BorderUp* bordU;
	BorderDown* bordD;

	GameTimer gt;

public:

	LevelManager(ObjectManager* pOM);
	~LevelManager();
	void Initialise();
	void Update(float frameTime);
	IShape2D* GetShape();
	void ProcessCollision(GameObject* pNewObject) ;
	void Render();
	void EndGame();
	void HandleMessage(Message msg);
};