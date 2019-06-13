#include "Heal.h"



Heal::Heal()
{
}


Heal::Heal(std::string name, sf::IntRect & rect)
{
	texture.loadFromFile(name);
	sprite.setTexture(texture);
	sprite.setTextureRect(rect);
}

Heal::~Heal()
{
}

sf::Sprite & Heal::getSprite()
{
	return sprite;
}

void Heal::healCharacter(Statistics &stats)
{
	int heal = stats.getCurrHp() + stats.getHealth() * 0.15;
	if (heal > stats.getHealth())
		heal = stats.getHealth();
	stats.setCurrHp(heal);
}

void Heal::decreaseMana(Statistics &stats)
{
	int mana = stats.getCurrMp() - stats.getCurrMp()*0.1;
	if (mana < 0)
		mana = 0;
	stats.setCurrMp(mana);
}

bool Heal::isExpired()
{
	if (expired.getElapsedTime().asSeconds() > 2) return true;

	return false;
}

void Heal::updatePosition(sf::Vector2f position)
{
	sprite.setPosition(position);
}

void Heal::draw(sf::RenderWindow &window)
{
	window.draw(sprite);
}
