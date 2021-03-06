#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/Graphics/View.hpp>

class DisplayWindow
{
	float width, height;
	sf::RenderWindow window;
	sf::View view;
	sf::View miniMapView;

public:
	DisplayWindow();
	~DisplayWindow();

	sf::RenderWindow & getWindow();
	void setViewCenter(sf::Vector2f newPosition);
	sf::Vector2f setMapRange(sf::Vector2f);
	void updateViewRange(sf::Vector2f &oldPosition, int &tmpW, int &tmpH, int &width, int &height);
	sf::Vector2f getViewPos();
	void setMapView();
	void setMiniMapView();
};

