#include "Animations.h"



Animations::Animations()
{
}


Animations::~Animations()
{
}

void Animations::mapAnimation(Map & map)
{
}


CharacterAnimations::CharacterAnimations(sf::Texture * texture, sf::Vector2u imageCount, float switchTime)
{
	this->imageCount = imageCount;
	this->switchTime = switchTime;
	totalTime = 0.0f;
	currentImage.x = 0;

	rectSourceSprite.width = texture->getSize().x / float(imageCount.x);
	rectSourceSprite.height = texture->getSize().y / float(imageCount.y);
}

void CharacterAnimations::Update(int row, int rotation, float deltaTime)
{
	currentImage.y = row;
	totalTime += deltaTime;

	if (totalTime >= switchTime)
	{
		totalTime -= switchTime;
		currentImage.x++;

		if (currentImage.x >= imageCount.x)
		{
			currentImage.x = 0;
		}
	}

	rectSourceSprite.left = currentImage.x * rectSourceSprite.width;
	rectSourceSprite.top = currentImage.y * rectSourceSprite.height;
	rectSourceSprite.width = abs(rectSourceSprite.width);
}
