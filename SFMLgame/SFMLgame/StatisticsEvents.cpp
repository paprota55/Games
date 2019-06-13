#include "StatisticsEvents.h"


StatisticsEvents::StatisticsEvents()
{
}

StatisticsEvents::~StatisticsEvents()
{
}

void StatisticsEvents::checkEvents(DisplayWindow &window, Character &character)
{
	updateHp(character.getStats());
	updateMp(character.getStats());
	if (levelUp(character.getStats()))
	{
		updateAfterLevelUp(character.getStats());
		window.setViewCenter(character.getPosition());
		drawLevelUpOrDead(window.getWindow(), "HUD/levelup.png",character.getPosition());
	}
	else if (dead(character.getStats()))
	{
		updateAfterDead(character.getStats(), character.getSprite());
		window.setViewCenter(character.getPosition());
		drawLevelUpOrDead(window.getWindow(), "HUD/dead.png",character.getPosition());
	}
	addPoint(character.getStats());
}

void StatisticsEvents::updateMp(Statistics&stats)
{
	int exhaust = 1;
	if (manaClock.getElapsedTime().asSeconds() >= exhaust)
	{
		int updatedMp = stats.getCurrMp() + 0.01*stats.getMana();
		if (updatedMp > stats.getMana())
			updatedMp = stats.getMana();
		stats.setCurrMp(updatedMp);
		manaClock.restart();
	}
}

void StatisticsEvents::updateHp(Statistics&stats)
{
	int exhaust = 1;
	if (healthClock.getElapsedTime().asSeconds() >= exhaust)
	{
		int updatedHp = stats.getCurrHp() + 0.01*stats.getHealth();
		
		if (updatedHp > stats.getHealth())
			updatedHp = stats.getHealth();
		stats.setCurrHp(updatedHp);
		healthClock.restart();
	}
}

bool StatisticsEvents::levelUp(Statistics&stats)
{
	if (stats.getExp() >= stats.getExpToLvl()) return true;
	else return false;
}

bool StatisticsEvents::dead(Statistics&stats)
{
	if (stats.getCurrHp() <= 0) return true;
	else return false;
}

void StatisticsEvents::updateAfterLevelUp(Statistics&stats)
{
	int expLeft = stats.getExp() - stats.getExpToLvl();
	int exp = stats.getExpToLvl() + stats.getExpToLvl()*0.2;
	stats.setExp(expLeft);
	stats.setExpToLvl(exp);
	int health = stats.getHealth() + stats.getHealth()*0.2;
	stats.setHealth(health);
	stats.setCurrHp(health);
	int mana = stats.getMana() + stats.getMana()*0.2;
	stats.setMana(mana);
	stats.setCurrMp(mana);
	int level = stats.getLevel() + 1;
	stats.setLevel(level);
	int points = stats.getPoints() + 1;
	stats.setPoints(points);
}

void StatisticsEvents::updateAfterDead(Statistics&stats,sf::Sprite &sprite)
{
	int health = stats.getHealth();
	stats.setCurrHp(health);
	int mana = stats.getMana();
	stats.setCurrMp(mana);
	int exp = stats.getExp() - stats.getExpToLvl() *0.05;
	if (exp < 0) exp = 0;
	stats.setExp(exp);
	sprite.setPosition(sf::Vector2f(3300.f, 3300.f));
}

void StatisticsEvents::addPoint(Statistics &stats)
{
	if (stats.getPoints() > 0 && addPointExhaust.getElapsedTime().asMilliseconds() > 200)
	{
		int points = stats.getPoints();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
		{
			int attackDmg = stats.getAttackDmg() + 1;
			points--;
			stats.setAttackDmg(attackDmg);
			addPointExhaust.restart();
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
		{
			int intelligence = stats.getIntelligence() + 1;
			points--;
			stats.setIntelligence(intelligence);
			addPointExhaust.restart();
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
		{
			int armor = stats.getArmor() + 1;
			points--;
			stats.setArmor(armor);
			addPointExhaust.restart();
		}
		stats.setPoints(points);
	}
}

void StatisticsEvents::increaseExp(Statistics &stats,int mnstrExp)
{
	int currExp = stats.getExp() + mnstrExp;
	stats.setExp(currExp);
}

void StatisticsEvents::drawLevelUpOrDead(sf::RenderWindow &window, std::string name,sf::Vector2f position)
{
	sf::Texture texture;
	sf::Sprite sprite;
	sf::IntRect rectangle;
	rectangle.height = 1080;
	rectangle.width = 1920;
	rectangle.left = 0;
	rectangle.top = 0;
	texture.loadFromFile(name);
	sprite.setTexture(texture);
	sprite.setTextureRect(rectangle);
	position.x -= 980;
	position.y -= 450;
	sprite.setPosition(position);
	window.clear();
	window.draw(sprite);
	window.display();
	Sleep(2000);
}