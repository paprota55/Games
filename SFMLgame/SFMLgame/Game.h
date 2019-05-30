#pragma once
#include "DisplayWindow.h"
#include"DataManager.h"
#include<iostream>

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

