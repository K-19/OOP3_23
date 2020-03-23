#define _CRT_SECURE_NO_WARNINGS
#include "TrainingApparat.h"

TrainingApparat::TrainingApparat()
{
	typeTrainer = NaN;
	this->cost = 0;
	name = "";
}

TrainingApparat::TrainingApparat(float cost, string name)
{
	typeTrainer = NaN;
	if (cost < 0) throw InvalidCost();
	this->cost = cost;
	this->name = name;
}

type TrainingApparat::getType()
{
	return typeTrainer;
}

float TrainingApparat::getCost()
{
	return cost;
}

float TrainingApparat::setCost()
{
	float newCost;
	int flag;
	do {
		flag = 0;
		try {
			cin >> newCost;

			if (!cin.good()) throw InvalidValueException();
			if (newCost < 0) throw InvalidCost();
			cin.clear();
			cin.ignore(10, '\n');
		}
		catch (InvalidCost exc)
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
	return this->cost = newCost;
}

string TrainingApparat::getName()
{
	return name;
}

string TrainingApparat::setName()
{
	int except;
	do
	{
		except = 0;
		string newName;
		try {
			getline(cin, newName);
			for (int i = 0; i < newName.length(); i++)
			{
				if (newName.at(i) == '_') throw InvalidName();
			}
		}
		catch (InvalidName exc) {
			exc.what();
			except = 1;
		}
		this->setName(newName);
	} while (except);
	return name;
}

string TrainingApparat::setName(string name)
{
	return this->name = name;
}

void TrainingApparat::showTablInfo(Settings& settings)
{
	cout.width(20);  cout << name;
	char temp[20];
	cout << setprecision(2);
	if (settings.getFormat() == FIX) cout.setf(ios::fixed, ios::floatfield);
	if (settings.getFormat() == SCIENTIFIC) cout.setf(ios::scientific, ios::floatfield);
	cout.setf(ios::uppercase);
	cout.width(20);
	if (settings.getPlus()) cout.setf(ios::showpos);
	else cout.unsetf(ios::showpos);
	if (settings.getBase() == DEC) { cout.setf(ios::dec, ios::basefield); cout << cost; }
	if (settings.getBase() == OCT) { cout.setf(ios::oct, ios::basefield); cout << (int)cost; }
	if (settings.getBase() == HEX) { cout.setf(ios::hex, ios::basefield); cout << (int)cost; }
}