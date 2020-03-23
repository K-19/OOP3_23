#pragma once
#include <string>
#include <iomanip>
#include "MyExceptions.h"
#include "Settings.h"

enum type { NaN, RUN, WEIGHT };

class TrainingApparat
{
protected:
	type typeTrainer;
	float cost;
	string name;
public:
	TrainingApparat();
	TrainingApparat(float, string);
	type getType();
	float getCost();
	float setCost();
	string getName();
	string setName();
	string setName(string);
	virtual void showTablInfo(Settings&);
};

