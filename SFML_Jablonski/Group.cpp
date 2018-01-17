#include "Factory.h"
#include <iostream>

Group::Group(int _owner, int _units, Factory* _from, Factory* _to, int _moves)
{
	owner_id = _owner;
	units = _units;
	from = _from;
	target = _to;
	moves_left = _moves;
	x = (double)_from->x;
	y = (double)_from->y;
	starting_moves = moves_left;
}

void Group::UpdatePosition()
{
	x = from->x + (target->x - from->x) / (starting_moves - moves_left);
	y = from->y + (target->y - from->y) / (starting_moves - moves_left);
}