#pragma once
#include "DisplayWindow.h"
#include"DataManager.h"
#include"StatisticsEvents.h"
#include<iostream>

class Game
{
	DisplayWindow window;
	sf::Event event;
	Character character;
	Map map;
	HUD hud;
	StatisticsEvents statsUpdater;
public:
	
	Game();
	~Game();

	void loop();
};

