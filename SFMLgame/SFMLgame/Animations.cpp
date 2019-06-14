#include "Animations.h"



Animations::Animations()
{
}

Animations::~Animations()
{
}

void Animations::speedUpAnim(std::vector<std::shared_ptr<SpeedUp>>&speedList)
{
	float animationSpeed = 0.35f;
	std::vector<std::shared_ptr<SpeedUp>>::iterator ptr;
	for (ptr = speedList.begin(); ptr != speedList.end(); ptr++)
	{
		int size = 48;
		int counter = (*ptr)->getSprite().getTexture()->getSize().x / size;
		sf::Sprite sprite = (*ptr)->getSprite();
		sf::IntRect rectSourceSprite = (*ptr)->getSprite().getTextureRect();
		if (speedClock.getElapsedTime().asSeconds() > animationSpeed)
		{
			rectSourceSprite.left += size;
			speedClock.restart();
			if (rectSourceSprite.left >= counter * size)
			{
				rectSourceSprite.left = 0;
			}
		}
		(*ptr)->getSprite().setTextureRect(rectSourceSprite);
	}
}

void Animations::magicBallAnim(std::vector<std::shared_ptr<MagicBall>>&magicBallList)
{
	float animationSpeed = 0.10f;
	std::vector<std::shared_ptr<MagicBall>>::iterator ptr;
	for (ptr = magicBallList.begin(); ptr != magicBallList.end(); ptr++)
	{
		int size = 48;
		int counter = (*ptr)->getSprite().getTexture()->getSize().x / size;
		sf::Sprite sprite = (*ptr)->getSprite();
		sf::IntRect rectSourceSprite = (*ptr)->getSprite().getTextureRect();
		if (magicBallClock.getElapsedTime().asSeconds() > animationSpeed)
		{
			rectSourceSprite.left += size;
			magicBallClock.restart();
			if (rectSourceSprite.left >= counter * size)
			{
				rectSourceSprite.left = 0;
			}
		}
		(*ptr)->getSprite().setTextureRect(rectSourceSprite);
	}
}

void Animations::healAnim(std::vector<std::shared_ptr<Heal>>&healList)
{
	float animationSpeed = 0.35f;
	std::vector<std::shared_ptr<Heal>>::iterator ptr;
	for (ptr = healList.begin(); ptr != healList.end(); ptr++)
	{
		int size = 48;
		int counter = (*ptr)->getSprite().getTexture()->getSize().x / size;
		sf::Sprite sprite = (*ptr)->getSprite();
		sf::IntRect rectSourceSprite = (*ptr)->getSprite().getTextureRect();
		if (healClock.getElapsedTime().asSeconds() > animationSpeed)
		{
			rectSourceSprite.left += size;
			healClock.restart();
			if (rectSourceSprite.left >= 3 * size)
			{
				rectSourceSprite.left = 0;
			}
		}
		(*ptr)->getSprite().setTextureRect(rectSourceSprite);
	}
}

void Animations::autoAttacAnim(std::vector<std::shared_ptr<AutoAttack>>&autoAttackList)
{
	float animationSpeed = 0.05f;
	std::vector<std::shared_ptr<AutoAttack>>::iterator ptr;
	for (ptr = autoAttackList.begin(); ptr != autoAttackList.end(); ptr++)
	{
		int size = 48;
		int counter = (*ptr)->getSprite().getTexture()->getSize().x / size;
		sf::Sprite sprite = (*ptr)->getSprite();
		sf::IntRect rectSourceSprite = (*ptr)->getSprite().getTextureRect();
		if (autoAttackClock.getElapsedTime().asSeconds() > animationSpeed)
		{
			rectSourceSprite.left += size;
			autoAttackClock.restart();
			if (rectSourceSprite.left >= 7 * size)
			{
				rectSourceSprite.left = 0;
			}
		}
		(*ptr)->getSprite().setTextureRect(rectSourceSprite);
	}
}

void Animations::monsterMove(sf::Sprite&sprite,int switcher, sf::Clock & monsterClock)
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
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) { rectSourceSprite.top = 0; rotation = 3; }
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) { rectSourceSprite.top = size; rotation = 4; }
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) { rectSourceSprite.top = 2*size; rotation = 2; }
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
