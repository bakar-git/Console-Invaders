#include "WelcomeScreen.h"
void WelcomeScreen::Start() {
	NChar = 9;
	NSpace = 5;
	CharHeight = 10;
	CharWidth = CharHeight + 1;
	TotalWidth = (NChar * CharWidth) + ((NChar - 1) * NSpace);
	XPos = (WinWidth / 2) - (TotalWidth / 2);
	YPos = (WinHeight / 4) - (CharHeight / 2);
	NStars = 150;
	AUDIO.play("bg", 1);
}
void WelcomeScreen::Renderer() {
	PrintStars();
	PrintHeading();
	string text = "Press space to begin your journey";
	Helpers::SetCursorPosition((WinHeight / 2) + 1, ((WinWidth / 2) - (text.length() / 2)));
	cout << text;
	Helpers::Pause();
}
void WelcomeScreen::End() {
	Helpers::SetColor(Environment::TxtWhiteColor);
	system("cls");
}
void WelcomeScreen::PrintChar(int* col_ptr, function<bool()> evl_condition, WORD color) {
	for (int col = 1; col <= CharWidth; col++)
	{
		*col_ptr = col;
		if (evl_condition()) {
			Helpers::SetColor(color);
			cout << "@";
		}
		else {
			Helpers::SetColor(Environment::TxtWhiteColor);
			cout << " ";
		}
	}
	Helpers::SetColor(Environment::TxtWhiteColor);
	for (int i = 0; i < NSpace; i++) {
		cout << " ";
	}
}
void WelcomeScreen::PrintStars()
{
	Helpers::SetColor(Environment::TxtWhiteColor);
	for (int i = 1; i <= NStars; i++) {
		Helpers::SetCursorPosition(rand() % WinHeight, rand() % WinWidth);
		cout << "*";
	}
}

void WelcomeScreen::PrintHeading() {
	WORD Clr1 = BACKGROUND_RED | Environment::TxtWhiteColor;
	WORD Clr2 = BACKGROUND_BLUE | Environment::TxtWhiteColor;
	WORD Clr3 = BACKGROUND_GREEN | Environment::TxtWhiteColor;
	for (int row = 1; row <= CharHeight; row++)
	{
		Helpers::SetCursorPosition(YPos + row, XPos);
		int* col_ptr = new int;
		// C	
		PrintChar(col_ptr, [=]()->bool {return (row == 1 || row == CharHeight || *col_ptr == 1) ? true : false; }, Clr1);
		// O
		PrintChar(col_ptr, [=]()->bool {return (row == 1 || *col_ptr == 1 || *col_ptr == CharWidth || row == CharHeight) ? true : 
			false; }, Clr1);
		// N
		PrintChar(col_ptr, [=]()->bool {return (*col_ptr == 1 || *col_ptr == CharWidth || *col_ptr == row) ? true : false; }, Clr1);
		// C	
		PrintChar(col_ptr, [=]()->bool {return (row == 1 || row == CharHeight || *col_ptr == 1) ? true : false; }, Clr1);
		// O
		PrintChar(col_ptr, [=]()->bool {return (row == 1 || *col_ptr == 1 || *col_ptr == CharWidth || row == CharHeight)
			? true : false; }, Clr3);
		// M
		PrintChar(col_ptr, [=]()->bool {return (*col_ptr == 1 || *col_ptr == CharWidth || (*col_ptr-1 == row && row < (CharHeight / 2)
			+ 1) || (*col_ptr+row == CharHeight+1 && row < 
			(CharHeight / 2) + 1)) ? true : false; }, Clr2);
		// B
		PrintChar(col_ptr, [=]()->bool {return (row == 1 || *col_ptr == 1 || *col_ptr == CharWidth || row == (CharHeight / 2) + 1 ||
			row == CharHeight) ? true : false; }, Clr2);
		// A
		PrintChar(col_ptr, [=]()->bool {return (row == 1 || *col_ptr == 1 || *col_ptr == CharWidth || row == (CharHeight / 2)+1) ? true 
			: false; }, Clr2);
		// T
		PrintChar(col_ptr, [=]()->bool {return (row == 1 || *col_ptr == CharWidth / 2) ? true : false; }, Clr2);
		cout << endl;
	}
}




