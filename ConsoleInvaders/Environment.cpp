#include "Environment.h"
int Environment::Height = 0, Environment::Width = 0;
WORD Environment::TxtWhiteColor = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY;
WORD Environment::BgWhiteColor = BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY;
string Environment::FileName = "score.txt";
int Environment::Score = 0;
bool Environment::UpdateScore = true;
int Environment::HeighestScore = 0;
Audio Environment::audioManager;
fstream Environment::file;
void Environment::Initialize(string path) {
	system("cls");
	// reading score.txt file to get highest score if any
	file.open(FileName, ios::in);
	string tmp;
	file >> tmp;
	if(tmp != "") HeighestScore = stoi(tmp);
	file.close();
	// setting basepath of audio manager
	Environment::audioManager.BasePath = path;
	Helpers::MaximizeWindow();
	Helpers::RemoveScrollBar();
	Helpers::GetConsoleDimensions(Height, Width); // storing height and width of window in 
												//Height and Width static data member of Environment class
}