#pragma once
#include "Textures.h"
#include <vector>
#include "Lands.h"
class Hero
{	
	int clock;
public:
	bool jumping;
	int jumpStage;
	int fallStage;
	sf::FloatRect position;
	sf::Sprite s_hero;
	bool inviolability;
	int inv;
	Hero(Textures &T);
	void move(bool);
	bool jump();
	void stay();
	void fall();
	void draw(sf::RenderWindow& window);
};

