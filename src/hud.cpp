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
        spriteLife.setPosition(screenWidth - (i * HUD_MARGIN_LEFT/2) - HUD_MARGIN_LEFT*2, MWEngine::HUD_MARGIN_TOP) ;
        lives.push_back(spriteLife);
    }
}

Hud::Hud(int widthX, int widthY, sf::Sprite spriteCharacter, int livesCur)
: points(0)
, screenWidth(widthX)
, screenHeight(widthY)
{
    lastLetterAdded = 0.0f;
    stringMessageTmp = "  ";
    stringMessage = "  This is where your journey starts... But what journey we are speaking\nabout, hm? You woke up somewhere far from your cozy comfy place...\nSome really weird rock stone area, seriously what the gem? All your\ndaily based several years mastered environment is gone!!!\n\n Can you survive in this strange undoubtly not finished world?";

 
    currentCharacterMessage = 0;
  
    spriteLife = spriteCharacter;
    spriteLife.scale(0.5f, 0.5f);
    textureLife.loadFromFile("assets/gfx/wizard_2.png");
    textureHud.loadFromFile("assets/gfx/hud.png");
    textureMessage.loadFromFile("assets/gfx/back/bigmessage.png");
    
    
    spriteHud.setTexture(textureHud);
    spriteHudLives.setTexture(textureHud);
    
    spriteHudLives.setPosition(widthX-(textureHud.getSize().x)-1,0);
    
    
    spriteMessage.setTexture(textureMessage);

    spriteMessage.setPosition(widthX/2-textureMessage.getSize().x/2,widthY/2-textureMessage.getSize().y/2);

    
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
    textPoints.setPosition(MWEngine::HUD_MARGIN_LEFT, MWEngine::HUD_MARGIN_TOP);


    textMessageTitle.setFont(fontBig);
    textMessageTitle.setString("Magic Wizard");
    textMessageTitle.setCharacterSize(30);
    textMessageTitle.setColor(sf::Color::Black);
    
    //textMessageSubtitle.setPosition(widthX/2-textMessageSubtitle.getSize().x/2,spriteMessage.getPosition().y+20);
    
    
    textMessageSubtitle.setFont(fontBig);
    textMessageSubtitle.setString("Development version");
    textMessageSubtitle.setCharacterSize(10);
    textMessageSubtitle.setColor(sf::Color::Black);
    
    
    
    textMessage.setFont(fontBig);
    textMessage.setString("");
    textMessage.setCharacterSize(15);
    textMessage.setColor(sf::Color::Black);
    


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
    startLevel.setCharacterSize(25);
    startLevel.setColor(sf::Color(0,0,0,225));

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
    stringMessageTmp = "  ";
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
    startLevel.setPosition(sf::Vector2f(screenWidth / 2.0f, screenHeight/2+textureMessage.getSize().y/2-40));
    
    textRect = textMessageTitle.getLocalBounds();
    textMessageTitle.setOrigin(textRect.left + textRect.width / 2.0f,
                       textRect.top  + textRect.height / 2.0f);
    textMessageTitle.setPosition(screenWidth / 2.0f, spriteMessage.getPosition().y+40);
    
    textRect = textMessageSubtitle.getLocalBounds();
    textMessageSubtitle.setOrigin(textRect.left + textRect.width / 2.0f,
                       textRect.top  + textRect.height / 2.0f);
    textMessageSubtitle.setPosition(screenWidth / 2.0f, spriteMessage.getPosition().y+70);
    
    //textRect = textMessage.getLocalBounds();
    //textMessage.setOrigin(textRect.left + textRect.width / 2.0f,
    //                   textRect.top  + textRect.height / 2.0f);
    textMessage.setPosition(spriteMessage.getPosition().x+30, spriteMessage.getPosition().y+100);
    stringMessageTmp = "  ";
    currentCharacterMessage = 0;
}


void Hud::updateMessageText(float deltaTime)
{
  std::cout << "updateMessageText " << lastLetterAdded << " " << deltaTime << " " << stringMessage.size() << " " << stringMessageTmp.size() <<  std::endl;
  lastLetterAdded += deltaTime;
  if (lastLetterAdded>0.1f)
  {
    lastLetterAdded = 0.0f;
    if (currentCharacterMessage<stringMessage.size()-1)
    {
      currentCharacterMessage++;
      stringMessageTmp = stringMessageTmp + stringMessage[currentCharacterMessage];
      textMessage.setString(stringMessageTmp);
    }
    
  }
  
  
  
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