#pragma once
#include "DisplayWindow.h"
#include "Character.h"
#include "Map.h"
#include "Animations.h"
class Game
{
	DisplayWindow window;
	sf::Event event;
	Character character;
	Map map;
	Animations animation;
public:
	
	Game();
	~Game();

	void loop();
};

