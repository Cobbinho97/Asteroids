#pragma once
#include "errortype.h"
#include "vector2D.h"
#include "mydrawengine.h"
#include "gametimer.h"
#include "myinputs.h"
#include "Shapes.h"
#include <typeinfo>

//Class allows for inheritance. Each GameObject inherits from this class - (Spaceship, Rock, Bullet, Borders, PowerUp)
//Andrew Cobb
//w16015479
class GameObject
{
	private:
		float frameTime;
		GameTimer gameTimer;

		//Create protected variables, allowing for access for derived classes
	protected:
		//GameObject Variables
		PictureIndex image;
		Vector2D position;
		Vector2D velocity;
		Vector2D size;
		Circle2D collisionShape; 
		float angle;
		void LoadImage(const wchar_t* filename);
		bool active;
		wchar_t type[16];
		bool bCollidable;  
		float seeThrough;

	public: 
			GameObject(); //Constructor
			~GameObject(); //Destructor
			virtual void Update(float frameTime) = 0;  //Processes GameObject's actions, use of Virtual allows for other classes to inherit
			virtual IShape2D* GetShape() = 0;//Returns Object's Collision Shape, use of Virtual allows for other classes to inherit
			void virtual ProcessCollision(GameObject* pNewObject)= 0; //Returns Object's Collision, use of Virtual allows for other classes to inherit
			virtual wchar_t* GetType(); //Returns Object Type, use of Virtual allows for other classes to inherit
			Vector2D GetPosition(); // Returns Objects Position
			bool IsCollidable();  //Checks if a GameObject has been made collidable
			bool IsActive(); //Returns if a GameObject is Active
			virtual void Render(); //Renders GameObject, use of Virtual allows for other classes to inherit
};

