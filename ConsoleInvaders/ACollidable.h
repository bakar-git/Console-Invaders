#pragma once
#include "AEntity.h"
class ACollidable
{
public:
	static bool cornerXYCollision(int targetX, int targetY, AEntity* elem) { // is targetX and targetY coordinates are inside "elem" boundaries
		int leftBoundary = elem->X;
		int rightBoundary = elem->X + elem->Width - 1;
		int topBoundary = elem->Y;
		int bottomBoundary = elem->Y + elem->Height - 1;
		if (
			(targetX >= leftBoundary && targetX <= rightBoundary) &&
			(targetY>= topBoundary && targetY<= bottomBoundary)
			) return true;
		return false;
	}
	virtual void collisionController() = 0;
};

