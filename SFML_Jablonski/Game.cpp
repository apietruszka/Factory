#include "Game.h"
#include <iostream>

int Game::loadInt(int max)
{
	int ret;
	cin >> ret;
	return ret;
}

void Game::sendGroup(int from, int to, int units)
{
	Factory* fromF = findFactory(from);
	Factory* toF = findFactory(to);
	fromF->units -= units;
	groups.push_back(new Group(fromF->owner_id, units, fromF, toF, distance(fromF->x, fromF->y, toF->x, toF->y)));
}

int Game::distance(int x1, int y1, int x2, int y2)
{
	return (int)sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
}

Factory* Game::findFactory(int id)
{
	for (int i = 0; i < factories.size(); i++)
	{
		if (factories[i]->id == id)
			return factories[i];
	}
}

Game::Game(int _min_fact, int _max_fact, int _max_prod, int _max_starting_units, int _max_x, int _max_y)
{
	int factories_amount = rand() % _min_fact + (_max_fact - _min_fact);
	for (int i = 0; i < factories_amount; i++)
	{
		factories.push_back(new Factory(i, 0, rand() % _max_starting_units, rand() % _max_prod, rand() % _max_x, rand() % _max_y));
	}

	//give players a factory
	factories[0]->owner_id = 1;
	factories[1]->owner_id = 2;
	factories[1]->units = factories[0]->units;//make it fair!
}

void Game::OneStep()
{
	for (int i = 0; i < factories.size(); i++)
	{
		factories[i]->Manage_groups();
	}
	for (int i = 0; i < groups.size(); i++)
	{
		if (groups[i]->moves_left <= 0)
		{
			delete groups[i];
			groups.erase(groups.begin() + i);
		}
	}

	CheckEnd();

	//input for both players
	DataInput(GetInputManually(1));
	DataInput(GetInputManually(2));
}

void Game::CheckEnd()
{
	int neutral = 0;
	int p1 = 0;
	int p2 = 0;
	for (int i = 0; i < factories.size(); i++)
	{
		switch (factories[i]->owner_id)
		{
		case 0:
			neutral++;
			break;
		case 1:
			p1++;
			break;
		case 2:
			p2++;
			break;
		}
		if (p1 == 0)
		{
			cout << "Player 2 wins!" << endl;
			exit(0);
		}
		if (p2 == 0)
		{
			cout << "Player 1 wins!" << endl;
			exit(0);
		}
	}
}

string Game::DataOutput()
{
	return "Data output not handled yet :3\n";
}

void Game::DataInput(string _s)
{
	cout << "Data input not handled yet :O" << endl;
}

string Game::GetInputManually(int _player_id)
{
	cout << "1. End Turn\n2. Make a move\n";
	if (loadInt(2)==2)
	{
		int from, to, amount;
		cout << "Give from id: ";
		cin >> from;
		cout << "Give to id: ";
		cin >> to;
		cout << "Give amount of units: ";
		cin >> amount;
		sendGroup(from, to, amount);
	}

	return "1";
}