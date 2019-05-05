#pragma once
#include<SFML/Graphics.hpp>
#include"Character.h"
#include"Map.h"
class Animations
{
public:
	Animations();
	~Animations();

	void mapAnimation(Map& map);
};

class CharacterAnimations
{
	sf::Texture texture;
	sf::IntRect rectSourceSprite;
	sf::Sprite sprite;
	sf::Clock clock;
	float animationSpeed;

	sf::Vector2u imageCount;
	sf::Vector2u currentImage;

	float totalTime;
	float switchTime;

public:
	CharacterAnimations();
	CharacterAnimations(sf::Texture* texture, sf::Vector2u imageCount, float switchTime);
	~CharacterAnimations();

	void Update(int row, int rotation, float deltaTime);
};