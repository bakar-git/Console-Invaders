#include "Star.h"
Star::Star(Boundary boundaries)
{
	limit = boundaries;
	Height = 1;
	Width = 1;
	Xspeed = 1;
	Yspeed = 1;
	canDestroy = false;
}

void Star::draw(int x = -10, int y = -10)
{
	Helpers::SetColor(Environment::TxtWhiteColor);
	if (x == -10 && y == -10) {
		x = X;
		y = Y;
	}
	Helpers::SetCursorPosition(y, x);
	int XCenter = WinWidth / 2;
	int YCenter = WinHeight / 2;
	if ((X <= XCenter && Y >= YCenter) || (X >= XCenter && Y <= YCenter)) cout << "/";
	else if ((X >= XCenter && Y >= YCenter) || (X <= XCenter && Y <= YCenter)) cout << "\\";
	/*if ((x <= xcenter && y >= ycenter) || (x >= xcenter && y <= ycenter)) cout << "//";
	else if ((x >= xcenter && y >= ycenter) || (x <= xcenter && y <= ycenter)) cout << "\\\\";*/
}

void Star::movementController()
{
	if (
		(X > limit.Left && X - Xspeed > limit.Left) && (X < limit.Right && X + Xspeed < limit.Right - Width) &&
		(Y > limit.Top && Y - Yspeed > limit.Top) && (Y < limit.Bottom && Y + Yspeed < limit.Bottom - Height)
		) {
		erase(X, Y);
		int XCenter = WinWidth / 2;
		int YCenter = WinHeight / 2;
		if (X <= XCenter) X -= Xspeed;
		else if (X >= XCenter) X += Xspeed;
		if (Y <= YCenter) Y -= Yspeed;
		else if (Y >= YCenter) Y += Yspeed;
		draw(X, Y);
	}else canDestroy = true;
}