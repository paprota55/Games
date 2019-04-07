#pragma once
#include<SFML/Graphics.hpp>
class Character
{
	sf::Texture texture;
	sf::IntRect rectSourceSprite;
	sf::Sprite sprite;
	sf::Clock clock;

	int rotation;

	float moveSpeed;
	float animationSpeed;

public:
	Character();
	~Character();

	//animations
	void animation();
	sf::Sprite& getSprite();

	//movement logic
	void move();
};

