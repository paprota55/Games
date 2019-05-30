#include "Statistics.h"



Statistics::Statistics()
{
}

Statistics::~Statistics()
{
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

int Statistics::getAttackSpeed()
{
	return attackSpeed;
}

int Statistics::getAttackDmg()
{
	return attackDmg;
}

int Statistics::getDefense()
{
	return defense;
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

void Statistics::setAttackSpeed(int & tmp)
{
	attackSpeed = tmp;
}

void Statistics::setAttackDmg(int & tmp)
{
	attackDmg = tmp;
}

void Statistics::setDefense(int & tmp)
{
	defense = tmp;
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