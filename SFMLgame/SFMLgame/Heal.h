#pragma once
#include "Statistics.h"
class Heal
{
	sf::Clock exhaust;

public:
	Heal();
	~Heal();
	void healCharacter(Statistics&);
};

