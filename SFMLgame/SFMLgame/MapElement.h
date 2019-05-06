#pragma once
#include <SFML/Graphics.hpp>
#include<string>

class MapElement
{
public:
	sf::Texture texture;
	sf::Sprite sprite;

public:
	MapElement();
	MapElement(std::string textureName, sf::IntRect rectSize);
	~MapElement();

	sf::Sprite & getElement();
	void drawElement(sf::RenderWindow& window);
};

