#pragma once
#include<SFML/Graphics.hpp>
#include"Statistics.h"
#include"Animations.h"
#include<iostream>
#include"Map.h"


class Character
{
	sf::Texture texture;
	sf::IntRect rectSourceSprite;
	sf::Sprite sprite;
	sf::Clock clock;
	std::string textureName;

	int rotation;
	Statistics stats;

public:
	Character();
	~Character();

	sf::IntRect & getRect();
	sf::Texture & getTexture();
	sf::Sprite & getSprite();
	Statistics & getStats();
	std::string & getName();

	void setTextureName(std::string &);

	//animations
	void animation();

	//movement logic
	void move(std::vector<std::shared_ptr<MapElement>>);
	sf::Vector2f getPosition();

	//drawing
	void drawCharacter(sf::RenderWindow &window);
	void drawCoordinates(sf::RenderWindow &window);

	bool collision(std::vector<std::shared_ptr<MapElement>>);
};