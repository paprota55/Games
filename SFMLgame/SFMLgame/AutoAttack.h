#pragma once
#include"Statistics.h"

class AutoAttack
{
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Clock expired;
	bool dmg;
public:
	AutoAttack();
	AutoAttack(std::string name, sf::IntRect & rect,sf::Vector2f,int);
	~AutoAttack();
	sf::Sprite & getSprite();
	bool isExpired();
	void correctPosition(sf::Vector2f&,int);
	void draw(sf::RenderWindow&);
	bool getDmg();
	void turnOffDmg();
};

