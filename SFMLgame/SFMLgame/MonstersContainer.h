#pragma once
#include "Monster.h"
#include "Animations.h"
#include"Skills.h"
#include "StatisticsEvents.h"

class MonstersContainer
{
	std::vector<std::shared_ptr<Monster>> monstersList;

public:
	MonstersContainer();
	~MonstersContainer();

	void drawMonsters(sf::RenderWindow&);
	std::vector<std::shared_ptr<Monster>>& getMonstersList();
	void checkFollow(sf::Vector2f);
	void moveToCharacter(sf::Vector2f,Animations);
	void attackCharacter(sf::Vector2f, Statistics&);
	void deadMonster(Statistics &, StatisticsEvents&);
	void checkCollisions(Skills&, Statistics&);
};

