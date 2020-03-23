#include "ColorCout.h"
#include <Windows.h>

void ColorCout::write(string text, color clr)
{
	HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	int background = 0;
	int foreground = clr;
	SetConsoleTextAttribute(hcon, (background << 4) | foreground);
	cout << text;
	background = 0;
	foreground = 15;
	SetConsoleTextAttribute(hcon, (background << 4) | foreground);
}

void ColorCout::writeln(string text, color clr)
{
	write(text, clr);
	cout << endl;
}