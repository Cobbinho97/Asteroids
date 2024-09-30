#pragma once
#include "GameObject.h"
#include "mydrawengine.h"
#include "ObjectManager.h"

//Class will display Game Over Background for Game
//Andrew Cobb
//w16015479
class ObjectManager; //Uses ObjectManager
class GameOverScreen : public GameObject
{
private:

	//Space Background Image
	PictureIndex space;
	//Pointer to LevelManager
	LevelManager* pLevelManager;

public:
	GameOverScreen(LevelManager* pLM); //Constructor
	~GameOverScreen(); //Destructor
	void Initialise(); //Initialises and creates GameOverScreen object
	void Render(); //Renders GameOverScreen Object, creating Game Over Background Image for Game
	void Update(float frameTime); //Processes GameOverScreen's actions
	IShape2D* GetShape(); //Returns GameOverScreen's collision shape
	void ProcessCollision(GameObject* pNewObject); //Processes Collision between GameOverScreen and other objects
};