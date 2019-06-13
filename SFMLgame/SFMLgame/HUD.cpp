#include "HUD.h"



HUD::HUD()
{
	font.loadFromFile("Fonts/arial.ttf");
	counterTextElem = 0;
}


HUD::~HUD()
{
	hudElements.clear();
	textElements.clear();
	correctPicPosition.clear();
	correctTextPosition.clear();
}

std::vector<std::shared_ptr<MapElement>>& HUD::getHudElements()
{
	return hudElements;
}

std::vector<sf::Vector2f>& HUD::getCorrect()
{
	return correctPicPosition;
}

std::vector<sf::Vector2f>& HUD::getTextCorrect()
{
	return correctTextPosition;
}

void HUD::drawHud(sf::RenderWindow &window)
{
	int i = 0;
	std::vector<std::shared_ptr<MapElement>>::iterator ptr;
	for (ptr = hudElements.begin(); ptr != hudElements.end(); ptr++)
	{
		if(i!=ifPoints)
		(*ptr)->drawElement(window);
		i++;
	}
	drawDataFonts(window);
}

void HUD::updatePosition(sf::Vector2f currPos)
{
	int i = 0;
	std::vector<std::shared_ptr<MapElement>>::iterator ptr;
	for (ptr = hudElements.begin(); ptr != hudElements.end(); ptr++)
	{
		(*ptr)->getElement().setPosition(sf::Vector2f(currPos.x - correctPicPosition[i].x,currPos.y - correctPicPosition[i].y));
		i++;
	}	
	i = 0;
	std::vector<sf::Text>::iterator itr;
	for (itr = textElements.begin(); itr != textElements.end(); itr++)
	{
		itr->setPosition(sf::Vector2f(currPos.x - correctTextPosition[i].x, currPos.y - correctTextPosition[i].y));
		i++;
	}
}

void HUD::updateHudDrawer(Statistics &stats)
{
	if (stats.getPoints() > 0)
	{
		ifPoints = 99;
	}
	else ifPoints = 7;
}

void HUD::updateText(Statistics &stats, sf::Vector2f position)
{
	textElements[9].setString(std::to_string(stats.getCurrHp()));
	textElements[10].setString(std::to_string(stats.getCurrMp()));
	textElements[11].setString(std::to_string(stats.getLevel()));
	textElements[12].setString(std::to_string(stats.getAttackDmg()));
	textElements[13].setString(std::to_string(stats.getIntelligence()));
	textElements[14].setString(std::to_string(stats.getArmor()));
	textElements[15].setString(std::to_string(stats.getPoints()));
	textElements[16].setString(std::to_string((int)position.x));
	textElements[17].setString(std::to_string((int)position.y));
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

void HUD::drawDataFonts(sf::RenderWindow &window)
{
	for (int i = 0; i < counterTextElem; i++)
	{
		window.draw(textElements[i]);
	}
}

void HUD::createNamesVector()
{
	for (int i = 0; i <18 ; i++)
	{
		textElements.push_back(sf::Text());
		textElements[i].setFont(font);
		textElements[i].setCharacterSize(20);
		textElements[i].setFillColor(sf::Color::White);
		textElements[i].setStyle(sf::Text::Bold);
		counterTextElem++;
	}
	setTextNames();

}

void HUD::setTextNames()
{
	textElements[0].setString("Health: ");
	textElements[1].setString("Mana: ");
	textElements[2].setString("Lvl: ");
	textElements[3].setString("AD: ");
	textElements[4].setString("AP: ");
	textElements[5].setString("Def: ");
	textElements[6].setString("Pkt: ");
	textElements[7].setString("X: ");
	textElements[8].setString("Y: ");
}

void HUD::updateHud(Statistics &stats, sf::Vector2f pos, sf::Vector2f charPos)
{
	updateHpAndMpAndExp(stats);
	updatePosition(pos);
	updateText(stats, charPos);
	updateHudDrawer(stats);
}

void HUD::hudClear()
{
	hudElements.clear();
}


