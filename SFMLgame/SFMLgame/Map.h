#pragma once
#include<vector>
#include"MapElement.h"
#include"DataManager.h"

class Map
{
public:
	std::vector<MapElement*> elements;
	std::vector<MapElement*> walkableElements;
	std::vector<MapElement*> protectedElements;
	int size;
public:
	Map();
	~Map();

	void createMap();
	void drawMap(sf::RenderWindow &window);
	void renderFloor(std::string & floorName, int &height, int &width, int& size);
	void createObjects(std::vector<MapElement*>& objectList);
	void update();
};

