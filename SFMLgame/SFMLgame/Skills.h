#pragma once
#include"Statistics.h"
#include<iostream>
#include"Heal.h"
#include"SpeedUp.h"
#include"AutoAttack.h"
#include"MagicBall.h"

class Skills
{
	sf::Clock healExhaust,speedExhaust, autoAttackExhaust,magicBallExhaust;
	float healTime,speedTime,autoAttackTime,magicBallTime;
	std::vector<std::shared_ptr<Heal>> healList;
	std::vector<std::shared_ptr<SpeedUp>> speedList;
	std::vector<std::shared_ptr<AutoAttack>> autoAttackList;
	std::vector<std::shared_ptr<MagicBall>> magicBallList;
	
public:
	Skills();
	~Skills();

	void skillChoicer(Statistics&,int,sf::Vector2f);
	void skillUpdater(sf::Vector2f);

	void drawSkills(sf::RenderWindow &);
	void expiredSkills(Statistics &);

	std::vector<std::shared_ptr<Heal>> & getHealList();
	std::vector<std::shared_ptr<SpeedUp>> & getSpeedList();
	std::vector<std::shared_ptr<AutoAttack>> & getAutoAttackList();
	std::vector<std::shared_ptr<MagicBall>> & getMagicBallList();
};

