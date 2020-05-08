#include "Hero.h"
#include <iostream>
Hero::Hero(Textures &T)
{	
	s_hero.setTexture(T.hero);
	s_hero.setTextureRect(sf::IntRect(1, 1, 66, 100));
	s_hero.setPosition(100, 500);
	clock = 0;		
	jumpStage = 0;
	fallStage = 0;
	jumping = false;
	position = s_hero.getGlobalBounds();
	inviolability = false;
	inv = 0;
}
//////////////////////////////////////////////////////////////////
void Hero::move(bool right)
{
	if (right)
	{
		s_hero.move(7, 0);
		if(jumping or fallStage) s_hero.setTextureRect(sf::IntRect(115, 1, 46, 102));
		else
		{
			switch (clock)
			{
			case 0: s_hero.setTextureRect(sf::IntRect(115, 1, 46, 102));
				break;
			case 5: s_hero.setTextureRect(sf::IntRect(254, 1, 18, 100));
				break;
			case 10:
			{
				s_hero.setTextureRect(sf::IntRect(208, 1, 45, 102));
				clock = -5;
			}
			break;
			}
		
		}
	}

	else
	{
		s_hero.move(-7, 0);
		if (jumping or fallStage) s_hero.setTextureRect(sf::IntRect(68, 1, 46, 102));
		else
		{
			switch (clock)
			{
			case 0: s_hero.setTextureRect(sf::IntRect(68, 1, 46, 102));
				std::cout << "JD "<< std::endl;
				break;
			case 5: s_hero.setTextureRect(sf::IntRect(273, 1, 18, 100));
				break;
			case 10:
			{
				s_hero.setTextureRect(sf::IntRect(162, 1, 45, 102));
				clock = -5;
			}
			break;
			}
		}
	}

	clock++;std::cout << clock << std::endl;
}
//////////////////////////////////////////////////////////////////////////////////////////////
void Hero::stay()
{
	s_hero.setTextureRect(sf::IntRect(1, 1, 66, 100));
	clock = 0;
}
//////////////////////////////////////////////////////////////////////////////////////////////
bool Hero::jump()
{
	jumpStage++;

	
		switch (jumpStage)
		{
		case 1:
		case 2:
		case 3:
		case 4:s_hero.move(0, -10);
			break;
		case 5:
		case 6:
		case 7:
		case 8: s_hero.move(0, -7);
			break;
		case 9:
		case 10:
		case 11:
		case 12: s_hero.move(0, -4);
			break;
		case 13:
		case 14:
		case 15:
		case 16: s_hero.move(0, -1);
			break;
		default:
		{
			jumpStage = 0;
			jumping = false;
			fallStage = 1;
		}
		}
	
	jumping = false;
	

	if (jumpStage != 0) return true;
	else return false;
}
void Hero::fall()
{
	switch (fallStage)
	{
	case 1:
	case 2:
	case 3:
	case 4: s_hero.move(0, 1);
		break;
	case 5:
	case 6:
	case 7:
	case 8: s_hero.move(0, 4);
		break;
	case 9:
	case 10:
	case 11:
	case 12: s_hero.move(0, 7);
		break;	
	default: s_hero.move(0, 10); 
	}

	fallStage++;
}

void Hero::draw(sf::RenderWindow& window)
{
	if (!inviolability) window.draw(s_hero);
	else if (inv % 10 != 0)
	{
		inv++;
	}
	else if (inv % 10 == 0)
	{
		inv++;
		window.draw(s_hero);
	}
	if (inv >= 150)
	{
		inviolability = false;
		inv = 0;
	}
}
