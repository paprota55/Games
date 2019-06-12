#pragma once
#include<vector>
#include"MapElement.h"
#include"Monster.h"

class Map
{
	MapElement brick;
	std::vector<std::shared_ptr<MapElement>> walkableElements;
	std::vector<std::shared_ptr<MapElement>> protectedElements;
	int size;
public:
	Map();
	~Map();

	void drawMap(sf::RenderWindow &window);
	void setFloor(std::string & floorName, int &height, int &width, int& size);
	void createMapFrame(std::vector<std::shared_ptr<MapElement>>& objectList);
	void drawObjectsFromList(std::vector<std::shared_ptr<MapElement>>& objectList, sf::RenderWindow & window);
	void drawFloor(sf::RenderWindow &window);
	std::vector<std::shared_ptr<MapElement>> & getProtectedElements();
	std::vector<std::shared_ptr<MapElement>> & getUnProtectedElements();
	int & getSize();
};

