#pragma once
#include<SFML/Graphics.hpp>

class DisplayWindow
{
	float width, height;
	sf::RenderWindow window;

public:
	DisplayWindow();
	~DisplayWindow();

	sf::RenderWindow & getWindow();
};

