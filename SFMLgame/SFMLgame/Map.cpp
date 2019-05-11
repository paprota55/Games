#include "Map.h"
#include <string>


Map::Map()
{
}

Map::~Map()
{
	elements.erase(elements.begin(), elements.end());
	walkableElements.erase(walkableElements.begin(), walkableElements.end());
	protectedElements.erase(protectedElements.begin(), protectedElements.end());
}

void Map::createMap()
{
	DataManager manager;
	int width, height;
	std::string floorName;
	manager.mapFloorCfg(floorName, height, width, size);
	renderFloor(floorName, height, width, size);	
	manager.loadObjects(walkableElements,protectedElements);
}

void Map::drawMap(sf::RenderWindow &window)
{
	for (int i = 0; i < size*size; i++)
		elements[i]->drawElement(window);
	int _size = walkableElements.size();
	for(int i = 0; i<_size;i++)
		walkableElements[i]->drawElement(window);
	_size = protectedElements.size();
	for (int i = 0; i < _size; i++)
		protectedElements[i]->drawElement(window);
}

void Map::renderFloor(std::string & floorName, int & height, int & width, int & size)
{
	int currWidth = 0;
	int currHeight = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			elements.push_back(new MapElement(floorName, sf::IntRect(0, 0, width, height),sf::Vector2f(currWidth,currHeight)));
			currWidth += width;
		}
		currWidth = 0;
		currHeight += height;
	}
}

void Map::update()
{
	DataManager manager;
	walkableElements.erase(walkableElements.begin(), walkableElements.end());
	protectedElements.erase(protectedElements.begin(), protectedElements.end());
	manager.loadObjects(walkableElements,protectedElements);
}



