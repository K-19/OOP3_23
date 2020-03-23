#pragma once
#include "TrainingApparat.h"
#include "Load.h"
class WeightTrainer : public TrainingApparat
{
public:
	Load load;
	WeightTrainer();
	WeightTrainer(float, float, string) throw (InvalidObject);
	void showTablInfo(Settings&);
};

