#pragma once
#include "ObjectManager.h"

//Class will upon create a Right Border to Level, which Rocks will bounce off whilst a Spaceship Object will Explode
//w16015479

class ObjectManager; //Uses ObjectManager
class BorderRight : public GameObject
{
private:
	//BorderRight Shape
	Rectangle2D borderRight;

public:
	BorderRight(); //Constructor
	~BorderRight(); //Destructor
	void Initialise(); //Initialises and creates BorderRight object
	IShape2D* GetShape(); //Returns BorderRight's collision shape
	void ProcessCollision(GameObject* pNewObject); //Will process a collision upon Object Intersection
	void Render(); //Renders Border into level
	void Update(float frameTime); //Processes BorderRight's actions
};
