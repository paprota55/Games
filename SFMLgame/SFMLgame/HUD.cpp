#include "HUD.h"



HUD::HUD()
{
}


HUD::~HUD()
{
	hudElements.clear();
}

std::vector<std::shared_ptr<MapElement>>& HUD::getHudElements()
{
	return hudElements;
}

std::vector<sf::Vector2f>& HUD::getCorrect()
{
	return correctPosition;
}

void HUD::drawHud(sf::RenderWindow &window)
{
	std::vector<std::shared_ptr<MapElement>>::iterator ptr;
	for (ptr = hudElements.begin(); ptr != hudElements.end(); ptr++)
		(*ptr)->drawElement(window);
}

void HUD::updatePosition(sf::Vector2f currPos)
{
	int i = 0;
	std::vector<std::shared_ptr<MapElement>>::iterator ptr;
	for (ptr = hudElements.begin(); ptr != hudElements.end(); ptr++)
	{
		(*ptr)->getElement().setPosition(sf::Vector2f(currPos.x - correctPosition[i].x,currPos.y - correctPosition[i].y));
		i++;
	}
		
}

void HUD::updateHpAndMp(Statistics &stats)
{
	double hp,mp;
	std::cout << stats.getCurrHp() << " ";
	hp = (float)stats.getCurrHp() / (float)stats.getHealth() * 190;
	//std::cout << hp;
	mp = (float)stats.getCurrMp() / (float)stats.getMana() * 190;
	sf::IntRect tmp;
	tmp = hudElements[2]->getElement().getTextureRect();
	if (hp < 0)
	{
		hp = 0;
	}
	tmp.width = hp;
	hudElements[2]->getElement().setTextureRect(tmp);
	tmp = hudElements[3]->getElement().getTextureRect();
	if (mp < 0)
	{
		mp = 0;
	}
	tmp.width = mp;
	hudElements[3]->getElement().setTextureRect(tmp);
}

