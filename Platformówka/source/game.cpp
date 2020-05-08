#include "Textures.h"
#include "Hero.h"
#include "listOfFunction.h"
#include <vector>
#include "Lands.h"
#include "listOfFunction.h"
#include <iostream>


int game(sf::RenderWindow& window, sf::View& view, Textures& T)
{
	

	std::vector<Lands> squares;
	std::vector<Cannon>  cannon;
	std::vector<Spikes> spikes;
	std::vector<Star> star;
	std::vector<Plane> plane;
	sf::Sprite s_META;
	
	bool DEVELOPER_MODE = false;
	
	T.loadTexture();
	Hero player(T);
	s_META.setTexture(T.META);
	
	createLands(squares, T);
	createObstacles(cannon, spikes, star, plane, T, s_META);
	
	int build = 0;
	int type = 0;

	bool trackingCamera = false;
	int HP = 3;
	sf::Event event;
	while (window.isOpen())
	{
		if (!player.inviolability and gameover(cannon, spikes, star, plane, player))
		{
			HP--;
			if (HP <= 0)
				return 2;
			else player.inviolability = true;
		}
		else if (s_META.getGlobalBounds().intersects(player.s_hero.getGlobalBounds()))
		{
			return 1;
		}
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (DEVELOPER_MODE)
			{
				if (type >= 0 and type < 10)
					buildMap(type, event, window, squares);
				if (type >= 10 and type < 19) buildObstacles(T, cannon, window, type, spikes, star, plane);
				else if (type == 19) setMeta(s_META, window);
			}
		}//while
		int y = player.s_hero.getPosition().y;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) and canHeroJump(squares, player) and not player.jumping and player.fallStage == 0 )
			player.jumping = true;
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) or sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) and canHeroGoRight(squares, player))
			player.move(true);
		else if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) or sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) and canHeroGoLeft(squares, player))
			player.move(false);
		else player.stay();
		if (DEVELOPER_MODE)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num0)) type = 0;
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) type = 1;
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) type = 2;
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)) type = 3;
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4)) type = 4;
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5)) type = 5;
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad0)) type = 10;
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad1)) type = 11;
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad2)) type = 12;
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad3)) type = 13;
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad4)) type = 14;
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad9)) type = 19;
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
			{
				saveMap(squares);
				saveObstacles(cannon, spikes, star, plane, s_META);
			}
		}
		if (player.jumping and canHeroJump(squares, player)) player.jumping = player.jump();
		else if (not canHeroStay(squares, player))
		{
			player.fall();
			if (canHeroStay(squares, player))
			{
				player.fallStage = 0;
				int y = player.s_hero.getPosition().y;
				y = y / 50;
				y = y * 50;
				player.s_hero.move(0, y - player.s_hero.getPosition().y);
				player.jumping = false;
				player.jumpStage = 0;
				player.stay();
			}
		}
		else if (canHeroStay(squares, player))
		{
			player.fallStage = 0;
			player.jumping = false;
			player.jumpStage = 0;
		}
		if (player.s_hero.getPosition().x >= 960) trackingCamera = true;
		if (trackingCamera)
		{
			view.setCenter(player.s_hero.getPosition().x,540);
			window.setView(view);
			if (player.s_hero.getPosition().x < 960)
			{
				trackingCamera = false;
				window.setView(window.getDefaultView());
				view = window.getView(),
				view.setSize(1920, 1080);
				view.setCenter(960, 540);
				window.setView(view);
			}
		}
		
		if (not canHeroJump(squares, player))
		{
			player.jumping = false;
			player.jumpStage = 0;
		}
		window.clear();
		drawLands(squares, window);
	
		for (std::vector<Cannon>::iterator itr = cannon.begin(), koniec = cannon.end(); itr != koniec; ++itr)
		{
			itr->draw(window);
			itr->move(squares);
		}
		for (std::vector<Spikes>::iterator itr = spikes.begin(), koniec = spikes.end(); itr != koniec; ++itr)
		{
			itr->draw(window);
		}
		for (std::vector<Star>::iterator itr = star.begin(), koniec = star.end(); itr != koniec; ++itr)
		{
			itr->move(squares);
			itr->draw(window);
		}
		for (std::vector<Plane>::iterator itr = plane.begin(), koniec = plane.end(); itr != koniec; ++itr)
		{
			itr->move(squares);
			itr->draw(window);
		}
		player.draw(window);
		window.draw(s_META);
		window.display();
	} //while
	return 0;
}
