#pragma once
#include "SFML/Graphics.hpp"

class HUD
{
	std::vector<sf::Texture> textures;
	std::vector<sf::Sprite> sprites;
	std::vector<std::string> names;
public:
	HUD();
	~HUD();
};