#pragma once
#include"headers.h"

class Helpers
{
public:
	static void SetCursorPosition(int row, int col); // Set the cursor position where next character will be printed
	static void GetConsoleDimensions(int& row, int& col); // get the height(number of rows) and width(number of colummns) of console window
	static void SetColor(WORD colors); // sets the color of next characters to be printed
	static string GetExePath(string x); // return director path when given executable path i.e "D:/path/to/project/debug/executable.exe" returns "D:/path/to/project/debug";
	static void RemoveScrollBar(); // removes the scrollbar from current window i.e Console Window
	static void MaximizeWindow(); // maximizes the window
	static void Pause(); // pauses the game unless space is pressed
private:
	static HANDLE hOut;
	static CONSOLE_SCREEN_BUFFER_INFO scrBufferInfo;
};
