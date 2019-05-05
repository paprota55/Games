#include "Map.h"
#include <string>


Map::Map():rectSourceSprite(0, 0, 1280, 720), sprite(texture, rectSourceSprite)
{
	texture.loadFromFile("maps/temple1.png");	
	sprite.setTextureRect(rectSourceSprite);
}


Map::~Map()
{
}

void Map::changeMap(std::string x)
{
	texture.loadFromFile(x);
}

sf::Sprite & Map::getMap()
{
	return sprite;
}

