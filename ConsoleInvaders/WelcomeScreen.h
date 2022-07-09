#pragma once
#include "headers.h"
#include "ALevel.h"
#include "Environment.h"
class WelcomeScreen: public ALevel
{
private:
	int NChar, // number of characters
		NSpace, // number of sapce b/w character
		CharHeight, // height of each character
		CharWidth, // width of each character
		XPos, // x coordinate
		YPos, // y coordinate
		TotalWidth, // total width
		NStars; // number of stars
	void Start();
	void Renderer();
	void End();
	void PrintChar(int* col_ptr, function<bool()> evl_condition, WORD color); // Print single character of heading
	void PrintHeading();
	void PrintStars();
};

