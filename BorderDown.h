#pragma once
#include "ObjectManager.h"

//Class will upon create a Lower Border to Level, which Rocks will bounce off whilst a Spaceship Object will Explode
//w16015479

class ObjectManager; //Uses ObjectManager
class BorderDown : public GameObject
{
private:
	//BorderDown Shape
	Rectangle2D borderDown;

public:
	BorderDown(); //Constructor
	~BorderDown(); //Destructor
	void Initialise(); //Initialises and creates BorderDown object
	IShape2D* GetShape(); //Returns BorderDown's collision shape
	void ProcessCollision(GameObject* pNewObject); //Will process a collision upon Object Intersection
	void Render(); //Renders Border into level
	void Update(float frameTime); //Processes BorderDown's actions
};

