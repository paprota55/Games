#pragma once
#include "SFML/Graphics.hpp"
#include<Windows.h>
#include "Character.h"

class StatisticsEvents
{
	sf::Clock clock;
	sf::Clock manaClock;
	sf::Clock healthClock;
public:
	StatisticsEvents();
	~StatisticsEvents();

	void checkEvents(sf::RenderWindow &, Character &);

	void updateMp(Statistics&);
	void updateHp(Statistics&);
	bool levelUp(Statistics&);
	bool dead(Statistics&);
	void updateAfterLevelUp(Statistics&);
	void updateAfterDead(Statistics&, sf::Sprite&);

	void drawLevelUpOrDead(sf::RenderWindow&, std::string, sf::Vector2f);
};

