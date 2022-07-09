#pragma once
#include "headers.h"
#include "ALevel.h"
#include "AEntity.h"
#include "Enemy.h"
#include "Player.h"
#include "Boundary.h"
#include "Environment.h"
class Level1 : public ALevel
{
public:
	static bool EnemiesReachedBottom;
private:
	const int FrameRate = 60;
	const int NEnemies = 24;
	const int XMargin = 3;
	const int YMargin = 3;
	Boundary boundary;
	AEntity* player;
	vector<AEntity*> enemies;
	void Start();
	void Renderer();
	void End();
	void PrintBoundary();
	void initPlayer();
	void initEnemies();
	void DrawScoreBoard();
	void UpdateScore();
};

