#include "Factory.h"
#include <iostream>

Group::Group(int _owner, int _units, Factory* _from, Factory* _to, int _moves)
{
	owner_id = _owner;
	units = _units;
	from = _from;
	target = _to;
	moves_left = _moves;
}