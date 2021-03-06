#ifndef TILE_H
#define TILE_H
#include <fstream>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "enums.h"
#include "magicsprite.h"

using namespace std;
namespace MWEngine
{
class Tile
{

public:
    vector<MagicSprite> tiles_level;

private:
    sf::Texture texturegroundQ;
    sf::Texture texturegroundW;
    sf::Texture texturegroundE;
    sf::Texture texturegroundA;
    sf::Texture texturegroundS;
    sf::Texture texturegroundD;
    sf::Texture texturegroundZ;
    sf::Texture texturegroundX;
    sf::Texture texturegroundC;

    sf::Texture texturegroundR;
    sf::Texture texturegroundT;
    sf::Texture texturegroundF;
    sf::Texture texturegroundG;

    
    sf::Texture textureB0;
    sf::Texture textureB1;
    sf::Texture textureB2;
    sf::Texture textureB3;
    sf::Texture textureB4;
    sf::Texture textureB5;
    sf::Texture textureB6;
    sf::Texture textureB7;
    sf::Texture textureB8;
    

public:
    MagicSprite spriteground;
    MagicSprite spritespear;
    MagicSprite spriteSkull;
    MagicSprite spriteExit;
    sf::Texture textureExit;
    MagicSprite sprite;
    
    MagicSprite spriteObject;
    
    int blockSize;
    float scaleSize;
    int rows;
    //vector<string> levels;
    



    vector<MagicSprite> tiles;
    vector<MagicSprite> spears;
    vector<MagicSprite> stars;
    vector<MagicSprite> skulls;
    
    
    vector<MagicSprite> backgroundObjects ;

    
    vector<MagicSprite> spears_level;
    vector<MagicSprite> stars_level;
    
    vector<sf::Texture> backgroundTextures;

private:
    sf::Texture texturespear;
    sf::Texture textureSkull;
    sf::Texture texturestar;
    float tileGroundSpeed;
    void addElem(char);
    int structure[8];


    float skullSpeed;
    float skullMovement;

public:
    Tile(int);
    ~Tile();
    Tile( const Tile &);
    void moveLeft(float, float);
    void moveRight(float, float);
    void drawTiles(float);
    void loadTiles();
    void addExit(int, int);
    void addTile(int, int, int, int);
    void addSpear(int, int, int);
    void addSkull(int, int, int);
    void addStar(int, int, int);
    void loadLevel(int);
    void addObject (  int lineCol, int lineY, int tileType);
};
}
#endif