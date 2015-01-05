#ifndef GAME_H
#define GAME_H

#include "background.h"
#include "character.h"
#include "tile.h"
#include "home.h"
#include "hud.h"
#include "audio.h"
#include "videoeffect.h"
#include "enums.h"
#include <utility>

namespace MWEngine
{
class Game
{

private:
    MWEngine::Audio audioEngine;
    MWEngine::Tile tile;
    MWEngine::Character character;
    MWEngine::Hud hud;
    MWEngine::Background bgd;
        sf::Clock Clock;
        sf::Clock runningClock;

        float deltaTime;

    MWEngine::Home homeScreen;

    sf::RenderTexture offscreen;
    sf::RenderTexture offscreenTmp;
    
    sf::VideoMode ownVideoMode;
    sf::RenderWindow window;
        sf::FloatRect wizardPos;
        const bool showRect;
	
  
  
  sf::Shader spriteShader;
  MWEngine::VideoEffect vfx;
  


private:
    int footSize;
    int screenWidth;
    int screenHeight;
    
    
    int renderWidth;
    int renderHeight;
    
    sf::RectangleShape rct1;
    sf::RectangleShape rct2;
    sf::RectangleShape rctColl;  
    std::array<std::vector<int>,5> collisions;

    sf::View defaultView;
    sf::View gameView;
    sf::FloatRect characterOldPos;

    int alive;
    int gameState;
    int level;
    int maxLevel;
    int nextLevel;

    bool showGameOver;
    int livesStart;
    int livesCur;
    int colStar;
    float border;
    sf::Event event;
    float oldY;
    int colCounter;
    float ccx1, ccx2, ccy1, ccy2;
    bool collision;
    int direction;
    int directionPrevious;
    sf::Time dT;
    float characterSpeed;
    float characterSpeedMax;
    float runningTime;
    int speedGear;
    int speedGearPrevious;
    int speedGearMax;

private:
    void createWindow(int, int);
    void drawHome();
    void drawStars();
    void drawSpears();
    void drawTiles();
    void drawTrees();
    void drawEnvironment();
    void drawGamePlay();
    void drawCharacterBlood();
    void drawGameOver();
    void drawStartLevel();
    void restartLevel();
    void eventLoop();
    void logicLoop();
    void drawLoop();
    void addCollision(int,int);
    void delCollision(int,int);
    
    void updateOffScreen();
    
    void validateCollisions();
    int checkCollisionDirection(sf::FloatRect,sf::FloatRect);
    
    bool doesCollide(int);
    bool doesCollideDirection(int,int);
    bool canMove(int);
    



public:
    Game(int, int);
    void start();

    void startLevel(int);

    void loop();
    void stop();

};
}
#endif

