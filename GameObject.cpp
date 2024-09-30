#include "GameObject.h"

//Andrew Cobb
//w16015479
//GameObject Class - KF6017 Software Architecture for Games

//Constructor
GameObject::GameObject()
{
	seeThrough = 0; //Sets Game Object to not be seeThrough unless seeThrough value is higher than 0
}

//Destructor
GameObject::~GameObject()
{
	
}

//Loads Image of Specified GameObject
void GameObject::LoadImage(const wchar_t* filename)
{
	image = MyDrawEngine::GetInstance()->LoadPicture(filename);

}

//Checks if GameObject is Collidable, if so returns bCollidable = true
bool GameObject::IsCollidable()
{
	if (bCollidable)
	{
		return bCollidable;
	}
}

void GameObject::Render()
{
	if (active == true)
	{
		MyDrawEngine* pDE = MyDrawEngine::GetInstance();
		pDE->DrawAt(position, image, 1.0f, angle, seeThrough);
	}

}

//Creates Collision at set position
void GameObject::Update(float frameTime)
{
	collisionShape.PlaceAt(position, 30);
}

//Returns type of Game Object
wchar_t* GameObject::GetType()
{
	return type;
}

//Returns position of Game Object
Vector2D GameObject::GetPosition()
{
	return position;
}

//Returns if GameObject is active
bool GameObject::IsActive()
{
	return active;
}