#include "GameOverScreen.h"
string GameOverScreen::GameOverText = "GameOver!";
void GameOverScreen::Start() {
	SaveScore();
	boundary.Top = 1;
	boundary.Bottom = WinHeight;
	boundary.Left = 1;
	boundary.Right = WinWidth;
	NStars = 500;
	InitStars();
}
void GameOverScreen::InitStars()
{
	AEntity* str;
	for (int i = 0; i < NStars; i++) {
		str = new Star(boundary);
		str->X = rand() % WinWidth;
		str->Y = rand() % WinHeight;
		stars.push_back(str);
		str->draw();
	}
}
void GameOverScreen::SaveScore()
{
	if (Environment::Score > Environment::HeighestScore) {
		Environment::file.open(Environment::FileName, ios::out | ios::trunc);
		Environment::file << Environment::Score;
		Environment::file.close();
	}
}
void GameOverScreen::Renderer() {
	while (1)
	{
		for (int i = 0; i < stars.size(); i++) {
			if (((Star*)stars[i])->canDestroy) {
				stars[i]->erase();
				delete stars[i];
				stars.erase(stars.begin() + i);
				continue;
			}
			else {
				((Star*)stars[i])->movementController();
			}
		}
		string text = GameOverText;
		Helpers::SetCursorPosition((WinHeight / 2) + 1, ((WinWidth / 2) - (text.length() / 2)));
		Helpers::SetColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		cout << text;
		if (stars.size() == 0) break;
		Sleep(FrameRate);
	}
	Helpers::Pause();
}
void GameOverScreen::End() {
	stars.clear();
	Helpers::SetColor(Environment::TxtWhiteColor);
	system("cls");
}





