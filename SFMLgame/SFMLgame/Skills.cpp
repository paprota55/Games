#include "Skills.h"

Skills::Skills()
{
	healTime = 3;
	speedTime = 20;
}

Skills::~Skills()
{
}

void Skills::characterHeal(Statistics &stats)
{
	if (healExhaust.getElapsedTime().asSeconds() > healTime)
	{
		int currHp = stats.getCurrHp() + 0.15*stats.getHealth();
		int currMp = stats.getCurrMp() - stats.getMana()*0.1;
		if (currHp > stats.getHealth())
			currHp = stats.getHealth();
		if (currMp < 0)
			currMp = 0;
		stats.setCurrMp(currMp);
		stats.setCurrHp(currHp);
		healExhaust.restart();
	}
}

void Skills::speedUp(Statistics &stats)
{
	if (speedUpExhaust.getElapsedTime().asSeconds() > speedTime)
	{
		float speed = 5;
		stats.setMoveSpeed(speed);
		speedUpExhaust.restart();
		speedExpired.restart();
	}
}

void Skills::checkClocks(Statistics &stats)
{
	speedUpOff(stats);
}

void Skills::skillUpdater(Statistics &stats)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F5))
	{
		characterHeal(stats);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F4))
	{
		speedUp(stats);
	}
	checkClocks(stats);
}

void Skills::speedUpOff(Statistics &stats)
{
	if (speedExpired.getElapsedTime().asSeconds() > speedTime / 2)
	{
		float speed = 3.5;
		stats.setMoveSpeed(speed);
		speedExpired.restart();
	}
}