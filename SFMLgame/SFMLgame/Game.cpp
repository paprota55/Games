#include "Game.h"

Game::Game() :window()
{
}

Game::~Game()
{
}

void Game::loop()
{
	DataManager manager;
	manager.loadMap(map);
	manager.loadCharacter(character);

	while (window.getWindow().isOpen())
	{
		while (window.getWindow().pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.getWindow().close();
				manager.saveCharacter(character);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				window.getWindow().close();
				manager.saveCharacter(character);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
			{
				manager.loadMap(map);
				manager.loadCharacter(character);
			}
		}

		character.move(map.getProtectedElements());
		character.animation();
		window.setViewCenter(character.getPosition());
		window.getWindow().clear();
		map.drawMap(window.getWindow());
		character.drawCharacter(window.getWindow());
		window.getWindow().display();
	}
}
