#pragma once
#include<SFML/Graphics.hpp>
#include"Statistics.h"

#include"Map.h"
#include"Monster.h"

class Animations
{
	sf::Clock clock;
public:
	Animations();
	~Animations();

	void speedUpAnim();
	void healAnim();
	void monsterMove(sf::Sprite&,int switcher, sf::Clock &);
	void characterMove(Statistics&, int &, sf::Sprite&);
};
