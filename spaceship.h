#pragma once
#include "Bullet.h"
#include "PlasmaBullet.h"
#include "Explosion.h"
#include "ObjectManager.h"
#include "mysoundengine.h"

//Spaceship will be the player class, creating the object that the player will control in the game
//Andrew Cobb
//w16015479
class ObjectManager; //Uses ObjectManager
class LevelManager;
class Spaceship : public GameObject //Spaceship is type of GameObject
{

	private:
	//Spaceship Properties
	Vector2D velocity; 
	Vector2D acceleration;
	Vector2D shipFront;
	bool powerUp;
	int health;

	//Spaceship Timers
	float shootDelayTimer;   
	float noDamageTimer;
	float powerUpTimer;
	float shootDelay;

	//Pointers
	ObjectManager* pObjectManager; 
	LevelManager* pLevelManager;
	Bullet* pBullet;
	PlasmaBullet* plasBullet;
	Explosion* pExp; 

protected:
	
	//Sound variables for Spaceship
	SoundIndex shootSound;
	SoundIndex explosionSound;
	SoundIndex boostSound;
	SoundIndex music;


	public:

	Spaceship(ObjectManager* pOM, LevelManager* pLM); //Constructor
	~Spaceship(); //Destructor
	void Initialise(); //Creates Spaceship and initialises into level
	IShape2D* GetShape();  //Gets Collision Shape of Spaceship
	void ProcessCollision(GameObject* pNewObject);  //Processes Collision betwen Spaceship and other Objects
	void Update(float frameTime); //Processes Spaceship actions
};
