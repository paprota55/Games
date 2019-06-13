#include "Character.h"

Character::Character()
{
}

Character::~Character()
{
}

sf::IntRect & Character::getRect()
{
	return rectSourceSprite;
}

sf::Texture & Character::getTexture()
{
	return texture;
}

sf::Sprite & Character::getSprite()
{
	return sprite;
}

Statistics & Character::getStats()
{
	return stats;
}

std::string & Character::getName()
{
	return textureName;
}

int & Character::getRotation()
{
	return rotation;
}

sf::Clock & Character::getClock()
{
	return clock;
}

Skills & Character::getSkills()
{
	return skills;
}

void Character::setTextureName(std::string &name)
{
	textureName = name;
}

void Character::checkSkills()
{
	skills.skillChoicer(stats,rotation,getPosition());
	skills.skillUpdater(getPosition());
}

void Character::drawSkills(sf::RenderWindow &window)
{
	skills.drawSkills(window);
}

void Character::move(std::vector<std::shared_ptr<MapElement>>elements, std::vector<std::shared_ptr<Monster>>monsterList)
{
	float moveSpeed = stats.getMoveSpeed();
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) || sf::Keyboard::isKeyPressed(sf::Keyboard::RControl))) {}

	else {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			sprite.move(0.0f, -moveSpeed);
			if(collision(elements,monsterList))
				sprite.move(0.0f, moveSpeed);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			sprite.move(0.0f, moveSpeed);
			if (collision(elements, monsterList))
				sprite.move(0.0f, -moveSpeed);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			sprite.move(-moveSpeed, 0.0f);
			if (collision(elements, monsterList))
				sprite.move(moveSpeed, 0.0f);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			sprite.move(moveSpeed, 0.0f);
			if (collision(elements, monsterList))
				sprite.move(-moveSpeed, 0.0f);
		}
	}
}

sf::Vector2f Character::getPosition()
{
	return sprite.getPosition();
}

void Character::drawCharacter(sf::RenderWindow & window)
{
	window.draw(sprite);
	drawCoordinates(window);
}

void Character::drawCoordinates(sf::RenderWindow & window)
{
}

bool Character::collision(std::vector<std::shared_ptr<MapElement>> elements, std::vector<std::shared_ptr<Monster>> monsterList)
{
	int _size = elements.size();

	for (int i = 0; i < _size; i++)
	{
		if (sprite.getGlobalBounds().intersects(elements[i]->sprite.getGlobalBounds()))
			return true;
	}
	_size = monsterList.size();
	for (int i = 0; i < _size; i++)
	{
		if (sprite.getGlobalBounds().intersects(monsterList[i]->getMonster().getGlobalBounds()))
			return true;
	}
	return false;
}