#pragma once
#include"SFML/Graphics.hpp"

class Statistics
{
	int level,health, currHp, mana,currMp,experience, experienceToNextLevel, intelligence, attackDmg,armor, points;
	float moveSpeed;

public:
	Statistics();
	~Statistics();

	int getLevel();
	int getHealth();
	int getMana();
	int getExp();
	int getIntelligence();
	int getAttackDmg();
	int getArmor();
	int getExpToLvl();
	int getCurrHp();
	int getCurrMp();
	int getPoints();
	float getMoveSpeed();

	void setLevel(int &tmp);
	void setPoints(int &tmp);
	void setHealth(int &tmp);
	void setMana(int &tmp);
	void setExp(int &tmp);
	void setIntelligence(int &tmp);
	void setAttackDmg(int &tmp);
	void setMoveSpeed(float &tmp);
	void setArmor(int &tmp);
	void setExpToLvl(int &tmp);
	void setCurrHp(int &tmp);
	void setCurrMp(int &tmp);
};