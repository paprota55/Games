#pragma once
#include<vector>
#include"MapElement.h"
#include"DataManager.h"

class Map
{
public:
	std::vector<MapElement*> elements;
	MapElement element;
	int size;
public:
	Map();
	~Map();

	void createMap();
	void drawMap(sf::RenderWindow &window);
};

