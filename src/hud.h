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
			sf::Texture textureMessage;
			sf::Sprite spriteLife;
			sf::Sprite spriteHud;
			sf::Sprite spriteHudLives;
			sf::Sprite spriteMessage;

			sf::Text textPoints;
			sf::Text gameOver;
			sf::Text startLevel;
			sf::Text pressToContinue;
			
			
			sf::Text textMessageTitle;
			sf::Text textMessageSubtitle;
			sf::Text textMessage;	
			string stringMessage;
			string stringMessageTmp;
			
			float lastLetterAdded;
			float currentCharacterMessage;
			
			
			
			int screenWidth,screenHeight;

			Hud(int, int, sf::Sprite, int);
			void setText();
			void restart();
			void createLives(int);
			void collectStar();
			void setLevel(int);
			void updateMessageText(float deltaTime);

	};
}
#endif