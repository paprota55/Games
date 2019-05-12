#pragma once
#include<SFML/Graphics.hpp>
#include"Statistics.h"
#include"Animations.h"
#include<iostream>
#include"DataManager.h"


class Character
{
	sf::Texture texture;
	sf::IntRect rectSourceSprite;
	sf::Sprite sprite;
	sf::Clock clock;

	int rotation;

	float moveSpeed;
	float animationSpeed;
	Statistics stats;

public:
	Character();
	~Character();

	//animations
	void animation();
	sf::Sprite& getSprite();

	//movement logic
	void move(std::vector<MapElement*>);
	sf::Vector2f getPosition();

	//drawing
	void drawCharacter(sf::RenderWindow &window);
	void drawCoordinates(sf::RenderWindow &window);

	void update();

	bool collision(std::vector<MapElement*>);
};

