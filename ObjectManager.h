#pragma once
#include <list>
#include "spaceship.h"
#include "rock.h"
#include "BorderUp.h"
#include "BorderDown.h"
#include "BorderLeft.h"
#include "BorderRight.h"
#include "LevelDisplay.h"
#include "GameOverScreen.h"
#include "GameOverScreen.h"
#include "PowerUp.h"
#include "PlasmaBullet.h"
#include <algorithm>

//ObjectManager manages assing and removing from ObjectList , also checking collisions between Objects
//Andrew Cobb
//w16015479
class GameObject;
class ObjectManager
{
private :

	//Creates list for Objects
	std::list<GameObject*> pNewObjectList;
	GameTimer gt;
	//Creates iterators to read through beginning and end of list
	std::list<GameObject*>::iterator it1; 
	std::list<GameObject*>::iterator it2; 

public:

	ObjectManager(); //Constructor
	~ObjectManager(); //Destructor
	void AddObject(GameObject* pNewObject); //Adds object to ObjectList
	void UpdateAll(float frameTime); //Updates all Objects based upon frameTime
	void CheckAllCollisions(); //Checks Active Intersecting Shapes and processes a Collision if there is a Intersection
	void RenderAll(); //Renders all Objects
	void DeleteAll(); //Deletes all Objects
	void DeleteInactive(); //Deletes all objects that have been made inactive
};

