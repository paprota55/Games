#include "DataManager.h"


DataManager::DataManager()
{
	objectsTxt = "objects/objectCFG.txt";
	mapNameTxt = "maps/floorCFG.txt";
	characterTxt = "outfits/characterCFG.txt";
	hudTxt = "HUD/hudCFG.txt";
	correctTextPositionTxt = "Fonts/correctPos.txt";
	monsterTxt = "monsters/monsterCFG.txt";
	errorLog = "ERROR_LOG.txt";
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
	file.open(mapNameTxt, std::ios::in);
	if (file.good())
	{
		if (file.is_open())
		{
			file >> height;
			file >> width;
			file >> size;
			file >> floorName;
			file.close();
		}
		else
		{
			std::string except = "File floorCFG.txt could not be opened.\nGo to folder maps and check file.\n If you haven't file or you don't know what to do, copy file floorCFG.txt from folder main to this location.\n";
			throw except;
		}
	}
	else
	{
		std::string except = "File floorCFG.txt have unexpected error.\nGo to folder maps and check file.\n If you haven't file or you don't know what to do, copy file floorCFG.txt from folder main to this location.\n";
		throw except;
	}
}

void DataManager::loadCharacter(Character & character)
{
	std::fstream file;
	std::string textureName;
	sf::Vector2f position;
	file.open(characterTxt, std::ios::in);
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
			character.getSprite().setTexture(character.getTexture());
			character.getSprite().setTextureRect(character.getRect());
			character.getTexture().setSmooth(true);
			character.getSprite().setOrigin(character.getSprite().getOrigin() / 2.0f);
			file >> position.x;
			file >> position.y;
			character.getSprite().setPosition(position);
			loadStatistics(character.getStats(), file);
			file.close();
		}
		else
		{
			int except = 1;
			throw except;
		}
	}
	else
	{
		int except = 1;
		throw except;
	}
}

void DataManager::loadStatistics(Statistics & stats, std::fstream & file)
{
	int statsTmp;
	float speed;
	file >> speed;
	stats.setMoveSpeed(speed);
	file >> statsTmp;
	stats.setLevel(statsTmp);
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
	stats.setIntelligence(statsTmp);
	file >> statsTmp;
	stats.setArmor(statsTmp);
	file >> statsTmp;
	stats.setPoints(statsTmp);
}

void DataManager::loadObjects(std::vector<std::shared_ptr<MapElement>>& objectsUnprotected, std::vector<std::shared_ptr<MapElement>>& objectsProtected)
{
	std::fstream file;
	file.open(objectsTxt, std::ios::in);
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
			file.close();
		}
		else
		{
			std::string except = "File objectCFG.txt could not be opened.\nGo to folder objects and check file.\n If you haven't file or you don't know what to do, copy file objectCFG.txt from folder main to this location.\n";
			throw except;
		}
	}
	else
	{
		std::string except = "File objectCFG.txt have unexpected error.\nGo to folder objects and check file.\n If you haven't file or you don't know what to do, copy file objectCFG.txt from folder main to this location.\n";
		throw except;
	}
}

void DataManager::loadHUD(HUD &hud)
{
	std::fstream file;
	std::string name;
	sf::IntRect rectangle;
	int posX, posY;
	

	file.open(hudTxt, std::ios::in);
	if (file.good())
	{
		if (file.is_open())
		{
			while (!file.eof())
			{
				file >> name;
				file >> rectangle.left;
				file >> rectangle.top;
				file >> rectangle.width;
				file >> rectangle.height;
				file >> posX >> posY;
				hud.getHudElements().push_back(std::shared_ptr<MapElement>(new MapElement(name, rectangle, sf::Vector2f(posX, posY))));
				hud.getCorrect().push_back(sf::Vector2f(posX, posY));
			}
			file.close();
		}
		else
		{
			std::string except = "File hudCFG.txt could not be opened.\nGo to folder HUD and check file.\n If you haven't file or you don't know what to do, copy file hudCFG.txt from folder main to this location.\n";
			throw except;
		}
	}
	else
	{
		std::string except = "File hudCFG.txt have unexpected error.\nGo to folder HUD and check file.\n If you haven't file or you don't know what to do, copy file hudCFG.txt from folder main to this location.\n";
		throw except;
	}
	loadTextHud(hud);
}

