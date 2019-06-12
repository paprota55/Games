#pragma once
#include<string>
#include<iostream>
#include"SFML/Graphics.hpp"

class Monster
{
	int health, currHp, exp, level, attackDmg,attackable;
	std::string name;
	sf::Texture texture;
	sf::Sprite sprite;
public:
	Monster();
	~Monster();
	void move();
	void animation();
	void attack();
	bool isAlive();
};

