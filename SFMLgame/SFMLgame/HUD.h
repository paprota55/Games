#pragma once
#include "SFML/Graphics.hpp"
#include "Statistics.h"
#include<iostream>
#include "Map.h"
#include "DisplayWindow.h"

class HUD
{
	std::vector<std::shared_ptr<MapElement>> hudElements;
	std::vector<sf::Vector2f> correctPosition;
	std::vector<sf::Text> textElements;
	sf::Font font;

public:
	HUD();
	~HUD();
	
	std::vector<std::shared_ptr<MapElement>> & getHudElements();
	std::vector<sf::Vector2f> & getCorrect();
	void drawHud(sf::RenderWindow &);
	void updatePosition(sf::Vector2f);
	void updateHpAndMpAndExp(Statistics&);
	void drawDataFonts(sf::RenderWindow&, Statistics&,sf::Vector2f);
	void createNamesVector();
	void hudClear();
};