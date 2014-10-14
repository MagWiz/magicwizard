#ifndef HOME_H
#define HOME_H
#include <SFML/Graphics.hpp>

#include <fstream>
#include <iostream>

using namespace std;

namespace MWEngine
{
	class Home
	{


	public:
		sf::Font fontBig;
		Home(float, float);
		void move(float, float);
		float moveSpeed;
		float gravity;
		void animate(float, int);
		float moveSize;
		sf::Vector2f velocity;
		float moveMoment;
		float startPosition;
		sf::Text textTitle;
		float timer;
		float timerStart;
		sf::Text textStart;
		int status;
	
	};
}
#endif