#ifndef GAME_H
#include <vector>
#include "Factory.h"

#define GAME_H

using namespace std;

class Game
{
	vector<Factory*> factories;
	vector<Group*> groups;

	int loadInt(int max);
	void sendGroup(int from, int to, int units);
	Factory* findFactory(int id);
	int distance(int x1, int y1, int x2, int y2);

public:
	Game(int _min_fact, int _max_fact, int _max_prod, int _max_starting_units, int _max_x, int _max_y);
	void OneStep();
	bool CheckEnd();
	string DataOutput();
	void DataInput(string _s);

	string GetInputManually(int _player_id);
	string MyAlgorithm(int _player_id);
};

#endif