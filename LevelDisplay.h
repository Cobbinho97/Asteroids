#pragma once
#include "GameObject.h"
#include "mydrawengine.h"
#include "ObjectManager.h"

//Class will display Space Background for Game
//Andrew Cobb
//w16015479
class ObjectManager; //Uses ObjectManager

class LevelDisplay : public GameObject
{
private:

	//Space Background Image
	PictureIndex space;

public:
	LevelDisplay(); //Constructor
	~LevelDisplay(); //Destructor
	void Initialise(); //Initialises and creates LevelDisplay object
	void Render(); //Renders LevelDisplay Object, creating Space Background Image for Game
	void Update(float frameTime); //Processes LevelDisplay's actions
	IShape2D* GetShape(); //Returns LevelDisplay's collision shape
	void ProcessCollision(GameObject* pNewObject); //Processes Collision between Level Display and other objects
};

