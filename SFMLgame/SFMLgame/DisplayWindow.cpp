#include "DisplayWindow.h"
#include "DataManager.h"

DisplayWindow::DisplayWindow():width(1920),height(1080),window(sf::VideoMode(width, height), "Fantasy World", sf::Style::Fullscreen)
{	
	window.setVerticalSyncEnabled(true);
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
	miniMapView = view;
	view.move(48.f, 192.f);
	miniMapView.setViewport(sf::FloatRect(0.8, 0, 0.20, 0.25));
	miniMapView.zoom(1.75);
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
	int tmpW = 455;
	int tmpH = 310;

	updateViewRange(oldPosition, tmpW, tmpH, width, height);

	return oldPosition;
}

void DisplayWindow::updateViewRange(sf::Vector2f &oldPosition, int &tmpW, int &tmpH, int &width, int &height)
{
	int correctionH = 48;
	int correctionW = 192;

	if (oldPosition.x < tmpW)
	{
		oldPosition.x = tmpW;
	}
	else if (oldPosition.x > width - tmpW - correctionW)
	{
		oldPosition.x = width - tmpW - correctionW;
	}
	if (oldPosition.y < tmpH)
	{
		oldPosition.y = tmpH;
	}
	else if (oldPosition.y > height - tmpH - correctionH)
	{
		oldPosition.y = height - tmpH- correctionH;
	}
}

sf::Vector2f DisplayWindow::getViewPos()
{
	return view.getCenter();
}

void DisplayWindow::setMapView()
{
	window.setView(view);
}

void DisplayWindow::setMiniMapView()
{
	window.setView(miniMapView);
}
