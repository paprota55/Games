#pragma once
#include<string>
#include<fstream>
#include"SFML/Graphics.hpp"
#include "MapElement.h"

class DataManager
{
	std::string mapNameTxt;
	std::string objectsTxt;
	std::string outfitsTxt;
public:
	DataManager();
	~DataManager();

	void mapFloorCfg(std::string & floorName, int &height, int &width, int& size);
	void outfitCFG(sf::Texture &, sf::IntRect &, float &);
	void loadObjects(std::vector<MapElement*>&, std::vector<MapElement*>&);
};

