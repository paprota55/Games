#include "MapElement.h"
#include<iostream>


MapElement::MapElement()
{
}

MapElement::MapElement(std::string textureName,sf::IntRect rectSize)
{
	texture.loadFromFile(textureName);
	sprite.setTexture(texture);
	sprite.setTextureRect(rectSize);
}

MapElement::MapElement(std::string textureName, sf::IntRect rectSize, sf::Vector2f spritePosition)
{
	texture.loadFromFile(textureName);
	sprite.setTexture(texture);
	sprite.setTextureRect(rectSize);
	sprite.setPosition(spritePosition);
}

MapElement::~MapElement()
{
}

sf::Sprite & MapElement::getElement()
{
	return sprite;
}

void MapElement::drawElement(sf::RenderWindow &window)
{
	window.draw(sprite);
}

