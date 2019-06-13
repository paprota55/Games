#pragma once
#include "SFML/Graphics.hpp"
#include "Statistics.h"
#include<iostream>
#include "Map.h"
#include "DisplayWindow.h"

class HUD
{
	std::vector<std::shared_ptr<MapElement>> hudElements;
	std::vector<sf::Vector2f> correctPicPosition;
	std::vector<sf::Vector2f> correctTextPosition;
	std::vector<sf::Text> textElements;
	sf::Font font;
	int counterTextElem, ifPoints;

public:
	HUD();
	~HUD();
	
	std::vector<std::shared_ptr<MapElement>> & getHudElements();
	std::vector<sf::Vector2f> & getCorrect();
	std::vector<sf::Vector2f> & getTextCorrect();
	void drawHud(sf::RenderWindow &);
	void updatePosition(sf::Vector2f);
	void updateHudDrawer(Statistics&);
	void updateText(Statistics&, sf::Vector2f);
	void updateHpAndMpAndExp(Statistics&);
	void drawDataFonts(sf::RenderWindow&);
	void createNamesVector();
	void setTextNames();
	void updateHud(Statistics&, sf::Vector2f, sf::Vector2f);

	void hudClear();
};