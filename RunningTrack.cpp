#include "RunningTrack.h"

RunningTrack::RunningTrack() : TrainingApparat()
{
	typeTrainer = RUN;
	maxspeed = 0;
}

RunningTrack::RunningTrack(float speed, float cost, string name) : TrainingApparat(cost, name)
{
	typeTrainer = RUN;
	this->maxspeed = speed;
}

float RunningTrack::setMaxSpeed(float speed)
{
	if (speed < 0) throw InvalidSpeed();
	return this->maxspeed = speed;
}

float RunningTrack::getMaxSpeed()
{
	return this->maxspeed;
}

void RunningTrack::showTablInfo(Settings& settings)
{
	if (settings.getFchar() == EMPTY) cout << setfill(' ');
	else if (settings.getFchar() == CHPOINT) cout << setfill('.');
	cout.width(20);
	cout << setiosflags(ios::left) << "Áודמגאÿ המנמזךא";
	if (settings.getPlus()) cout.setf(ios::showpos);
	else cout.unsetf(ios::showpos);
	TrainingApparat::showTablInfo(settings);
	cout << setprecision(2);
	if (settings.getFormat() == FIX) cout.setf(ios::fixed, ios::floatfield);
	if (settings.getFormat() == SCIENTIFIC) cout.setf(ios::scientific, ios::floatfield);
	cout.setf(ios::uppercase);
	if (settings.getBase() == DEC) { cout.setf(ios::dec, ios::basefield); 	cout << maxspeed << " ךל/ק" << endl; }
	if (settings.getBase() == OCT) { cout.setf(ios::oct, ios::basefield); 	cout << (int)maxspeed << " ךל/ק" << endl; }
	if (settings.getBase() == HEX) { cout.setf(ios::hex, ios::basefield); 	cout << (int)maxspeed << " ךל/ק" << endl; }

}