#pragma once
#include "GameObject.h"
#include "ObjectManager.h"

//Class will spawn a power up that can be collected by the player to make the levelk easier to complete
//Andrew Cobb
//w16015479

class ObjectManager; //Uses ObjectManager
class PowerUp : public GameObject
{
public:
	//Pointer to ObjectManager
	ObjectManager* pObjectManager;

	//Collision shape of PowerUp
	Circle2D collisionShape;


public:
	PowerUp(ObjectManager* pOM); //Constructor
	~PowerUp(); //Destructor
	void Initialise(); //Initialises and creates Power Up object
	IShape2D* GetShape(); //Returns Collision Shape of Power Up
	void ProcessCollision(GameObject* pNewObject); //Processes collision between Power Up and Spaceship 
	void Update(float frameTime); // Processes Power Up's actions
};

