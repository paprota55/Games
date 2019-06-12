#include "MonstersContainer.h"



MonstersContainer::MonstersContainer()
{
}

MonstersContainer::~MonstersContainer()
{
	monstersList.clear();
}

void MonstersContainer::drawMonsters(sf::RenderWindow &window)
{
	std::vector<std::shared_ptr<Monster>>::iterator ptr;
	for (ptr = monstersList.begin(); ptr != monstersList.end(); ptr++)
		(*ptr)->drawMonster(window);
}

std::vector<std::shared_ptr<Monster>>& MonstersContainer::getMonstersList()
{
	return monstersList;
}

void MonstersContainer::checkFollow(sf::Vector2f position)
{
	std::vector<std::shared_ptr<Monster>>::iterator ptr;
	for (ptr = monstersList.begin(); ptr != monstersList.end(); ptr++)
	{
		if ((((position.x - (*ptr)->getPosition().x < 350) && (position.x - (*ptr)->getPosition().x >= 0)) || ((position.x - (*ptr)->getPosition().x > -350) && (position.x - (*ptr)->getPosition().x <= 0))) && (((position.y - (*ptr)->getPosition().y < 280) && (position.y - (*ptr)->getPosition().y >= 0)) || ((position.y - (*ptr)->getPosition().y > -280) && (position.y - (*ptr)->getPosition().y <= 0))))
		{
			int tmp = 1;
			(*ptr)->setFollow(tmp);
		}
		else
		{
			int tmp = 0;
			(*ptr)->setFollow(tmp);
		}
	}
}

void MonstersContainer::moveToCharacter(sf::Vector2f position, Animations animation)
{
	float speed = 2;
	int size = 48;
	int switcher = 0;
	std::vector<std::shared_ptr<Monster>>::iterator ptr;
	for (ptr = monstersList.begin(); ptr != monstersList.end(); ptr++)
	{
		if ((*ptr)->ifAgrresive())
		{
			if (position.x - (*ptr)->getPosition().x > size + 3 || position.x - (*ptr)->getPosition().x < -size -3)
			{
				if (position.x - (*ptr)->getPosition().x < 350 && position.x - (*ptr)->getPosition().x >= -size)
				{
					(*ptr)->getMonster().move(speed, 0.0f);
					switcher = 4;
					animation.monsterMove((*ptr)->getMonster(), switcher,(*ptr)->getClock());
				}
				else if (position.x - (*ptr)->getPosition().x > -350 && position.x - (*ptr)->getPosition().x <= size)
				{
					(*ptr)->getMonster().move(-speed, 0.0f);
					switcher = 3;
					animation.monsterMove((*ptr)->getMonster(), switcher, (*ptr)->getClock());
				}
			}
			else if (position.y - (*ptr)->getPosition().y > size + 3 || position.y - (*ptr)->getPosition().y < -size - 3)
			{
				if (position.y - (*ptr)->getPosition().y < 350 && position.y - (*ptr)->getPosition().y >= -size)
				{
					(*ptr)->getMonster().move(0.0f, speed);
					switcher = 2;
					animation.monsterMove((*ptr)->getMonster(), switcher, (*ptr)->getClock());
				}
				else if (position.y - (*ptr)->getPosition().y > -350 && position.y - (*ptr)->getPosition().y <= size)
				{
					(*ptr)->getMonster().move(0.0f, -speed);
					switcher = 1;
					animation.monsterMove((*ptr)->getMonster(), switcher, (*ptr)->getClock());
				}
			}

		}
		
	}
}

void MonstersContainer::attackCharacter(sf::Vector2f position, Statistics &stats)
{
	int size = 48;
	std::vector<std::shared_ptr<Monster>>::iterator ptr;
	for (ptr = monstersList.begin(); ptr != monstersList.end(); ptr++)
	{
		if ((*ptr)->ifAgrresive())
		{
			if ((position.x - (*ptr)->getPosition().x < size + 3 &&  position.x - (*ptr)->getPosition().x > -size - 3) && (position.y - (*ptr)->getPosition().y < size + 3 && position.y - (*ptr)->getPosition().y > -size - 3))
			{
				(*ptr)->attack(stats);
			}
		}
	}
}

void MonstersContainer::deadMonster()
{
	int size = monstersList.size();

	for (int i = 0; i < size; i++)
	{
		if (!monstersList.at(i)->isAlive())
		{
			monstersList.erase(monstersList.begin() + i);
		}
	}
}
