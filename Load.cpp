#include "Load.h"

#define MAX_MASS 400

Load::Load() : mass(0) {}

Load::Load(float mass) : mass(mass) {}

float Load::getMass()
{
	return mass;
}

float Load::addMass(float mass)
{
	if (this->mass + mass > 1000) throw InvalidValueException();
	return this->mass += mass;
}

float Load::reduceMass(float mass)
{
		if (this->mass - mass < 0) throw InvalidValueException();
		return this->mass -= mass;
}

float Load::setMass(float mass)
{
	if (mass < 0.0) throw InvalidMass();
	return this->mass = mass;
}

float Load::setMass()
{
	float newMass;
	int flag;
	do {
		flag = 0;
		try {
			cin >> newMass;
			if (!cin.good()) throw InvalidValueException();
			if (newMass <= 0 || newMass > MAX_MASS) throw InvalidMass();
			cin.clear();
			cin.ignore(10, '\n');
		}
		catch (InvalidMass exc)
		{
			exc.what();
			flag = 1;
		}
		catch (InvalidValueException exc)
		{
			exc.what();
			cin.clear();
			cin.ignore(10, '\n');
			flag = 1;
		}
	} while (flag);
	return this->mass = newMass;
}