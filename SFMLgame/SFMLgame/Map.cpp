#include "Map.h"
#include <string>
#include <thread>

Map::Map()
{
}

Map::~Map()
{
	walkableElements.clear();
	protectedElements.clear();
}

void Map::drawMap(sf::RenderWindow &window)
{
	drawFloor(window);
	drawObjectsFromList(walkableElements, window);
	drawObjectsFromList(protectedElements, window);
}

void Map::setFloor(std::string & floorName, int & height, int & width, int & size)
{
	int currWidth = 0;
	int currHeight = 0;
	brick.setElement(floorName, sf::IntRect(0, 0, width, height), sf::Vector2f(0,0));
}

void Map::createMapFrame(std::vector<std::shared_ptr<MapElement>>& objectList)
{
	int height, width;
	height = brick.getElement().getTextureRect().height * size;
	width = brick.getElement().getTextureRect().width * size;
	
	objectList.insert(objectList.begin(), std::shared_ptr<MapElement>(new MapElement("maps/water.png", sf::IntRect(0, 0, width, 1), sf::Vector2f(0, -1))));
	objectList.insert(objectList.begin(), std::shared_ptr<MapElement>(new MapElement("maps/water.png", sf::IntRect(0, 0, width, 1), sf::Vector2f(0, height))));
	objectList.insert(objectList.begin(), std::shared_ptr<MapElement>(new MapElement("maps/water.png", sf::IntRect(0, 0, 1, height), sf::Vector2f(width-90, 0))));
	objectList.insert(objectList.begin(), std::shared_ptr<MapElement>(new MapElement("maps/water.png", sf::IntRect(0, 0, 1, height), sf::Vector2f(-1, 0))));
}

void Map::drawObjectsFromList(std::vector<std::shared_ptr<MapElement>>& objectList, sf::RenderWindow & window)
{
	std::vector<std::shared_ptr<MapElement>>::iterator ptr;
	for (ptr = objectList.begin(); ptr != objectList.end(); ptr++)
		(*ptr)->drawElement(window);
}

void Map::drawFloor(sf::RenderWindow & window)
{
	int currWidth = 0;
	int currHeight = 0;
	short int width = brick.sprite.getTextureRect().width;
	short int height = brick.sprite.getTextureRect().height;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			brick.setPosition(sf::Vector2f(currWidth, currHeight));
			brick.drawElement(window);
			currWidth += width;
		}
		currWidth = 0;
		currHeight += height;
	}
}

std::vector<std::shared_ptr<MapElement>> &Map::getProtectedElements()
{
	return protectedElements;
}

std::vector<std::shared_ptr<MapElement>>& Map::getUnProtectedElements()
{
	return walkableElements;
}

int & Map::getSize()
{
	return size;
}