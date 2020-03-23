#pragma once
#include <vector>
#include <iostream>
#include "ColorCout.h"
#include "Gym.h"
using namespace std;
class Menu
{
public:
	static int out(vector<string>);
	static int outTitle(vector<string>, string);
	static int outWithoutCls(vector<string>);
};

