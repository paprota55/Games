#include "Statistics.h"



Statistics::Statistics()
{
}

Statistics::~Statistics()
{
}

int Statistics::getLevel()
{
	return level;
}

int Statistics::getHealth()
{
	return health;
}

int Statistics::getMana()
{
	return mana;
}

int Statistics::getExp()
{
	return experience;
}

int Statistics::getIntelligence()
{
	return intelligence;
}

int Statistics::getAttackDmg()
{
	return attackDmg;
}

int Statistics::getArmor()
{
	return armor;
}

int Statistics::getExpToLvl()
{
	return experienceToNextLevel;
}

int Statistics::getCurrHp()
{
	return currHp;
}

int Statistics::getCurrMp()
{
	return currMp;
}

int Statistics::getPoints()
{
	return points;
}

float Statistics::getMoveSpeed()
{
	return moveSpeed;
}

void Statistics::setLevel(int & tmp)
{
	level = tmp;
}

void Statistics::setPoints(int & tmp)
{
	points = tmp;
}

void Statistics::setHealth(int & tmp)
{
	health = tmp;
}

void Statistics::setMana(int & tmp)
{
	mana = tmp;
}

void Statistics::setExp(int & tmp)
{
	experience = tmp;
}

void Statistics::setIntelligence(int & tmp)
{
	intelligence = tmp;
}

void Statistics::setAttackDmg(int & tmp)
{
	attackDmg = tmp;
}

void Statistics::setMoveSpeed(float & tmp)
{
	moveSpeed = tmp;
}

void Statistics::setArmor(int & tmp)
{
	armor = tmp;
}

void Statistics::setExpToLvl(int & tmp)
{
	experienceToNextLevel = tmp;
}

void Statistics::setCurrHp(int & tmp)
{
	currHp = tmp;
}

void Statistics::setCurrMp(int & tmp)
{
	currMp = tmp;
}



