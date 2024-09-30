#pragma once
#include "Explosion.h"
#include "mysoundengine.h"
#include "ObjectManager.h"
#include "Bullet.h"
#include "PlasmaBullet.h"

//Class will create the asteroids that will spawn into the level to be destroyed by the player
//Andrew Cobb
//w16015479

class ObjectManager; //Uses ObjectManager
class LevelManager;
class Rock : public GameObject
{
private:
	//Rocks Health
	int rockHealth;  

	//Rock Damage timer
	float damageTimer;

	//Pointers
	ObjectManager* pObjectManager;
	SoundIndex explosionSound;
	Explosion* pExp;
	LevelManager* pLevelManager;

public:
	Rock(ObjectManager* pOM , LevelManager* pLM); //Constructor
	~Rock(); //Destructor
	void Initialise(); //Creates Rock and initialises into level
	IShape2D* GetShape();  //Gets Collision Shape of Rock
	void ProcessCollision(GameObject* pNewObject); //Processes Collision betwen Spaceship and other Objects
	void Update(float frameTime); //Processes Rock actions
};

