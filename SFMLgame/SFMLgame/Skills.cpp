#include "Skills.h"

Skills::Skills()
{
	healTime = 2.5;
	speedTime = 20;
	autoAttackTime =0.5;
	magicBallTime = 1;
}

Skills::~Skills()
{
	healList.clear();
	speedList.clear();
	autoAttackList.clear();
	magicBallList.clear();
}

void Skills::skillChoicer(Statistics &stats,int rotation,sf::Vector2f position)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F5))
	{
		if (healExhaust.getElapsedTime().asSeconds() > healTime)
		{
			sf::IntRect objectRect;
			objectRect.top = 0;
			objectRect.left = 0;
			objectRect.width = 48;
			objectRect.height = 48;
			std::string textureName = "spells/heal.png";
			healList.insert(healList.begin(), std::shared_ptr<Heal>(new Heal(textureName, objectRect)));
			(*healList.begin())->healCharacter(stats);
			(*healList.begin())->decreaseMana(stats);
			healExhaust.restart();
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::F4))
	{
		if (speedExhaust.getElapsedTime().asSeconds() > speedTime)
		{
			sf::IntRect objectRect;
			objectRect.top = 0;
			objectRect.left = 0;
			objectRect.width = 48;
			objectRect.height = 48;
			std::string textureName = "spells/speed.png";
			speedList.insert(speedList.begin(), std::shared_ptr<SpeedUp>(new SpeedUp(textureName, objectRect)));
			(*speedList.begin())->speedUpCharacter(stats);
			(*speedList.begin())->decreaseMana(stats);
			speedExhaust.restart();
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::F3))
	{
		if (magicBallExhaust.getElapsedTime().asSeconds() > magicBallTime)
		{
			sf::IntRect objectRect;
			objectRect.top = 0;
			objectRect.left = 0;
			objectRect.width = 48;
			objectRect.height = 48;
			std::string textureName = "spells/magicball.png";
			magicBallList.insert(magicBallList.begin(), std::shared_ptr<MagicBall>(new MagicBall(textureName, objectRect, position, rotation)));
			(*magicBallList.begin())->decreaseMana(stats);
			magicBallExhaust.restart();
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		if (autoAttackExhaust.getElapsedTime().asSeconds() > autoAttackTime)
		{
			sf::IntRect objectRect;
			objectRect.top = 0;
			objectRect.left = 0;
			objectRect.width = 48;
			objectRect.height = 48;
			std::string textureName = "spells/autoattack.png";
			autoAttackList.insert(autoAttackList.begin(), std::shared_ptr<AutoAttack>(new AutoAttack(textureName, objectRect,position,rotation)));
			autoAttackExhaust.restart();
		}
	}
	expiredSkills(stats);
}

void Skills::skillUpdater(sf::Vector2f position)
{
	std::vector<std::shared_ptr<Heal>>::iterator ptr;
	for (ptr = healList.begin(); ptr != healList.end(); ptr++)
	{
		(*ptr)->getSprite().setPosition(position);
	}
	std::vector<std::shared_ptr<SpeedUp>>::iterator tmp;
	for (tmp = speedList.begin(); tmp != speedList.end(); tmp++)
	{
		(*tmp)->getSprite().setPosition(position);
	}
	std::vector<std::shared_ptr<MagicBall>>::iterator ball;
	for (ball = magicBallList.begin(); ball != magicBallList.end(); ball++)
	{
		(*ball)->move();
	}
}

void Skills::drawSkills(sf::RenderWindow &window)
{
	for (auto i : healList)
	{
		i->draw(window);
	}
	for (auto i : speedList)
	{
		i->draw(window);
	}
	for (auto i : autoAttackList)
	{
		i->draw(window);
	}
	for (auto i : magicBallList)
	{
		i->draw(window);
	}
}

void Skills::expiredSkills(Statistics & stats)
{
	int size = healList.size();
	for (int i = 0; i < size; i++)
	{
		if (healList.at(i)->isExpired())
		{
			healList.erase(healList.begin() + i);
		}
	}
	size = speedList.size();
	for (int i = 0; i < size; i++)
	{
		if (speedList.at(i)->isExpired(stats))
		{
			speedList.erase(speedList.begin() + i);
		}
	}
	size = autoAttackList.size();
	for (int i = 0; i < size; i++)
	{
		if (autoAttackList.at(i)->isExpired())
		{
			autoAttackList.erase(autoAttackList.begin() + i);
		}
	}
	size = magicBallList.size();
	for (int i = 0; i < size; i++)
	{
		if (magicBallList.at(i)->isExpired())
		{
			magicBallList.erase(magicBallList.begin() + i);
		}
	}
}

std::vector<std::shared_ptr<Heal>>& Skills::getHealList()
{
	return healList;
}

std::vector<std::shared_ptr<SpeedUp>>& Skills::getSpeedList()
{
	return speedList;
}

std::vector<std::shared_ptr<AutoAttack>>& Skills::getAutoAttackList()
{
	return autoAttackList;
}

std::vector<std::shared_ptr<MagicBall>>& Skills::getMagicBallList()
{
	return magicBallList;
}
