#include "DisplayWindow.h"

DisplayWindow::DisplayWindow():width(1280),height(720),window(sf::VideoMode(width, height), "Fantasy World v.0")
{	
	window.setFramerateLimit(60);
}


DisplayWindow::~DisplayWindow()
{

}

sf::RenderWindow & DisplayWindow::getWindow()
{
	return window;
}

void DisplayWindow::setViewCenter(sf::Vector2f newPosition)
{
	view.setCenter(newPosition);
	view.setViewport(sf::FloatRect(0, 0, 1, 1.5));
	view.move(48.f, 192.f);
	window.setView(view);
}
