#pragma once
#include "GameObject.h"

//Class will upon processing vullets, will play Bullet Images upon User Input
//w16015479

class Bullet : public GameObject
{
private:

	//Bullet's Properties
	Vector2D velocity;
	PictureIndex bullet;
	float bulletSpeed; 
	float actTimer;

public:

	Bullet(); //Constructor
	~Bullet(); //Destructor
	void Initialise(Vector2D startPosition, float sAngle, Vector2D launcherVelocity); //Initialises and creates Bullet object
	IShape2D* GetShape(); //Returns collision shape of Bullet
	void ProcessCollision(GameObject* pNewObject); //Will Create a Explosion when Bullet Object collides with a Rock Object
	void Update(float frameTime); //Processes Bullet's actions
	void Render(); //Renders Bullet Object, displaying Bullet Image upon User Input
};

