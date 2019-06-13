#pragma once
#include"SFML/Graphics.hpp"
#include"Statistics.h"

class MagicBall
{
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Clock expired;
	int rotation;
	float time;
public:
	MagicBall();
	MagicBall(std::string name, sf::IntRect & rect, sf::Vector2f, int);
	void correctPosition(sf::Vector2f&, int);
	~MagicBall();
	bool isExpired();
	sf::Sprite & getSprite();
	void draw(sf::RenderWindow&);
	void decreaseMana(Statistics&);
	void decreaseExpiredTime();
	void move();
};

