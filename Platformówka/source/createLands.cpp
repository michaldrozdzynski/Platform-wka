#include "listOfFunction.h"
#include "Textures.h"
#include <fstream>

void createLands(std::vector<Lands>& squares, Textures &T)
{
	std::ifstream plik("data/map1.dat", std::ios::binary);
	int x = 0;
	for (int i = 1; i <= 400; i++)
	{
		for (int j = 1; j <= 22; j++)
		{
			plik.read((char*)& x, sizeof x);
			squares.push_back(Lands(T, i, j, x));
		}
	}
}