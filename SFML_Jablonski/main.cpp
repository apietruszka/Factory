#include <SFML/Graphics.hpp>
#include <iostream>
#include <chrono>
#include "Game.h"



int main()
{
	Game FactoriesOfLove()
	clock_t start = clock();
	clock_t end;
	double dt = 0.0000001;
	double logTime = 5;

	srand(time(NULL));
	

	sf::RenderWindow window(sf::VideoMode(800, 800), "Gotta love MJ!");

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();

		window.display(); 
		
		end = clock();
		dt = (double)(end - start) / CLOCKS_PER_SEC;
		if (dt > logTime)
		{
			start = clock();
		}
	}

	return 0;
}