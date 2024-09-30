#include "GameOverScreen.h"
#include "LevelManager.h"

//Andrew Cobb
//w16015479
//GameOverScreen Class - KF6017 Software Architecture for Games

//Constructor, Implementation of LevelManager Pointer
GameOverScreen::GameOverScreen(LevelManager* pLM)
{
	bCollidable = false;
	active = false;
	pLevelManager = pLM;
}

//Destructor
GameOverScreen::~GameOverScreen()
{
}

void GameOverScreen::Initialise()
{

}

void GameOverScreen::Render()
{
}

void GameOverScreen::Update(float frameTime)
{
	MyDrawEngine* pDE = MyDrawEngine::GetInstance();

	position.set(position + (velocity * frameTime));
}

//Sets Collision for Game Over Screen to false;
IShape2D* GameOverScreen::GetShape()
{
	return &collisionShape;
}

void GameOverScreen::ProcessCollision(GameObject* pNewObject)
{

}
