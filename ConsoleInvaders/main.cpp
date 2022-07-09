#include "headers.h"
#include "WelcomeScreen.h"
#include "GameOverScreen.h"
#include "Level1.h"
int main(int argc, char* argv[])
{
	// argv[0] gives the location of current executable i.e "D:/path/to/project/debug/executable.exe";
	string audioDirectory = Helpers::GetExePath(argv[0]) + "\\sounds\\";
	Environment::Initialize(audioDirectory);
	WelcomeScreen wls;
	wls.Initialize();
	Level1 lvl1;
	lvl1.Initialize();
	GameOverScreen gmo;
	gmo.Initialize();
	return 0;
}