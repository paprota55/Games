#pragma once
#include"Statistics.h"
#include<iostream>

class Skills
{
	sf::Clock healExhaust,speedUpExhaust,speedExpired;
	int healTime,speedTime;
	
public:
	Skills();
	~Skills();
	void characterHeal(Statistics&);
	void speedUp(Statistics&);
	void checkClocks(Statistics&);
	void skillUpdater(Statistics&);
	void speedUpOff(Statistics&);

};

