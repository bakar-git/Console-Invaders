#include "Level1.h"
bool Level1::EnemiesReachedBottom = false;
void Level1::Start()
{
	boundary.Top = YMargin;
	boundary.Bottom = WinHeight - YMargin;
	boundary.Left = XMargin;
	boundary.Right = WinWidth - XMargin + 1;
	PrintBoundary();
	initPlayer();
	initEnemies();
	Bullet::targets = &enemies;
}

void Level1::Renderer()
{
	while(1){
		if (Enemy::canMove) {
			for (AEntity* elem : enemies) ((Enemy*)elem)->movementController();
			Enemy::canMove = false;
		}
		((Player*)player)->movementController();
		((Player*)player)->collisionController();
		if (Environment::UpdateScore) DrawScoreBoard();
		if (((Player*)player)->dead) break;
		if (GetAsyncKeyState(VK_ESCAPE)) break; // if escape key is pressed
		if (enemies.size() == 0) break; // if all enemies are dead
		if (EnemiesReachedBottom) break; // if any enemy passes bottom boundary
		Sleep(FrameRate);
	}
	AUDIO.play("game-over");
	Sleep(2000);
}

void Level1::End()
{
	delete player;
	enemies.clear();
	Helpers::SetColor(Environment::TxtWhiteColor);
	system("cls");
}
void Level1::initPlayer()
{
	player = new Player(boundary);
	player->X = boundary.Left + 1;
	player->Y = boundary.Bottom - player->Height - 1;
	player->draw();
}

void Level1::PrintBoundary()
{
	Helpers::SetColor(Environment::TxtWhiteColor);
	// Top Boundary
	Helpers::SetCursorPosition(YMargin, XMargin);
	for (int i = 1; i <= WinWidth-XMargin-2; i++) cout << "-";
	// Bottom Boundary
	Helpers::SetCursorPosition(WinHeight-1-YMargin, XMargin);
	for (int i = 1; i <= WinWidth - XMargin - 2; i++) cout << "-";
	// Left Boundary
	for (int i = YMargin; i <= WinHeight - 1 - YMargin; i++) {
		Helpers::SetCursorPosition(i, XMargin);
		cout << "|";
	}
	// Right Boundary
	for (int i = YMargin; i <= WinHeight - 1 - YMargin; i++) {
		Helpers::SetCursorPosition(i, WinWidth -XMargin);
		cout << "|";
	}
}



void Level1::initEnemies()
{
	int enemyTotalWidth = 13;
	int nEnemyCanBePlaced = (boundary.Right - boundary.Left) / enemyTotalWidth; // 12 is enemy width and 1 is space between them
	int nSpaces = ((boundary.Right - boundary.Left) - (nEnemyCanBePlaced * enemyTotalWidth))/2; // space to leave
	int nEnemyPlaced = 0;
	int placedEnemyX = boundary.Left + 1 + nSpaces;
	int placedEnemyY = boundary.Top + 1;
	AEntity* enemy;
	for (int i = 1; i <= NEnemies; i++)
	{
		enemy = new Enemy(boundary);
		enemy->X = placedEnemyX;
		enemy->Y = placedEnemyY;
		enemies.push_back(enemy);
		nEnemyPlaced++;
		if (nEnemyPlaced % nEnemyCanBePlaced == 0) {
			placedEnemyX = boundary.Left + 1 + nSpaces; // reset X placement
			placedEnemyY += 6; // increment in Y placement
		}
		else
		{
			placedEnemyX += enemyTotalWidth;
		}
		enemy->draw();
	}
    Enemy::TimedMovementInitializer();
}

void Level1::DrawScoreBoard()
{
	Helpers::SetColor(Environment::TxtWhiteColor);
	Helpers::SetCursorPosition(2, 1);
	for (int i = 0; i < WinWidth - 2; i++) cout << " ";
	string s = "Score : " + to_string(Environment::Score);
	string hs = "Heighest Score : " + to_string(Environment::HeighestScore);
	int XCenter = WinWidth / 2;
	Helpers::SetCursorPosition(2, (XCenter / 2) - s.size());
	cout << s;
	Helpers::SetCursorPosition(2, XCenter + (XCenter / 2) - hs.size());
	cout << hs;
	Environment::UpdateScore = false;
}
