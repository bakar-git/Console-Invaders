#include "Helpers.h"

HANDLE Helpers::hOut = GetStdHandle(STD_OUTPUT_HANDLE);
CONSOLE_SCREEN_BUFFER_INFO Helpers::scrBufferInfo;
void Helpers::SetCursorPosition(int row, int col) {
	COORD coord;
	coord.X = col;
	coord.Y = row;
	SetConsoleCursorPosition(hOut, coord);
}
string Helpers::GetExePath(string x)
{
	std::string f = x;
	return f.substr(0, f.find_last_of("\\/"));
}
void Helpers::GetConsoleDimensions(int& row, int& col) {
	GetConsoleScreenBufferInfo(hOut, &scrBufferInfo);
	col = scrBufferInfo.srWindow.Right - scrBufferInfo.srWindow.Left + 1;
	row = scrBufferInfo.srWindow.Bottom - scrBufferInfo.srWindow.Top + 1;
}

void Helpers::RemoveScrollBar() {
	GetConsoleScreenBufferInfo(hOut, &scrBufferInfo);

	// current window size
	short winWidth = scrBufferInfo.srWindow.Right - scrBufferInfo.srWindow.Left + 1;
	short winHeight = scrBufferInfo.srWindow.Bottom - scrBufferInfo.srWindow.Top + 1;

	// current screen buffer size
	short scrBufferWidth = scrBufferInfo.dwSize.X;
	short scrBufferHeight = scrBufferInfo.dwSize.Y;

	// to remove the scrollbar, make sure the window height matches the screen buffer height
	COORD newSize;
	newSize.X = scrBufferWidth;
	newSize.Y = winHeight;

	// set the new screen buffer dimensions
	int Status = SetConsoleScreenBufferSize(hOut, newSize);
}


void Helpers::Pause() {
	Sleep(200);
	while (!GetAsyncKeyState(32)){}
	Sleep(200);
}

void Helpers::SetColor(WORD colors) {
	SetConsoleTextAttribute(hOut, colors);
}

void Helpers::MaximizeWindow() {
	system("mode con COLS=700");
	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
	SendMessage(GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);
}
