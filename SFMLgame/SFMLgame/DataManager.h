#pragma once
#include<string>
#include<fstream>
#include<cstdio>
#include "Character.h"

class DataManager
{
	std::string mapNameTxt;
	std::string objectsTxt;
	std::string characterTxt;
public:
	DataManager();
	~DataManager();

	void loadMap(Map&);
	void mapFloorCfg(std::string & floorName, int &height, int &width, int& size);
	void loadCharacter(Character &);
	void loadStatistics(Statistics &, std::fstream & file);
	void loadObjects(std::vector<std::shared_ptr<MapElement>>&, std::vector<std::shared_ptr<MapElement>>&);

	void saveCharacter(Character &);
	void saveStatistics(Statistics &, std::fstream &);
};