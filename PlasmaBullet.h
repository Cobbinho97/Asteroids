#pragma once
#include "GameObject.h"

//Class will create the power up's plasma bullet for a set amount of time when player activates power up
//Andrew Cobb
//w16015479

class PlasmaBullet : public GameObject
{
private:

	//Plasma Bullet's Properties
	Vector2D velocity;
	PictureIndex plasmabullet; 
	float bulletSpeed; 
	bool plasmaActive;

	//Timer for if Plasma Bullet is active
	float actTimer;


public:

	PlasmaBullet(); //Constructor
	~PlasmaBullet(); //Destructor
	void Initialise(Vector2D startPosition, float sAngle, Vector2D launcherVelocity); //Initialises and creates Plasma Bullet object
	IShape2D* GetShape(); //Gets collision shape of Plasma Bullet
	void ProcessCollision(GameObject* pNewObject); //Processes collision between Plasma Bullet and Spaceship
	void Update(float frameTime); // Processes Plasma Bullet's actions
	void Render(); //Renders Plasma Bullet into level

};