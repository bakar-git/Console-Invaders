#include "Enemy.h"
bool Enemy::canMove = false;
void Enemy::TimedMovementInitializer()
{
	thread letEnemiesMove([=]() {
		while (1)
		{
			Sleep(MoveAfter);
			canMove = true;
		}
		});
	letEnemiesMove.detach();
}
Enemy::Enemy(Boundary boundaries)
{
	limit = boundaries;
	Height = 5;
	Width = 12;
	lives = TotalLives;
	Yspeed = 1;
}

void Enemy::draw(int x = -10, int y = -10)
{
	if (x == -10 && y == -10) {
		x = X;
		y = Y;
	}
	switch (lives)
	{
	case 2:
		Helpers::SetColor(Clr1);
		break;
	case 1:
		Helpers::SetColor(Clr2);
		break;
	case 0:
		Helpers::SetColor(Clr3);
		break;
	}
	Helpers::SetCursorPosition(y, x);
	cout << R"(************)";
	Helpers::SetCursorPosition(y + 1, x);
	cout << R"(* <.>  <.> *)";
	Helpers::SetCursorPosition(y + 2, x);
	cout << R"(*    /\    *)";
	Helpers::SetCursorPosition(y + 3, x);
	cout << R"(*   WWWW   *)";
	Helpers::SetCursorPosition(y + 4, x);
	cout << R"(************)";
}

void Enemy::movementController()
{
	if (Y < limit.Bottom && Y + Yspeed < limit.Bottom - Height) {
		erase(X, Y);
		Y += Yspeed;
		draw(X, Y);
	}
	else {
		Level1::EnemiesReachedBottom = true;
	}
}
