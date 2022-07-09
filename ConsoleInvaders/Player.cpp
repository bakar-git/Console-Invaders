#include "Player.h"

Player::Player(Boundary boundaries)
{
	dead = false;
	limit = boundaries;
	Height = 4;
	Width = 12;
	Xspeed = 2;
	Yspeed = 1;
}



void Player::draw(int x = -10, int y = -10)
{
	if (x == -10 && y == -10) {
		x = X;
		y = Y;
	}
	Helpers::SetCursorPosition(y, x);
	cout << R"(    / \)";
	Helpers::SetCursorPosition(y + 1, x);
	cout << R"(   {###})";
	Helpers::SetCursorPosition(y + 2, x);
	cout << R"( //|/|\|\\)";
	Helpers::SetCursorPosition(y + 3, x);
	cout << R"(///_||||_\\\)";
}

void Player::movementController()
{
	if (GetAsyncKeyState(VK_LEFT) && X > limit.Left && X - Xspeed > limit.Left) {
		erase(X, Y);
		X -= Xspeed;
		draw(X, Y);
	}
	if (GetAsyncKeyState(VK_RIGHT) && X < limit.Right && X + Xspeed < limit.Right - Width) {
		erase(X, Y);
		X+=Xspeed;
		draw(X, Y);
	}
	if (GetAsyncKeyState(VK_UP) && Y > limit.Top && Y - Yspeed > limit.Top) {
		erase(X, Y);
		Y-=Yspeed;
		draw(X, Y);
	}
	if (GetAsyncKeyState(VK_DOWN) && Y < limit.Bottom && Y + Yspeed < limit.Bottom - Height) {
		erase(X, Y);
		Y+=Yspeed;
		draw(X, Y);
	}
	if (GetAsyncKeyState(65) && Bullet::canGenerate) { // A key
		AEntity* bult = new Bullet(limit);
		bullets.push_back(bult);
		bult->X = X + 5;
		bult->Y = Y;
		bult->draw();
	}
	for (int i = 0; i < bullets.size(); i++) {
		if (((Bullet*)bullets[i])->canDestroy) {
			bullets[i]->erase();
			delete bullets[i];
			bullets.erase(bullets.begin() + i);
			continue;
		}
		else {
			((Bullet*)bullets[i])->movementController();
			((Bullet*)bullets[i])->collisionController();
		}
	}
}

void Player::collisionController()
{
	vector<AEntity*>* targets = Bullet::targets;
	for (int i = 0; i < (*targets).size(); i++) {
		if (
			cornerXYCollision(X, Y + Height - 1, (*targets)[i]) || 
			cornerXYCollision(X+Width-1, Y + Height - 1, (*targets)[i]) || 
			cornerXYCollision(X+1, Y + Height - 2, (*targets)[i]) || 
			cornerXYCollision(X+Width-2, Y + Height - 2, (*targets)[i]) || 
			cornerXYCollision(X + 3, Y + Height - 3, (*targets)[i]) || 
			cornerXYCollision(X + Width - 4, Y + Height - 3, (*targets)[i]) ||
			cornerXYCollision(X + 5, Y, (*targets)[i]) ||
			cornerXYCollision(X + Width - 6, Y, (*targets)[i])
			) {
			dead = true;
			AUDIO.play("explosion");
			
			break;
		}
	}
}


