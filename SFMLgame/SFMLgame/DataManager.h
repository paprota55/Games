#pragma once
#include<string>
#include<fstream>
#include"SFML/Graphics.hpp"

class DataManager
{
public:
	DataManager();
	~DataManager();
	void mapFloorCfg(std::string & floorName, int &height, int &width, int& size);
	void outfitCFG(sf::Texture &, sf::IntRect &, float &);
};

