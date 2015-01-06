#include <sstream>
#include <string>
#include "hud.h"
#include <SFML/Graphics.hpp>

#include <iostream>

using namespace std;
namespace MWEngine
{
void Hud::createLives(int livesCur)
{
    lives.clear();
    for (int i = 0; i < livesCur; i++)
    {
        sf::Sprite spriteLifeTmp = spriteLife;
        spriteLife.setPosition(screenWidth - (i * 80) - 80, MWEngine::HUD_MARGIN_TOP) ;
        lives.push_back(spriteLife);
    }
}

Hud::Hud(int widthX, int widthY, sf::Sprite spriteCharacter, int livesCur)
{

    points = 0;
    spriteLife = spriteCharacter;
    screenWidth = widthX;
    screenHeight = widthY;
    textureLife.loadFromFile("assets/gfx/wizard_2.png");
    points = 0;
    sf::FloatRect textRect;
    if (!fontBig.loadFromFile("assets/fonts/TradeWinds-Regular.ttf"))
    {
        exit(-1);
    }
    // Points Text
    textPoints.setString("Points: 00");
    textPoints.setFont(fontBig);
    textPoints.setCharacterSize(20);
    textPoints.setColor(sf::Color::Black);
    textPoints.setStyle(sf::Text::Bold);
    textPoints.setPosition(10, MWEngine::HUD_MARGIN_TOP);




    pressToContinue.setFont(fontBig);
    pressToContinue.setCharacterSize(25);
    pressToContinue.setColor(sf::Color::White);
    pressToContinue.setStyle(sf::Text::Bold);
    pressToContinue.setString("Press Space to continue...");

    textRect = pressToContinue.getLocalBounds();
    pressToContinue.setOrigin(textRect.left + textRect.width / 2.0f,
                       textRect.top  + textRect.height / 2.0f);
    pressToContinue.setPosition(sf::Vector2f(screenWidth / 2.0f, screenHeight / 2.0f));


    startLevel.setFont(fontBig);
    startLevel.setCharacterSize(95);
    startLevel.setColor(sf::Color(255,255,255,125));


    // Game Over Text
    gameOver.setString("GAME OVER");
    gameOver.setFont(fontBig);
    gameOver.setCharacterSize(75);
    gameOver.setColor(sf::Color::White);
    gameOver.setStyle(sf::Text::Bold);
    textRect = gameOver.getLocalBounds();
    gameOver.setOrigin(textRect.left + textRect.width / 2.0f,
                       textRect.top  + textRect.height / 2.0f);
    gameOver.setPosition(sf::Vector2f(screenWidth / 2.0f, screenHeight / 2.0f));
    createLives(livesCur);

}


void Hud::restart()
{
    setText();
}


void Hud::setLevel(int levelNumber)
{
    stringstream ss;
    ss << levelNumber;
    startLevel.setString("Level: " + ss.str());
    sf::FloatRect textRect = startLevel.getLocalBounds();
    startLevel.setOrigin(textRect.left + textRect.width / 2.0f,
                       textRect.top  + textRect.height / 2.0f);
    startLevel.setPosition(sf::Vector2f(screenWidth / 2.0f, screenHeight / 2.0f));
}

void Hud::setText()
{
    stringstream ss;
    ss << points;
    textPoints.setString("Points: " + ss.str());

}


void Hud::collectStar()
{
    points = points + 20;
    setText();
}
}