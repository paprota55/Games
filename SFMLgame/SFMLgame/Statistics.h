#pragma once
class Statistics
{
	int health, currHp, mana,currMp,experience, experienceToNextLevel, attackSpeed, attackDmg,defense,armor;
public:
	Statistics();
	~Statistics();
	int getHealth();
	int getMana();
	int getExp();
	int getAttackSpeed();
	int getAttackDmg();
	int getDefense();
	int getArmor();
	int getExpToLvl();
	int getCurrHp();
	int getCurrMp();

	void setHealth(int &tmp);
	void setMana(int &tmp);
	void setExp(int &tmp);
	void setAttackSpeed(int &tmp);
	void setAttackDmg(int &tmp);
	void setDefense(int &tmp);
	void setArmor(int &tmp);
	void setExpToLvl(int &tmp);
	void setCurrHp(int &tmp);
	void setCurrMp(int &tmp);
};