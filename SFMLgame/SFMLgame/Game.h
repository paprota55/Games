#pragma once
#include "DisplayWindow.h"
#include "Character.h"
#include "Map.h"
class Game
{
	DisplayWindow window;
	sf::Event event;
	Character character;
	Map map;
public:
	
	Game();
	~Game();

	void loop();
};

