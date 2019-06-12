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

void HUD::updateHpAndMpAndExp(Statistics &stats)
{
	float hp,mp,exp;
	hp = (float)stats.getCurrHp() / (float)stats.getHealth() * 190;
	mp = (float)stats.getCurrMp() / (float)stats.getMana() * 190;
	exp = (float)stats.getExp() / (float)stats.getExpToLvl() * 190;
	sf::IntRect tmp;
	tmp = hudElements[3]->getElement().getTextureRect();
	if (hp < 0)
	{
		hp = 0;
	}
	tmp.width = hp;
	hudElements[3]->getElement().setTextureRect(tmp);
	tmp = hudElements[4]->getElement().getTextureRect();
	if (mp < 0)
	{
		mp = 0;
	}
	tmp.width = mp;
	hudElements[4]->getElement().setTextureRect(tmp);
	tmp = hudElements[5]->getElement().getTextureRect();
	if (exp < 0)
	{
		exp = 0;
	}
	tmp.width = exp;
	hudElements[5]->getElement().setTextureRect(tmp);

}

void HUD::drawDataFonts(sf::RenderWindow &window, Statistics &stats, sf::Vector2f coordinates)
{
	for (int i = 0; i < 6; i++)
	{
		window.draw(textElements[i]);
	}
}

void HUD::createNamesVector()
{
	font.loadFromFile("Fonts/arial.ttf");
	sf::Text hp, mp, attackDmg, intelligence, armor, coordinates;
	for (int i = 0; i < 6; i++)
	{
		textElements.push_back(sf::Text());
		textElements[i].setFont(font);
		textElements[i].setCharacterSize(20);
		textElements[i].setFillColor(sf::Color::Black);
		textElements[i].setStyle(sf::Text::Bold);
	}
	textElements[0].setString("Health: ");
	textElements[1].setString("Mana: ");
	textElements[2].setString("AD: ");
	textElements[3].setString("AP: ");
	textElements[4].setString("Def: ");
	textElements[5].setString("Coordinates: ");
}

void HUD::hudClear()
{
	hudElements.clear();
}


