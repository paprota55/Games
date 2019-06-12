#pragma once
#include "DisplayWindow.h"
#include"DataManager.h"
#include"StatisticsEvents.h"
#include<iostream>
#include"MonstersContainer.h"
#include "Animations.h"

class Game
{
	DisplayWindow window;
	sf::Event event;
	Character character;
	Map map;
	HUD hud;
	StatisticsEvents statsUpdater;
	MonstersContainer monsters;
	Animations animation;

public:
	
	Game();
	~Game();

	void loop();
};

