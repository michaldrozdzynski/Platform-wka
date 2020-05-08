#pragma once
#include "Textures.h"
class Spikes
{
public:
	sf::Sprite s_spikes;
	Spikes(Textures& T,int position);
	void draw(sf::RenderWindow& window);
	int value;

};

