#include "ObjectManager.h"
//Andrew Cobb
//w16015479
//ObjectManager Class - KF6017 Software Architecture for Games

//Constructor
ObjectManager::ObjectManager()
{

}

//Destructor
ObjectManager::~ObjectManager()
{
	DeleteAll();
}

//Adds new Object to ObjectList
void ObjectManager::AddObject(GameObject* pNewObject) //Adds Object to ObjectList
{
	pNewObjectList.push_back(pNewObject);
}

//Updates All New Objects currently in ObjectList
void ObjectManager::UpdateAll(float frameTime) 
{
	for (GameObject* pNewObject : pNewObjectList)
	{
		if(pNewObject)
		pNewObject->Update(frameTime);
	}
}

// Checks for Collision of all Shapes, Processing collision of it occurs depending on Object
void ObjectManager::CheckAllCollisions()	 
{
	for (it1 = pNewObjectList.begin(); it1 != pNewObjectList.end(); it1++)
	{
		for (it2 = std::next(it1); it2 != pNewObjectList.end(); it2++)
		{

			if ((*it1) && (*it2) && ((*it1)->IsCollidable()&&(*it2)->IsCollidable()&&(*it1)->IsActive()&& (*it2)->IsActive() && (*it1)->GetShape()->Intersects(*(*it2)->GetShape())))
			{
				(*it1)->ProcessCollision((*it2));
				(*it2)->ProcessCollision((*it1));
			}
		}
	}
}

//Renders All Objects in ObjectList
void ObjectManager::RenderAll() 
{
	for (GameObject* pNewObject : pNewObjectList)
	{
		if(pNewObject)
		pNewObject->Render();
	}
}

// Deletes all objects in ObjectList and sets to a null pointer
void ObjectManager::DeleteAll() 
{
	for (GameObject* &pNewObject : pNewObjectList)
	{
			delete pNewObject;
			pNewObject = nullptr;		
	}
	pNewObjectList.clear();
}

//Deletes all inactive objects in ObjectList and sets to a null pointer
void ObjectManager::DeleteInactive() 
{
	for (GameObject* &pNewObject : pNewObjectList)
	{
		if (pNewObject)
			if (pNewObject->IsActive() == false)
			{
				delete pNewObject;
				pNewObject = nullptr;

			}
	}
}