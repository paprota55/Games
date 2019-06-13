#pragma once
#include<SFML/Graphics.hpp>
#include"Statistics.h"
#include"Map.h"
#include "Monster.h"
#include "Heal.h"
#include "SpeedUp.h"
#include"AutoAttack.h"
#include"MagicBall.h"

class Animations
{
	sf::Clock clock, healClock, autoAttackClock,speedClock,magicBallClock;

public:
	Animations();
	~Animations();

	void speedUpAnim(std::vector<std::shared_ptr<SpeedUp>>&);
	void magicBallAnim(std::vector<std::shared_ptr<MagicBall>>&);
	void healAnim(std::vector<std::shared_ptr<Heal>>&);
	void autoAttacAnim(std::vector<std::shared_ptr<AutoAttack>>&);
	void monsterMove(sf::Sprite&,int switcher, sf::Clock &);
	void characterMove(Statistics&, int &, sf::Sprite&);
};
