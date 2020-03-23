#pragma once
#include "TrainingApparat.h"
class RunningTrack :
	public TrainingApparat
{
	float maxspeed;
public:
	RunningTrack();
	RunningTrack(float, float, string);
	float setMaxSpeed(float) throw (InvalidSpeed);
	float getMaxSpeed();
	void showTablInfo(Settings&);
};

