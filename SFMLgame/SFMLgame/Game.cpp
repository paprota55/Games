#include "Game.h"
#include<iostream>



Game::Game() :window()
{

}


Game::~Game()
{
}

void Game::loop()
{
	map.createMap();
	int skillAvailable = 0;
	while (window.getWindow().isOpen())
	{
		while (window.getWindow().pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.getWindow().close();
		}

		character.move();
		character.animation();
		window.setViewCenter(character.getPosition());
		window.getWindow().clear();
		map.drawMap(window.getWindow());
		character.drawCharacter(window.getWindow());
		window.getWindow().display();
	}
}