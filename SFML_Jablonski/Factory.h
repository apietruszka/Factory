#ifndef FACTORY_H
#ifndef GROUP_H

#include <SFML/Graphics.hpp>

#define FACTORY_H
#define GROUP_H

class Group;

class Factory
{
	friend class Game;

	int x, y;

	int id;
	int owner_id;//0 - nobodie's
	int units;
	int production;
	std::vector<Group*> incoming_groups;

public:
	Factory(int _id, int _owner_id, int _starting_units, int _prod, int _x, int _y);
	void Manage_groups();
	void Produce();
};

class Group
{
	friend class Game;
	friend class Factory;

	int owner_id;
	int units;
	Factory* from;//maybe useless
	Factory* target;//maybe useless
	int moves_left;

	Group(int _owner, int _units, Factory* _from, Factory* _to, int _moves);
};

#endif
#endif