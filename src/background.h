#ifndef BACKGROUND_H
#define BACKGROUND_H
#include <SFML/Graphics.hpp>
#include "enums.h"

namespace MWEngine
{
class Background
{
public:
    float tileGroundSpeed;
    float planetSpeed;
    float treesSpeed;
    float trees2Speed;
    float trees3Speed;


    float characterSpeed;

    sf::Vector2f posTree;

    Background(int, int);
    sf::Texture texturetiles;
    sf::Texture texturetree01;
    sf::Texture texturetree02;

    sf::Texture textureground;
    sf::Texture textureExit;

    sf::Sprite spritetile00;
    sf::Sprite spritetile01;
    sf::Sprite spritetile02;
    sf::Sprite spritetile03;
    sf::Sprite spritetile04;
    sf::Sprite spritetile05;
    sf::Sprite spritetile06;
    sf::Sprite spritetile07;

    sf::Sprite spritetree01;
    sf::Sprite spritetree02;
    sf::Sprite spritetree03;
    sf::Sprite spritetree04;
    sf::Sprite spritetree05;
    sf::Sprite spritetree06;
    sf::Sprite spritetree07;
    sf::Sprite spritetree08;
    sf::Sprite spritetree09;
    sf::Sprite spritetree0a;
    sf::Sprite spritetree0b;
    sf::Sprite spritetree0c;
    sf::Sprite spritetree0d;
    sf::Sprite spritetree0e;
    sf::Sprite spritetree0f;


    sf::Sprite spriteground;


    sf::Sprite tiles [8];

    /*    sf::Sprite trees [4];
        sf::Sprite trees2 [4];
        sf::Sprite trees3 [7];*/

    sf::Texture textureback;
    sf::Texture textureStartLevel;
    sf::Texture texturebackMountain;
    sf::Texture texturebackMountainNG;
    sf::Sprite spritebackMountainBack;
    sf::Sprite spritebackMountainCenter;
    sf::Sprite spritebackMountainFront;

    sf::Sprite spriteback;
    sf::Sprite spriteStartLevel;
    sf::Sprite spritebackMenu;
    sf::Sprite spriteExit;

    sf::Texture textureplanet;

    sf::Sprite spriteplanet;
    sf::Texture textureCloud;
    sf::Sprite spriteCloud;
    void printMessage();
    void initScale();
    void initMove();
    void moveLeft(float, float);
    void moveRight(float, float);


};
}
#endif