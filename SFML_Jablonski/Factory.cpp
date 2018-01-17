#include "Factory.h"
#include <iostream>

Factory::Factory(int _id, int _owner_id, int _starting_units, int _prod, int _x, int _y)
{
	id = _id;
	owner_id = _owner_id;
	units = _starting_units;
	production = _prod;
}

void Factory::Manage_groups()
{
	for (int i = 0; i < incoming_groups.size(); i++)
	{
		if (--incoming_groups[i]->moves_left<=0)
		{
			//do attack
			if (owner_id == incoming_groups[i]->owner_id)
			{
				units += incoming_groups[i]->units;
			}
			else
			{
				units -= incoming_groups[i]->units;
				if (units <= 0)
				{
					owner_id = incoming_groups[i]->owner_id;//takeover!
					units *= -1;//no negative dudes allowed
				}
			}
			//free memo, free some from vector - this is done from Game class to do a clean iterative approach
		}
	}
}

void Factory::Produce()
{
	units += production;
}