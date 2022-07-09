#include "Bullet.h"

bool Bullet::canGenerate = true;
vector<AEntity*>* Bullet::targets;
Bullet::Bullet(Boundary boundaries)
{
	limit = boundaries;
	Height = 1;
	Width = 1;
	Xspeed = 1;
	Yspeed = 1;
	canDestroy = false;
	canGenerate = false;
	thread letBulletGenerateAgain([=]() {
		Sleep(PauseTime);
		Bullet::canGenerate = true;
	});
	letBulletGenerateAgain.detach();
	AUDIO.play("shoot");
}

void Bullet::draw(int x = -10, int y = -10)
{
	if (x == -10 && y == -10) {
		x = X;
		y = Y;
	}
	Helpers::SetCursorPosition(y, x);
	cout << "|";
}

void Bullet::movementController()
{
	if (Y > limit.Top && Y - Yspeed > limit.Top) {
		erase(X, Y);
		Y-=Yspeed;
		draw(X, Y);
	}
	else {
		canDestroy = true;
	}
}

void Bullet::collisionController()
{
	for (int i = 0; i < (*targets).size(); i++) {
		if (cornerXYCollision(X, Y, (*targets)[i])) {
			if (((Enemy*)(*targets)[i])->lives != 0) {
				((Enemy*)(*targets)[i])->lives--;
				(*targets)[i]->draw();
				AUDIO.play("bulletHit");
			}
			else {
				(*targets)[i]->erase();
				delete (*targets)[i];
				(*targets).erase((*targets).begin() + i);
				AUDIO.play("explosion");
				Environment::Score += 3;
				Environment::UpdateScore = true;
			}
			canDestroy = true;
			continue;
		}
	}
}

