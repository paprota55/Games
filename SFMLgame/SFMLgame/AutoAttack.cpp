#include "AutoAttack.h"



AutoAttack::AutoAttack()
{
}

AutoAttack::AutoAttack(std::string name, sf::IntRect & rect, sf::Vector2f position, int rotation)
{
	dmg = true;
	texture.loadFromFile(name);
	sprite.setTexture(texture);
	sprite.setTextureRect(rect);
	correctPosition(position, rotation);
	sprite.setPosition(position);
}

AutoAttack::~AutoAttack()
{
}

sf::Sprite & AutoAttack::getSprite()
{
	return sprite;
}

bool AutoAttack::isExpired()
{
	if (expired.getElapsedTime().asSeconds() > 0.3) return true;

	return false;
}

void AutoAttack::correctPosition(sf::Vector2f &position,int rotation)
{
	int size = 48;
	if (rotation == 1)
	{
		position.y -= size;
	}
	else if (rotation == 2)
	{
		position.x += size;
	}
	else if (rotation == 3)
	{
		position.y += size;
	}
	else if (rotation == 4)
	{
		position.x -= size;
	}
}

void AutoAttack::draw(sf::RenderWindow &window)
{
	window.draw(sprite);
}

bool AutoAttack::getDmg()
{
	return dmg;
}

void AutoAttack::turnOffDmg()
{
	dmg = false;
}
