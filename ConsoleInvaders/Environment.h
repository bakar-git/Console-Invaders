#pragma once
#include "headers.h"
#include "Helpers.h"
#include "Audio.h"
class Environment
{
public:
	static int Score; // score inside game
	static bool UpdateScore; // tells renderer to update score
	static fstream file;
	static int HeighestScore;
	static string FileName;
	static Audio audioManager;
	static WORD TxtWhiteColor, BgWhiteColor;
	static int
		Height, // Height(Number of rows) of Console Window
		Width; // Width(Number of columns) of Console Window
	static void Initialize(string path);
};
#ifndef AUDIO
#define AUDIO Environment::audioManager
#define WinHeight Environment::Height
#define WinWidth Environment::Width
#endif // !AUDIO