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
