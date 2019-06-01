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
	HUD hud;
public:
	
	Game();
	~Game();

	void loop();
};

