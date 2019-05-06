#include "DisplayWindow.h"
#include "DataManager.h"

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
	view.setCenter(setMapRange(newPosition));
	view.setViewport(sf::FloatRect(0, 0, 1, 1.5));
	view.move(48.f, 192.f);
	window.setView(view);
}

sf::Vector2f DisplayWindow::setMapRange(sf::Vector2f oldPosition)
{
	DataManager manager;
	int size,width,height;
	std::string floorName;

	manager.mapFloorCfg(floorName, height, width, size);
	height = height * size;
	width = width * size;

	if (oldPosition.x < 455)
	{
		oldPosition.x = 455;
	}
	if (oldPosition.y < 310)
	{
		oldPosition.y = 310;
	}

	return oldPosition;
}
