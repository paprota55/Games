#pragma once
#include<string>
#include<fstream>
class DataManager
{
public:
	DataManager();
	~DataManager();
	void mapFloorCfg(std::string & floorName, int &height, int &width, int& size);
};

