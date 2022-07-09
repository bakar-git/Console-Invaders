#pragma once
#include "AMovable.h" 
#include "AEntity.h" 
#include "ACollidable.h" 
#include "Bullet.h" 
class Player : public AEntity, public AMovable, public ACollidable
{
public:
	bool dead;
	vector<AEntity*> bullets;
	Player(Boundary boundaries);
	void draw(int x, int y);
	void movementController();
	void collisionController();
};

