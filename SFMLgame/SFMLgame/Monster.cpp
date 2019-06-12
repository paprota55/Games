#include "Monster.h"

Monster::Monster(std::string name, sf::IntRect & rect, int &hp, int &expp, int &attack, int &followw,sf::Vector2f position)
{
	texture.loadFromFile(name);
	texture.setSmooth(true);
	sprite.setTexture(texture);
	sprite.setTextureRect(rect);
	health = hp;
	exp = expp;
	attackDmg = attack;
	follow = followw;
	sprite.setPosition(position);
}

Monster::~Monster()
{
}

void Monster::attack(Statistics &stats)
{
	if (attackExhaust.getElapsedTime().asSeconds() > 2)
	{
		int hp = stats.getCurrHp() - attackDmg;
		stats.setCurrHp(hp);
		attackExhaust.restart();
	}
}

bool Monster::ifAgrresive()
{
	if (follow == 1) return true;

	return false;
}

bool Monster::isAlive()
{
	if (health <= 0) return false;
	
	return true;
}

void Monster::drawMonster(sf::RenderWindow &window)
{
	window.draw(sprite);
}

sf::Vector2f Monster::getPosition()
{
	return sprite.getPosition();
}

sf::Sprite & Monster::getMonster()
{
	return sprite;
}

void Monster::setFollow(int &tmp)
{
	follow = tmp;
}

sf::Clock & Monster::getClock()
{
	return movement;
}
