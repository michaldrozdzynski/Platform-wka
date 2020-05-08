#pragma once
#include "Hero.h"
#include "Lands.h"
#include <vector>
#include "cannon.h"
#include "Spikes.h"
#include "Star.h"
#include "Plane.h"

int game(sf::RenderWindow& window, sf::View& view, Textures& T);
void createLands(std::vector<Lands>& squares, Textures& T);
void drawLands(std::vector<Lands>& squares, sf::RenderWindow& window);
int mapEdit(sf::RenderWindow& toolsWindow, Textures& T);
void buildMap(int type,sf::Event& event, sf::RenderWindow& window, std::vector<Lands>& squares);
void save(std::vector<Lands>& squares);
void saveMap(std::vector<Lands>& squares);
void heroSurrounding(std::vector<Lands>& squares, Hero& player);
bool canHeroGoRight(std::vector<Lands>& squares, Hero& player);
bool canHeroGoLeft(std::vector<Lands>& squares, Hero& player);
bool canHeroJump(std::vector<Lands>& squares, Hero& player);
bool canHeroStay(std::vector<Lands>& squares, Hero& player);
void buildObstacles(Textures& T, std::vector<Cannon>& cannon,
	sf::RenderWindow& window, int type, std::vector<Spikes>& spikes, std::vector<Star>& star, std::vector<Plane>& plane);
void saveObstacles(std::vector<Cannon>& cannon, std::vector<Spikes>& spikes, std::vector<Star>& star, std::vector<Plane>& plane, sf::Sprite& META);
void createObstacles(std::vector<Cannon>& cannon, std::vector<Spikes>& spikes, std::vector<Star>& star, std::vector<Plane>& plane, Textures& T, sf::Sprite& META);
void setMeta(sf::Sprite& s_META, sf::RenderWindow& window);
bool gameover(std::vector<Cannon>& cannon, std::vector<Spikes>& spikes, std::vector<Star>& star, std::vector<Plane>& plane, Hero& player);