#pragma once
#include "SFML/Graphics.hpp"
#include"MapElement.h"
#include "Statistics.h"
#include<iostream>

class HUD
{
	std::vector<std::shared_ptr<MapElement>> hudElements;
	std::vector<sf::Vector2f> correctPosition;
public:
	HUD();
	~HUD();
	
	std::vector<std::shared_ptr<MapElement>> & getHudElements();
	std::vector<sf::Vector2f> & getCorrect();
	void drawHud(sf::RenderWindow &);
	void updatePosition(sf::Vector2f);
	void updateHpAndMp(Statistics&);
};