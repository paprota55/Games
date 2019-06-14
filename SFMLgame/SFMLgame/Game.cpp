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
	manager.loadAll(map, character, hud, monsters.getMonstersList(),window.getWindow());
	hud.createNamesVector();


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
			
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
			{
				int val = character.getStats().getHealth();
				character.getStats().setCurrHp(val);
				character.getStats().setCurrMp(val);
			}
			
		}
		if (monsters.getMonstersList().size() == 0)
		{
			manager.loadMonsters(monsters.getMonstersList());
		}
		monsters.checkFollow(character.getPosition());
		monsters.moveToCharacter(character.getPosition(),animation);
		monsters.attackCharacter(character.getPosition(), character.getStats());
		monsters.deadMonster(character.getStats(),statsUpdater);

		character.move(map.getProtectedElements(),monsters.getMonstersList());
		animation.characterMove(character.getStats(), character.getRotation(), character.getSprite());

		window.setViewCenter(character.getPosition());
		statsUpdater.checkEvents(window, character);
		hud.updateHud(character.getStats(), window.getViewPos(),character.getPosition());
		character.checkSkills();
		monsters.checkCollisions(character.getSkills(), character.getStats());
		animation.healAnim(character.getSkills().getHealList());
		animation.speedUpAnim(character.getSkills().getSpeedList());
		animation.autoAttacAnim(character.getSkills().getAutoAttackList());
		animation.magicBallAnim(character.getSkills().getMagicBallList());

		window.getWindow().clear();

		map.drawMap(window.getWindow());
		character.drawCharacter(window.getWindow());
		monsters.drawMonsters(window.getWindow());
		character.drawSkills(window.getWindow());
		hud.drawHud(window.getWindow());

		window.setMiniMapView();
		map.drawMap(window.getWindow());
		character.drawCharacter(window.getWindow());
		monsters.drawMonsters(window.getWindow());
		window.setMapView();
		window.getWindow().display();
	}
}
