#include "MapElement.h"
#include<iostream>


MapElement::MapElement()
{
	texture.loadFromFile("maps/dick1.png");
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(0, 0, 800, 800));
}

MapElement::MapElement(std::string textureName,sf::IntRect rectSize)
{
	texture.loadFromFile(textureName);
	sprite.setTexture(texture);
	sprite.setTextureRect(rectSize);
}

MapElement::~MapElement()
{
}

sf::Sprite & MapElement::getElement()
{
	return sprite;
	// TODO: insert return statement here
}

void MapElement::drawElement(sf::RenderWindow &window)
{
	//std::cout << sprite.getPosition().x << " " << sprite.getPosition().y << std::endl;
	window.draw(sprite);
}

