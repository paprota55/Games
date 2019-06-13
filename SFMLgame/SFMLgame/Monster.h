#pragma once
#include<string>
#include<iostream>
#include"SFML/Graphics.hpp"
#include"Statistics.h"

class Monster
{
	int health, exp, attackDmg,follow;
	std::string name;
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Clock attackExhaust;
	sf::Clock movement;
public:
	Monster(std::string, sf::IntRect&, int&, int&, int&, int&,sf::Vector2f);
	~Monster();
	void attack(Statistics&);
	bool ifAgrresive();
	bool isAlive();
	void drawMonster(sf::RenderWindow&);
	sf::Vector2f getPosition();
	sf::Sprite & getMonster();
	void setFollow(int&);
	void decreaseHp(float&);
	int & getExp();
	sf::Clock & getClock();
};

