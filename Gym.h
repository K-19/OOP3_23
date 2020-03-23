#pragma once
#include <vector>
#include "RunningTrack.h"
#include "WeightTrainer.h"
#include "Menu.h"
using namespace std;
class Gym
{
	vector<TrainingApparat*> trainers;
	string name;

public: 
	Gym();
	Gym(string);
	void setTrainers(vector<TrainingApparat*>);
	int controlMenu() throw (MenuError);
	int formationMenu(Settings&) throw (MenuError);
	int deletedMenu();
	void showFullInfo(Settings);
	int showTablica(vector<string>, Settings&, int&);
	string setName();
	string setName(string);
	string getName();
	TrainingApparat* addTrainer();
	TrainingApparat* addTrainer(TrainingApparat*);
	vector<TrainingApparat*> getAllTrainers();

	static void changeBase(Settings&);
	static void changeFormat(Settings&);
	static void changePlus(Settings&);
	static void changeFchar(Settings&);

	float getCostAllTrainers();

	void AutoFill();
};

