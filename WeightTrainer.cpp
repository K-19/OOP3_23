#include "WeightTrainer.h"

WeightTrainer::WeightTrainer() : TrainingApparat()
{
	typeTrainer = WEIGHT;
	load.setMass(0);
}

WeightTrainer::WeightTrainer(float mass, float cost, string name) : TrainingApparat(cost, name)
{
	typeTrainer = WEIGHT;
	try { load.setMass(mass); }
	catch (InvalidMass) { throw InvalidObject(); }
}

void WeightTrainer::showTablInfo(Settings& settings)
{
	if (settings.getFchar() == EMPTY) cout << setfill(' ');
	else if (settings.getFchar() == CHPOINT) cout << setfill('.');
	cout.width(20);
	cout << setiosflags(ios::left) << "Силовой тренажёр";
	if (settings.getPlus()) cout.setf(ios::showpos);
	else cout.unsetf(ios::showpos);
	TrainingApparat::showTablInfo(settings);
	if (settings.getFormat() == FIX) cout.setf(ios::fixed, ios::floatfield);
	if (settings.getFormat() == SCIENTIFIC) cout.setf(ios::scientific, ios::floatfield);
	cout.width(0);  
	cout.setf(ios::uppercase);
	if (settings.getBase() == DEC) { cout.setf(ios::dec, ios::basefield); 	cout << load.getMass() << " кг" << endl; }
	if (settings.getBase() == OCT) { cout.setf(ios::oct, ios::basefield);  cout << (int)load.getMass() << " кг" << endl; }
	if (settings.getBase() == HEX) { cout.setf(ios::hex, ios::basefield);  cout << (int)load.getMass() << " кг" << endl; }

}