#pragma once
#include "ObjectManager.h"

//Class will upon create a Left Border to Level, which Rocks will bounce off whilst a Spaceship Object will Explode
//w16015479

class ObjectManager; //Uses ObjectManager
class BorderLeft : public GameObject
{
private:
	//BorderLeft Shape
	Rectangle2D borderLeft;

public:
	BorderLeft(); //Constructor
	~BorderLeft(); //Destructor
	void Initialise(); //Initialises and creates BorderLeft object
	IShape2D* GetShape(); //Returns BorderLeft's collision shape
	void ProcessCollision(GameObject* pNewObject); //Will process a collision upon Object Intersection
	void Render(); //Renders Border into level
	void Update(float frameTime); //Processes BorderLeft's actions
};
