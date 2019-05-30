#include "DataManager.h"


DataManager::DataManager()
{
	objectsTxt = "objects/objectCFG.txt";
	mapNameTxt = "maps/floorCFG.txt";
	characterTxt = "outfits/characterCFG.txt";
}

DataManager::~DataManager()
{
}

void DataManager::loadMap(Map &map)
{
	int width, height;
	std::string floorName;
	mapFloorCfg(floorName, height, width, map.getSize());
	map.setFloor(floorName, height, width, map.getSize());
	map.createMapFrame(map.getProtectedElements());
	loadObjects(map.getUnProtectedElements(), map.getProtectedElements());
}

void DataManager::mapFloorCfg(std::string & floorName, int & height, int & width, int &size)
{
	std::fstream file;
	file.open(mapNameTxt);
	if (file.good())
	{
		if (file.is_open())
		{
			file >> height;
			file >> width;
			file >> size;
			file >> floorName;
		}
	}
	file.close();
}

void DataManager::loadCharacter(Character & character)
{
	std::fstream file;
	std::string textureName;
	sf::Vector2f position;
	file.open(characterTxt);
	if (file.good())
	{
		if (file.is_open())
		{
			file >> textureName;
			character.setTextureName(textureName);
			character.getTexture().loadFromFile(textureName);
			file >> character.getRect().left;
			file >> character.getRect().top;
			file >> character.getRect().width;
			file >> character.getRect().height;
			file >> character.getSpeed();
			character.getSprite().setTexture(character.getTexture());
			character.getSprite().setTextureRect(character.getRect());
			character.getTexture().setSmooth(true);
			character.getSprite().setOrigin(character.getSprite().getOrigin() / 2.0f);
			file >> position.x;
			file >> position.y;
			character.getSprite().setPosition(position);
			loadStatistics(character.getStats(), file);
		}
	}
	file.close();
}

void DataManager::loadStatistics(Statistics & stats, std::fstream & file)
{
	int statsTmp;
		file >> statsTmp;
			stats.setHealth(statsTmp);
			file >> statsTmp;
			stats.setCurrHp(statsTmp);
			file >> statsTmp;
			stats.setMana(statsTmp);
			file >> statsTmp;
			stats.setCurrMp(statsTmp);
			file >> statsTmp;
			stats.setExpToLvl(statsTmp);
			file >> statsTmp;
			stats.setExp(statsTmp);
			file >> statsTmp;
			stats.setAttackDmg(statsTmp);
			file >> statsTmp;
			stats.setAttackSpeed(statsTmp);
			file >> statsTmp;
			stats.setArmor(statsTmp);
			file >> statsTmp;
			stats.setDefense(statsTmp);
}

void DataManager::loadObjects(std::vector<std::shared_ptr<MapElement>>& objectsUnprotected, std::vector<std::shared_ptr<MapElement>>& objectsProtected)
{
	std::fstream file;
	file.open(objectsTxt);
	std::string textureName;
	sf::IntRect objectRect;
	int posX, posY, _protected, rotation;
	if (file.good())
	{
		if (file.is_open())
		{
			while (!file.eof())
			{
				file >> textureName;
				file >> objectRect.left;
				file >> objectRect.top;
				file >> objectRect.width;
				file >> objectRect.height;
				file >> posX >> posY >> rotation >> _protected;
				if (_protected == 0)
				{
					objectsUnprotected.insert(objectsUnprotected.begin(), std::shared_ptr<MapElement>(new MapElement(textureName, objectRect, sf::Vector2f(posX, posY))));
					objectsUnprotected.front()->sprite.setRotation(rotation);
				}
				else if (_protected == 1)
				{
					objectsProtected.insert(objectsProtected.begin(), std::shared_ptr<MapElement>(new MapElement(textureName, objectRect, sf::Vector2f(posX, posY))));
					objectsProtected.front()->sprite.setRotation(rotation);
				}
			}
		}
	}
	file.close();
}

void DataManager::saveCharacter(Character & character)
{
	std::fstream file;
	file.open(characterTxt);
	if (file.good())
	{
		if (file.is_open())
		{
			file << character.getName() << "\n";
			file << character.getRect().left << " ";
			file << character.getRect().top << " ";
			file << character.getRect().width << " ";
			file << character.getRect().height << "\n";
			file << character.getSpeed() << "\n";
			file << character.getSprite().getPosition().x << " ";
			file << character.getSprite().getPosition().y << "\n";
			saveStatistics(character.getStats(), file);
		}
	}
	file.close();
}

void DataManager::saveStatistics(Statistics & stats, std::fstream & file)
{
	file << stats.getHealth() << " ";
	file << stats.getCurrHp() << "\n";
	file << stats.getMana() << " ";
	file << stats.getCurrMp() << "\n";
	file << stats.getExpToLvl() << " ";
	file << stats.getExp() << "\n";
	file << stats.getAttackDmg() << "\n";
	file << stats.getAttackSpeed() << "\n";
	file << stats.getArmor() << "\n";
	file << stats.getDefense() << "\n";
}