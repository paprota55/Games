#include "MagicBall.h"



MagicBall::MagicBall()
{
}

MagicBall::MagicBall(std::string name, sf::IntRect & rect, sf::Vector2f position, int rot)
{
	rotation = rot;
	texture.loadFromFile(name);
	sprite.setTexture(texture);
	sprite.setTextureRect(rect);
	correctPosition(position, rotation);
	sprite.setPosition(position);
	time = 0.70;
}

void MagicBall::correctPosition(sf::Vector2f &position, int rotation)
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


MagicBall::~MagicBall()
{
}

bool MagicBall::isExpired()
{
	if (expired.getElapsedTime().asSeconds() > time) return true;
	return false;
}

sf::Sprite & MagicBall::getSprite()
{
	return sprite;
}

void MagicBall::draw(sf::RenderWindow &window)
{
	window.draw(sprite);
}

void MagicBall::decreaseMana(Statistics &stats)
{
	int mana = stats.getCurrMp() - stats.getCurrMp()*0.2;
	if (mana < 0)
		mana = 0;
	stats.setCurrMp(mana);
}

void MagicBall::decreaseExpiredTime()
{
	time = 0;
}

void MagicBall::move()
{
	float moveSpeed = 5.0f;
	if (rotation == 1)
	{
		sprite.move(0.0f, -moveSpeed);
	}
	else if (rotation == 2)
	{
		sprite.move(moveSpeed, 0.0f);
	}
	else if (rotation == 3)
	{
		sprite.move(0.0f, moveSpeed);
	}
	else if (rotation == 4)
	{
		sprite.move(-moveSpeed, 0.0f);
	}
}
