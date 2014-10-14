#include "home.h"
#include <SFML/Graphics.hpp>

#include <iostream>
namespace MWEngine
{
	void Home::animate(float deltaTime, int screenHeight)
	{
		if (status==4)
		{
			move(600,deltaTime);
		}

		if (status==5)
		{
			moveMoment=0;
			status = 1;
		}

		if (status==0)
		{
			move(300,deltaTime);
		}

		if (status==1)
		{
			if (moveMoment==-1)
			{
				moveMoment=0;
			}
			move(-300,deltaTime);
		}

		if (status==2)
		{
			status=0;
			moveMoment=0;

		}


		timer += deltaTime;
		//std::cout << "TIMER" << timer << std::endl;

		if (timer>30)
		{
			textStart.setPosition(textStart.getPosition().x, screenHeight-20);
		}

	}
	void Home::move(float move,float deltaTime)
	{

		timer = 0;
		sf::Clock Clock;
		timerStart = Clock.restart().asSeconds();
		//std::cout << "INIT "
		gravity=0.01f;
		moveSpeed=5.0f;
		if ((moveMoment==0) && (move>0))
		{
			moveMoment=1;
			startPosition = textTitle.getPosition().y;
			//velocity.y = 0;
			velocity.y = 40*moveSpeed;
		}


		else if ((moveMoment==0) && (move<0))
		{
			moveMoment=2;
			startPosition = textTitle.getPosition().y;
			//velocity.y = 0;
			velocity.y = 40*-moveSpeed;
		}

		if ((moveMoment==1) && (textTitle.getPosition().y<startPosition+move))
		{
 			textTitle.move(0, velocity.y*deltaTime);
			velocity.y += (-gravity);

		}

		else if ((moveMoment==1) && (textTitle.getPosition().y>startPosition+move))
		{
			moveMoment = -1;
			status++;
		}

		else if ((moveMoment==2) && (textTitle.getPosition().y>startPosition+move))
		{
 			textTitle.move(0, velocity.y*deltaTime);
			velocity.y += (-gravity);
		}

		else if ((moveMoment==2) && (textTitle.getPosition().y<startPosition+move))
		{
			moveMoment = -1;
			status++;
		}


	}

	Home::Home(float screenWidth, float screenHeight)
	{

		moveMoment = 0;
		moveSpeed = 4.0f;
		status = 4;
		if (!fontBig.loadFromFile("assets/fonts/TradeWinds-Regular.ttf"))
		{
			exit(-1);
		};

		textTitle.setString("Magic Wizard");
		textTitle.setFont(fontBig);
		textTitle.setCharacterSize(70);
		textTitle.setColor(sf::Color(255, 250, 250, 255));
		textTitle.setStyle(sf::Text::Bold);

		sf::FloatRect textRect = textTitle.getLocalBounds();
		textTitle.setOrigin(textRect.left + textRect.width/2.0f,textRect.top  + textRect.height/2.0f);
		textTitle.setPosition(sf::Vector2f(screenWidth/2.0f,-200));

		textStart.setString("press ENTER to start");
		textStart.setFont(fontBig);
		textStart.setCharacterSize(20);
		textStart.setColor(sf::Color::Black);
		textStart.setStyle(sf::Text::Bold);

		textRect = textStart.getLocalBounds();
		textStart.setOrigin(textRect.left + textRect.width/2.0f,textRect.top  + textRect.height/2.0f);
		textStart.setPosition(sf::Vector2f(screenWidth/2.0f,screenHeight+620));


	}
}