void DataManager::loadTextHud(HUD &hud)
{
	std::fstream file;
	int posX, posY;

	file.open(correctTextPositionTxt, std::ios::in);

	if (file.good())
	{
		if (file.is_open())
		{
			while (!file.eof())
			{
				file >> posX >> posY;
				hud.getTextCorrect().push_back(sf::Vector2f(posX, posY));
			}
			file.close();
		}
		else
		{
			std::string except = "File correctPos.txt could not be opened.\nGo to folder Fonts and check file.\n If you haven't file or you don't know what to do, copy file correctPos.txt from folder main to this location.\n";
			throw except;
		}
	}
	else
	{
		std::string except = "File correctPos.txt have unexpected error.\nGo to folder Fonts and check file.\n If you haven't file or you don't know what to do, copy file correctPos.txt from folder main to this location.\n";
		throw except;
	}


}

void DataManager::loadMonsters(std::vector<std::shared_ptr<Monster>>&monsterList)
{
	std::fstream file;
	file.open(monsterTxt, std::ios::in);
	std::string textureName;
	sf::IntRect objectRect;
	int posX, posY,hp,exp,attack,follow;
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
				file >> posX >> posY >> hp >> exp >> attack >> follow;
				monsterList.insert(monsterList.begin(), std::shared_ptr<Monster>(new Monster(textureName, objectRect, hp, exp, attack, follow, sf::Vector2f(posX, posY))));
			}
			file.close();
		}
		else
		{
			std::string except = "File monsterCFG.txt could not be opened.\nGo to folder monsters and check file.\n If you haven't file or you don't know what to do, copy file monsterCFG.txt from folder main to this location.\n";
			throw except;
		}
	}
	else
	{
		std::string except = "File monsterCFG.txt have unexpected error.\nGo to folder monsters and check file.\n If you haven't file or you don't know what to do, copy file monsterCFG.txt from folder main to this location.\n";
		throw except;
	}
}

void DataManager::loadAll(Map &map, Character &character, HUD &hud, std::vector<std::shared_ptr<Monster>>&monsters,sf::RenderWindow& window)
{
	try
	{
		loadMap(map);
		loadCharacter(character);
		loadHUD(hud);
		loadMonsters(monsters);
	}
	catch(std::string except)
	{
		std::fstream file;
		file.open(errorLog, std::ios::out);
		file << except;
		file.close();
		window.close();
		std::cout << "Check ERROR_LOG in game folder\n";
		system("Pause");
		system("start ERROR_LOG.txt");
		exit(1);
	}
	catch (int except)
	{
		std::fstream file;
		file.open(characterTxt, std::ios::out);
		file << "outfits/1.png\n";
		for (int i = 0; i < 4; i++)
		{
			file << 48 << " ";
		}
		file << "\n";
		file << 3300 << " ";
		file << 3300 << "\n";
		file << 3.5<<"\n";
		file << 1 << "\n";
		file << 200 << " " << 200 << "\n";
		file << 200 << " " << 200 << "\n";
		file << 200 << " " << 0 << "\n";
		file << 1 << "\n";
		file << 1 << "\n";
		file << 1 << "\n";
		file << 0 << "\n";
		file.close();
		window.close();
		file.open(errorLog, std::ios::out);
		file<<"File characterCFG.txt have unexpected problem so we need to delete your character status and create new.\nI apologise for problems.";
		file.close();
		std::cout << "Check ERROR_LOG in game folder\n";
		system("Pause");
		system("start ERROR_LOG.txt");
		exit(1);
	}
}

void DataManager::saveCharacter(Character & character)
{
	std::fstream file;
	file.open(characterTxt,std::ios::out);
	if (file.good())
	{
		if (file.is_open())
		{
			file << character.getName() << "\n";
			file << character.getRect().left << " ";
			file << character.getRect().top << " ";
			file << character.getRect().width << " ";
			file << character.getRect().height << "\n";
			file << character.getSprite().getPosition().x << " ";
			file << character.getSprite().getPosition().y << "\n";
			saveStatistics(character.getStats(), file);
		}
	}
	file.close();
}

void DataManager::saveStatistics(Statistics & stats, std::fstream & file)
{
	file << stats.getMoveSpeed() << "\n";
	file << stats.getLevel() << "\n";
	file << stats.getHealth() << " ";
	file << stats.getCurrHp() << "\n";
	file << stats.getMana() << " ";
	file << stats.getCurrMp() << "\n";
	file << stats.getExpToLvl() << " ";
	file << stats.getExp() << "\n";
	file << stats.getAttackDmg() << "\n";
	file << stats.getIntelligence() << "\n";
	file << stats.getArmor() << "\n";
	file << stats.getPoints() << "\n";
}