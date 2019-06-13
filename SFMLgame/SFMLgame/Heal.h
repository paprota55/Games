#pragma once
#include "Statistics.h"

class Heal
{
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Clock expired;

public:
	Heal();
	Heal(std::string name, sf::IntRect & rect);
	~Heal();
	sf::Sprite & getSprite();
	void healCharacter(Statistics&);
	void decreaseMana(Statistics&);
	bool isExpired();
	void updatePosition(sf::Vector2f);
	void draw(sf::RenderWindow&);
};

