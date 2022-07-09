#pragma once
#include "headers.h"
#include "Star.h"
#include "ALevel.h"
#include "AEntity.h"
#include "Environment.h"
class GameOverScreen : public ALevel
{
public:
	static string GameOverText;
private:
	Boundary boundary;
	const int FrameRate = 100;
	int NStars; // number of stars
	vector<AEntity*> stars;
	void Start();
	void Renderer();
	void End();
	void InitStars();
	void SaveScore();
};

