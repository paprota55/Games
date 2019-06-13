#pragma once
#include "Statistics.h"

class SpeedUp
{
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Clock expired;

public:
	SpeedUp();
	SpeedUp(std::string name, sf::IntRect & rect);
	~SpeedUp();
	sf::Sprite & getSprite();
	void speedUpCharacter(Statistics&);
	void decreaseMana(Statistics&);
	bool isExpired(Statistics&);
	void updatePosition(sf::Vector2f);
	void draw(sf::RenderWindow&);
};