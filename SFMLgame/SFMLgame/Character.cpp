#include "Character.h"



Character::Character():rectSourceSprite(0, 0, 48, 48), sprite(texture, rectSourceSprite),clock()
{
	texture.loadFromFile("outfits/sth.png");
	moveSpeed = 5.0f;
	animationSpeed = 0.05f;
	texture.setSmooth(true);
}


Character::~Character()
{
}

void Character::animation()
{
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) || sf::Keyboard::isKeyPressed(sf::Keyboard::RControl))) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) { rectSourceSprite.top = 144; rotation = 1; }
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) { rectSourceSprite.top = 0; rotation = 2; }
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) { rectSourceSprite.top = 48; rotation = 3; }
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) { rectSourceSprite.top = 96; rotation = 4; }
	}
	else {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			rectSourceSprite.top = 144;
			rotation = 1;
			if (clock.getElapsedTime().asSeconds() > animationSpeed)
			{
				rectSourceSprite.left += 48;
				clock.restart();
				if (rectSourceSprite.left >= 144)
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
				rectSourceSprite.left += 48;
				clock.restart();
				if (rectSourceSprite.left >= 144)
				{
					rectSourceSprite.left = 0;
				}
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			rectSourceSprite.top = 48;
			rotation = 4;
			if (clock.getElapsedTime().asSeconds() > animationSpeed)
			{
				rectSourceSprite.left += 48;
				clock.restart();
				if (rectSourceSprite.left >= 144)
				{
					rectSourceSprite.left = 0;
				}
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			rectSourceSprite.top = 96;
			rotation = 2;
			if (clock.getElapsedTime().asSeconds() > animationSpeed)
			{
				rectSourceSprite.left += 48;
				clock.restart();
				if (rectSourceSprite.left >= 144)
				{
					rectSourceSprite.left = 0;
				}
			}
		}
		else
		{
			rectSourceSprite.left = 48;
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
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			sprite.move(moveSpeed, 0.0f);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			sprite.move(-moveSpeed, 0.0f);
		}
	}
}
