#include <Cursor.h>

void Gotoxy(int x, int y)
{	
	assert(x<60&&y<25);
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Gotoxy(POINT xy)
{	
	assert(xy.x<60&&xy.y<25);
	COORD coord;
	coord.X = static_cast<short>(xy.x);
	coord.Y = static_cast<short>(xy.y);
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void HideCursor(bool n)
{
	CONSOLE_CURSOR_INFO cursor_info = {1, n};
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}