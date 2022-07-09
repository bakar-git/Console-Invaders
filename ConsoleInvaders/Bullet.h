#pragma once
#include "Enemy.h"
#include "AEntity.h"
#include "AMovable.h"
#include "ACollidable.h"
class Bullet : public AEntity, public AMovable, public ACollidable
{
public:
	static vector<AEntity*>* targets; // targets of bullet
	Bullet(Boundary boundaries);
	void draw(int x, int y);
	void movementController();
	void collisionController();
	bool canDestroy;
	static bool canGenerate;
	static const int PauseTime = 300; // in milli sec
	~Bullet() {
		(*targets).clear();
		delete targets;
	}
};

