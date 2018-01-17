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
	cout << "Sending group!" << endl;
	Factory* fromF = findFactory(from);
	Factory* toF = findFactory(to);
	fromF->units -= units;
	Group* newGrp = new Group(fromF->owner_id, units, fromF, toF, distance(fromF->x, fromF->y, toF->x, toF->y));
	groups.push_back(newGrp);
	toF->incoming_groups.push_back(newGrp);
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

	//make it fair!
	factories[1]->units = factories[0]->units;
	if (factories[1]->production == 0)
		factories[1]->production = 1;
	factories[0]->production = factories[1]->production;
}

void Game::OneStep()
{
	for (int i = 0; i < factories.size(); i++)
	{
		factories[i]->Manage_groups();
	}
	for (int i = 0; i < factories.size(); i++)
	{
		factories[i]->Produce();
	}
	for (int i = 0; i < groups.size(); i++)
	{
		groups[i]->UpdatePosition();
		if (groups[i]->moves_left <= 0)
		{
			delete groups[i];
			groups.erase(groups.begin() + i);
		}
	}


	//input for both players
	DataInput(GetInputManually(1));
	DataInput(GetInputManually(2));
}

bool Game::CheckEnd()
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
	}
	if (p1 == 0)
	{
		cout << "Player 2 wins!" << endl;
		return true;
	}
	if (p2 == 0)
	{
		cout << "Player 1 wins!" << endl;
		return true;
	}
	return false;
}

string Game::DataOutput()
{
	cout<<"Factories:\n";
	for (int i = 0; i < factories.size(); i++)
	{
		cout << "id: " << factories[i]->id << ", ";
		cout << "owner: " << factories[i]->owner_id << ", ";
		cout << "production: " << factories[i]->production << ", ";
		cout << "units: " << factories[i]->units << ", ";
		cout << "position: " << factories[i]->x << ", ";
		cout << factories[i]->y << ", ";
		cout << "Groups incoming: " << factories[i]->incoming_groups.size() << "\n";
		for (int j = 0; j < factories[i]->incoming_groups.size(); j++)
		{
			cout << "\t" << factories[i]->incoming_groups[j]->units << " units incoming. Units owner: " << factories[i]->incoming_groups[j]->owner_id << ", turns left: " << factories[i]->incoming_groups[j]->moves_left << endl;
		}

	}

	return "Data output not handled yet :3\n";
}

void Game::DataInput(string _s)
{
	cout << "Data input not handled yet :O" << endl;
}

string Game::GetInputManually(int _player_id)
{
	DataOutput();
	int buf;
	cout << "1. End Turn\n2. Make a move\n";
	do
	{
		buf = loadInt(2);
		int from, to, amount;
		cout << "Give from id: ";
		cin >> from;
		cout << "Give to id: ";
		cin >> to;
		cout << "Give amount of units: ";
		cin >> amount;
		sendGroup(from, to, amount);
	}while()

	return "1";
}

string MyAlgorithm(int _player_id)
{
	return "1";
}