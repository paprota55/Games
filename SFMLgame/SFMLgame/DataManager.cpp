#include "DataManager.h"



DataManager::DataManager()
{
}


DataManager::~DataManager()
{
}

void DataManager::mapFloorCfg(std::string & floorName, int & height, int & width, int &size)
{
	std::fstream file;
	file.open("maps/floorCFG.txt");
	if (file.is_open())
	{
		file >> height;
		file >> width;
		file >> size;
		file >> floorName;
	}
}

void DataManager::outfitCFG(sf::Texture & texture, sf::IntRect & rectangle, float & speed)
{
	std::fstream file;
	std::string textureName;
	file.open("outfits/outfitCFG.txt");
	if (file.is_open())
	{
		file >> textureName;
		texture.loadFromFile(textureName);
		file >> rectangle.left;
		file >> rectangle.top;
		file >> rectangle.width;
		file >> rectangle.height;
		file >> speed;
	}
}
