#pragma once
#include "MyExceptions.h"
class Load
{
	float mass;
public:
	Load();
	Load(float);
	float getMass();
	float addMass(float) throw (InvalidValueException);
	float reduceMass(float) throw (InvalidValueException);
	float setMass();
	float setMass(float) throw (InvalidMass);

};

