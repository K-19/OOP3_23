#pragma once
#include <iostream>
#include <string>
using namespace std;

enum color { BLACK = 1, DARK_BLUE, DARK_GREEN, DARK_BIRUZA, DARK_RED, DARK_MALINA, DARK_YELLOW, SNOW, BLUE, GREEN, LIGHT_BLUE, RED, MALINA, YELLOW, WHITE };

class ColorCout
{
public:
	static void write(string, color);
	static void writeln(string, color);
};

