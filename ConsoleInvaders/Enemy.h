#pragma once
#include "Level1.h"
#include "AEntity.h"
#include "AMovable.h"
#include "ACollidable.h"
class Enemy : public AEntity, public AMovable
{
private:
	const static int TotalLives = 2;
	const static int MoveAfter = 1000; // milliseconds
	const static WORD Clr1 = FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY;
	const static WORD Clr2 = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY;
	const static WORD Clr3 = FOREGROUND_RED;
public:
	static void TimedMovementInitializer();
	static bool canMove;
	int lives;
	Enemy(Boundary boundaries);
	void draw(int x, int y);
	void movementController();
};

