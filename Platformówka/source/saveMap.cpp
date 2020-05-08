#include "listOfFunction.h"
#include <fstream>

void saveMap(std::vector<Lands>& squares)
{
	std::ofstream plik("data/map1.dat", std::ios::binary);

	for (std::vector<Lands>::iterator itr = squares.begin(); itr != squares.end(); ++itr)
	{
		plik.write((char*)(&(itr->type)), sizeof(int));
	}
}