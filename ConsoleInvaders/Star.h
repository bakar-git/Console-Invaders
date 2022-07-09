#pragma once
#include "AEntity.h"
#include "AMovable.h"
class Star : public AEntity, public AMovable
{
public:
	Star(Boundary boundaries);
	void draw(int x, int y);
	void movementController();
	bool canDestroy;
};

