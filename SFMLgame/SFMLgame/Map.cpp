#include "Map.h"



Map::Map():rectSourceSprite(0, 0, 1280, 720), sprite(texture, rectSourceSprite)
{
	texture.loadFromFile("maps/temple.png");	
	sprite.setTextureRect(rectSourceSprite);
}


Map::~Map()
{
}

void Map::changeMap()
{
}

sf::Sprite & Map::getMap()
{
	return sprite;
}

