#pragma once
#include "headers.h"
#include "Environment.h"
#include "Helpers.h"
class AEntity // every object on screen is type of entity. Except for text that appears on first screen
{
public:
	int X; // X coordinate of object
	int Y; // Y coordinate of object
	int Height;
	int Width;
	virtual void draw(int x=-10, int y=-10) = 0; 
	virtual void erase(int x = -10, int y = -10) {
		if (x == -10 && y == -10) {
			x = X;
			y = Y;
		}
		Helpers::SetColor(Environment::TxtWhiteColor);
		for (int i = 0; i < Height; i++) {
			Helpers::SetCursorPosition(y + i, x);
			for (int j = 1; j <= Width; j++) cout << " ";
		}
	}
};
