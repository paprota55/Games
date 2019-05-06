#pragma once
#include<SFML/Graphics.hpp>
#include"Character.h"
#include"Map.h"
class Animations
{
public:
	Animations();
	~Animations();

	void mapAnimation(Map& map);
};
