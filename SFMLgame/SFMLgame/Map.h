#pragma once
#include <SFML/Graphics.hpp>
class Map
{
	sf::Texture texture;
	sf::Sprite sprite;
	sf::IntRect rectSourceSprite;

	float width, height;

public:
	Map();
	~Map();

	void changeMap(std::string x);

	sf::Sprite& getMap();
};

