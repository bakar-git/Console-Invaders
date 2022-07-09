#pragma once
#include "Boundary.h"
class AMovable // Every movable object will inherit this
{
public:
	Boundary limit; // limit which movable object cant pass
	int Xspeed; // movement speed in X
	int Yspeed; // movement speed in Y
	virtual void movementController() = 0;
};

