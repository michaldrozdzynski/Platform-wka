#include "Textures.h"

void Textures::loadTexture()
{
	hero.loadFromFile("img/hero.png");
	lands.loadFromFile("img/land.png");
	border.loadFromFile("img/border.png");
	cannon.loadFromFile("img/armata.png");
	bullet.loadFromFile("img/pocisk.png");
	spikes.loadFromFile("img/kolce.png");
	star.loadFromFile("img/star.png");
	lift.loadFromFile("img/lift.png");
	plane.loadFromFile("img/plane.png");
	bomb.loadFromFile("img/bomba.png");
	META.loadFromFile("img/meta.png");
	START.loadFromFile("img/start.png");
	KONIEC.loadFromFile("img/koniec.png");
	win.loadFromFile("img/win.png");
	lose.loadFromFile("img/lose.png");
}
///////////////////////////////////////////////////////////