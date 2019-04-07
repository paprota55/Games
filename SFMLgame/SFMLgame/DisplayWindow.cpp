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
