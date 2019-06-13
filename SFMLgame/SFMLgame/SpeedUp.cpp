#include "SpeedUp.h"



SpeedUp::SpeedUp()
{
}

SpeedUp::SpeedUp(std::string name, sf::IntRect & rect)
{
	texture.loadFromFile(name);
	sprite.setTexture(texture);
	sprite.setTextureRect(rect);
}


SpeedUp::~SpeedUp()
{
}

sf::Sprite & SpeedUp::getSprite()
{
	return sprite;
}

void SpeedUp::speedUpCharacter(Statistics &stats)
{
	float speed = stats.getMoveSpeed() + 1;
	stats.setMoveSpeed(speed);
}

void SpeedUp::decreaseMana(Statistics &stats)
{
	int mana = stats.getCurrMp() - stats.getCurrMp()*0.15;
	if (mana < 0)
		mana = 0;
	stats.setCurrMp(mana);
}

bool SpeedUp::isExpired(Statistics& stats)
{
	if (expired.getElapsedTime().asSeconds() > 10)
	{
		float speed = stats.getMoveSpeed() - 1;
		stats.setMoveSpeed(speed);
		return true;
	}

	return false;
}

void SpeedUp::updatePosition(sf::Vector2f position)
{
	sprite.setPosition(position);
}

void SpeedUp::draw(sf::RenderWindow &window)
{
	window.draw(sprite);
}
