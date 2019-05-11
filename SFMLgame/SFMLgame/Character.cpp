#include "Character.h"

Character::Character(): clock()
{
	DataManager manager;
	manager.outfitCFG(texture, rectSourceSprite, moveSpeed);
	sprite.setTexture(texture);
	sprite.setTextureRect(rectSourceSprite);
	animationSpeed = moveSpeed /100.0f;
	texture.setSmooth(true);
	sprite.setOrigin(sprite.getOrigin() / 2.0f);
}

Character::~Character()
{
}

void Character::animation()
{
	int size = 48;
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) || sf::Keyboard::isKeyPressed(sf::Keyboard::RControl))) {
		rectSourceSprite.left = size;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) { rectSourceSprite.top = 3*size; rotation = 1; }
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) { rectSourceSprite.top = 0; rotation = 2; }
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) { rectSourceSprite.top = size; rotation = 3; }
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) { rectSourceSprite.top = 2*size; rotation = 4; }
	}
	else {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			rectSourceSprite.top = 3*size;
			rotation = 1;
			if (clock.getElapsedTime().asSeconds() > animationSpeed)
			{
				rectSourceSprite.left += size;
				clock.restart();
				if (rectSourceSprite.left >= 3*size)
				{
					rectSourceSprite.left = 0;
				}
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			rotation = 3;
			rectSourceSprite.top = 0;
			if (clock.getElapsedTime().asSeconds() > animationSpeed)
			{
				rectSourceSprite.left += size;
				clock.restart();
				if (rectSourceSprite.left >= 3*size)
				{
					rectSourceSprite.left = 0;
				}
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			rectSourceSprite.top = size;
			rotation = 4;
			if (clock.getElapsedTime().asSeconds() > animationSpeed)
			{
				rectSourceSprite.left += size;
				clock.restart();
				if (rectSourceSprite.left >= 3*size)
				{
					rectSourceSprite.left = 0;
				}
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			rectSourceSprite.top = 2*size;
			rotation = 2;
			if (clock.getElapsedTime().asSeconds() > animationSpeed)
			{
				rectSourceSprite.left += size;
				clock.restart();
				if (rectSourceSprite.left >= 3*size)
				{
					rectSourceSprite.left = 0;
				}
			}
		}
		else
		{
			rectSourceSprite.left = size;
		}
	}
	sprite.setTextureRect(rectSourceSprite);
}


sf::Sprite & Character::getSprite()
{
	return sprite;
}

void Character::move()
{
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) || sf::Keyboard::isKeyPressed(sf::Keyboard::RControl))) {}
	else {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			sprite.move(0.0f, -moveSpeed);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			sprite.move(0.0f, moveSpeed);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			sprite.move(-moveSpeed, 0.0f);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			sprite.move(moveSpeed, 0.0f);
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
}

void Character::update()
{
	DataManager manager;
	manager.outfitCFG(texture, rectSourceSprite, moveSpeed);
	sprite.setTexture(texture);
	sprite.setTextureRect(rectSourceSprite);
	animationSpeed = moveSpeed / 100.0f;
	texture.setSmooth(true);
	sprite.setOrigin(sprite.getOrigin() / 2.0f);
}


