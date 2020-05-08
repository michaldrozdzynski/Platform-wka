#include "Textures.h"
#include "listOfFunction.h"
#include <fstream>

void createObstacles(std::vector<Cannon>& cannon, std::vector<Spikes>& spikes, std::vector<Star>& star,
	std::vector<Plane>& plane, Textures& T, sf::Sprite &META)
{
	std::ifstream plik1("data/cannon1.dat", std::ios::binary);
	int x = 0;
	do
	{
		x = 0;
		plik1.read((char*)& x, sizeof x);
		if(x)cannon.push_back(Cannon(T, x));
	} while (x != 0);
	std::ifstream plik2("data/spikes1.dat", std::ios::binary);
	do
	{
		x = 0;
		plik2.read((char*)& x, sizeof x);
		if(x)spikes.push_back(Spikes(T, x));
	} while (x != 0);
	std::ifstream plik3("data/star1.dat", std::ios::binary);
	do
	{
		x = 0;
		plik3.read((char*)& x, sizeof x);
		if(x)star.push_back(Star(T, x));
	} while (x != 0);
	std::ifstream plik4("data/plane1.dat", std::ios::binary);
	do
	{
		x = 0;
		plik4.read((char*)& x, sizeof x);
		if (x)plane.push_back(Plane(T, x));
	} while (x != 0);

	std::ifstream plik5("data/meta1.dat", std::ios::binary);
	x = -100;
	plik5.read((char*)& x, sizeof x);
	META.setPosition((x / 22)*50, (x % 22)*50);

}