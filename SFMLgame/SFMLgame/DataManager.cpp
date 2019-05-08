#include "DataManager.h"



DataManager::DataManager()
{
	objectsTxt = "object/objectCFG.txt";
	mapNameTxt = "maps/floorCFG.txt";
	outfitsTxt = "outfits/outfitCFG.txt";
}


DataManager::~DataManager()
{
}

void DataManager::mapFloorCfg(std::string & floorName, int & height, int & width, int &size)
{
	std::fstream file;
	file.open(mapNameTxt);
	if (file.is_open())
	{
		file >> height;
		file >> width;
		file >> size;
		file >> floorName;
	}
	file.close();
}

void DataManager::outfitCFG(sf::Texture & texture, sf::IntRect & rectangle, float & speed)
{
	std::fstream file;
	std::string textureName;
	file.open(outfitsTxt);
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
	file.close();
}

void DataManager::loadObjects(std::vector<MapElement*>& objects)
{
	std::fstream file;
	file.open(objectsTxt);
	std::string textureName;
	sf::IntRect objectRect;
	int posX, posY, touchable;
	if (file.is_open())
	{
		while (!file.eof())
		{
			file >> textureName;
			file >> objectRect.left;
			file >> objectRect.top;
			file >> objectRect.width;
			file >> objectRect.height;
			file >> posX >> posY;
			objects.push_back(new MapElement(textureName, objectRect, sf::Vector2f(posX, posY)));
		}
	}
	file.close();
}