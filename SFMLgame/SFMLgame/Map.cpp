#include "Map.h"
#include <string>


Map::Map()
{
}

Map::~Map()
{
	elements.erase(elements.begin(), elements.end());
}

void Map::createMap()
{
	DataManager manager;
	int width, height;
	std::string floorName;
	manager.mapFloorCfg(floorName, height, width, size);

	int currWidth = 0;
	int currHeight = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			elements.push_back(new MapElement(floorName,sf::IntRect(0,0,width,height)));
			//elements[_size*i + j].getElement().setPosition(currWidth, currHeight);
			elements[size*i + j]->getElement().setPosition(currWidth, currHeight);
			currWidth += width;
		}
		currWidth = 0;
		currHeight += height;
	}
}

void Map::drawMap(sf::RenderWindow &window)
{
	for (int i = 0; i < size*size; i++)
	{
		elements[i]->drawElement(window);
	}
	//element.drawElement(window);
		//window.draw(elements[i].getElement());
	//window.draw(maps.getElement());
}


