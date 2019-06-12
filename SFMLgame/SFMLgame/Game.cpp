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
	manager.loadHUD(hud);
	hud.createNamesVector();
	manager.loadMonsters(monsters.getMonstersList());

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
				hud.hudClear();
				manager.loadHUD(hud);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
			{
				int val = character.getStats().getHealth();
				character.getStats().setCurrHp(val);
				character.getStats().setCurrMp(val);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::H))
			{
				int newHp = character.getStats().getCurrHp() - 5;
				character.getStats().setCurrHp(newHp);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
			{
				int newExp = character.getStats().getExp() + 15;
				character.getStats().setExp(newExp);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::M))
			{
				int newMp = character.getStats().getCurrMp() - 5;
				character.getStats().setCurrMp(newMp);
			}
		}
		if (monsters.getMonstersList().size() <= 1)
		{
			manager.loadMonsters(monsters.getMonstersList());
		}
		monsters.checkFollow(character.getPosition());
		monsters.moveToCharacter(character.getPosition(),animation);
		monsters.attackCharacter(character.getPosition(), character.getStats());
		monsters.deadMonster();

		character.move(map.getProtectedElements(),monsters.getMonstersList());
		animation.characterMove(character.getStats(), character.getRotation(), character.getSprite());

		window.setViewCenter(character.getPosition());
		statsUpdater.checkEvents(window, character);
		hud.updateHud(character.getStats(), window.getViewPos());
		character.checkSkills();

		window.getWindow().clear();
		map.drawMap(window.getWindow());
		character.drawCharacter(window.getWindow());
		monsters.drawMonsters(window.getWindow());
		hud.drawHud(window.getWindow());

		window.setMiniMapView();
		map.drawMap(window.getWindow());
		character.drawCharacter(window.getWindow());
		monsters.drawMonsters(window.getWindow());
		window.setMapView();
		window.getWindow().display();
	}
}
