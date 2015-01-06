#ifndef HUD_H
#define HUD_H

#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>
#include "enums.h"

using namespace std;
namespace MWEngine
{
	class Hud
	{
		private:
			sf::Font fontBig;

		public:
			int points;
			vector<sf::Sprite> lives;
			sf::Texture textureLife;
			sf::Texture textureHud;
			sf::Sprite spriteLife;
			sf::Sprite spriteHud;
			sf::Text textPoints;
			sf::Text gameOver;
			sf::Text startLevel;
			sf::Text pressToContinue;
			int screenWidth,screenHeight;

			Hud(int, int, sf::Sprite, int);
			void setText();
			void restart();
			void createLives(int);
			void collectStar();
			void setLevel(int);

	};
}
#endif