#pragma once
#include "SFML/Graphics.hpp"
#include<Windows.h>
#include "Character.h"
#include"DisplayWindow.h"

class StatisticsEvents
{
	sf::Clock clock;
	sf::Clock manaClock;
	sf::Clock healthClock;
	sf::Clock addPointExhaust;
public:
	StatisticsEvents();
	~StatisticsEvents();

	void checkEvents(DisplayWindow &, Character &);

	void updateMp(Statistics&);
	void updateHp(Statistics&);
	bool levelUp(Statistics&);
	bool dead(Statistics&);
	void updateAfterLevelUp(Statistics&);
	void updateAfterDead(Statistics&, sf::Sprite&);
	void addPoint(Statistics&);

	void drawLevelUpOrDead(sf::RenderWindow&, std::string, sf::Vector2f);
};

