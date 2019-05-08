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
	while (window.getWindow().isOpen())
	{
		while (window.getWindow().pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.getWindow().close();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				window.getWindow().close();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
				map.Delete();
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
