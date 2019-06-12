#include "Animations.h"



Animations::Animations()
{
}


Animations::~Animations()
{
}

void Animations::monsterMove(sf::Sprite&sprite,int switcher,sf::Clock & monsterClock)
{
	float animationSpeed = (1 / 3.0f) * 0.5f;;
	int size = 48;
	sf::IntRect rectSourceSprite = sprite.getTextureRect();

	if (switcher == 1)
	{
		rectSourceSprite.top = 3 * size;
		if (monsterClock.getElapsedTime().asSeconds() > animationSpeed)
		{
			rectSourceSprite.left += size;
			monsterClock.restart();
			if (rectSourceSprite.left >= 3 * size)
			{
				rectSourceSprite.left = 0;
			}
		}
	}
	else if (switcher == 2)
	{
		rectSourceSprite.top = 0;
		if (monsterClock.getElapsedTime().asSeconds() > animationSpeed)
		{
			rectSourceSprite.left += size;
			monsterClock.restart();
			if (rectSourceSprite.left >= 3 * size)
			{
				rectSourceSprite.left = 0;
			}
		}
	}
	else if (switcher == 3)
	{
		rectSourceSprite.top = size;
		if (monsterClock.getElapsedTime().asSeconds() > animationSpeed)
		{
			rectSourceSprite.left += size;
			monsterClock.restart();
			if (rectSourceSprite.left >= 3 * size)
			{
				rectSourceSprite.left = 0;
			}
		}
	}
	else if (switcher == 4)
	{
		rectSourceSprite.top = 2 * size;
		if (monsterClock.getElapsedTime().asSeconds() > animationSpeed)
		{
			rectSourceSprite.left += size;
			monsterClock.restart();
			if (rectSourceSprite.left >= 3 * size)
			{
				rectSourceSprite.left = 0;
			}
		}
	}
	else
	{
		rectSourceSprite.left = size;
	}
	sprite.setTextureRect(rectSourceSprite);
}


void Animations::characterMove(Statistics&stats, int &rotation,sf::Sprite&sprite)
{

	float animationSpeed = (1/stats.getMoveSpeed()) * 0.5f;
	sf::IntRect rectSourceSprite = sprite.getTextureRect();

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
