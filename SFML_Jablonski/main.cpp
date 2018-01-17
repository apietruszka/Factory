#include <iostream>
#include <chrono>
#include "Game.h"



int main()
{
	srand(time(NULL));

	Game FactoriesOfLove(10, 20, 3, 10, 5, 5);
	
	while (FactoriesOfLove.CheckEnd() == false)
	{
		cout << "Step Over" << endl;
		FactoriesOfLove.OneStep();
	}

	return 0;
}