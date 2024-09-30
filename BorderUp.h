#pragma once
#include "ObjectManager.h"

//Class will upon create a Upper Border to Level, which Rocks will bounce off whilst a Spaceship Object will Explode
//w16015479

class ObjectManager; //Uses ObjectManager
class BorderUp : public GameObject
{
private:
	//BorderUp Shape
	Rectangle2D borderUp;

public:
	BorderUp(); //Constructor
	~BorderUp(); //Destructor
	void Initialise(); //Initialises and creates BorderUp object
	IShape2D* GetShape(); //Returns BorderUp's collision shape
	void ProcessCollision(GameObject* pNewObject); //Will process a collision upon Object Intersection
	void Render(); //Renders Border into level
	void Update(float frameTime); //Processes BorderUp's actions
};
