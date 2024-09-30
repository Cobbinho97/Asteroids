#pragma once
#include "GameObject.h"

//Class will upon processing collisions, send a Explosion Object to play an Explosion Image
//w16015479

class Explosion : public GameObject
{
private:
	//Explosion's Properties
	PictureIndex images[8]; //Array of 8 Different Rock Images
	Vector2D position;
	Circle2D collisionShape;
	float currentImage;

public:
	Explosion(); //Constructor
	~Explosion(); //Destructor
	void Initialise(Vector2D position); //Initialises and creates Explosion object
	IShape2D* GetShape(); //Returns Explosion's collision shape
	void ProcessCollision(GameObject* pNewObject); //Will Create a Explosion Image when a Collision occurs
	void Update(float frameTime); //Processes Explosion's actions
	void Render(); //Renders Explosion Object, displaying Explosion Image
};