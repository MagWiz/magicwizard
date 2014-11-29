#include <iostream>
#include <sstream>
#include <string>
#include <SFML/Graphics.hpp>
#include "tile.h"


using namespace std;

namespace MWEngine
{

/**
    Loads tiles

    */
void Tile::loadTiles()
{
    if (!texturegroundQ.loadFromFile("assets/gfx/Grass/gras1.png"))
        exit(1);
    if (!texturegroundW.loadFromFile("assets/gfx/Grass/gras2.png"))
        exit(1);
    if (!texturegroundE.loadFromFile("assets/gfx/Grass/gras3.png"))
        exit(1);
    if (!texturegroundA.loadFromFile("assets/gfx/Grass/grass4.png"))
        exit(1);
    if (!texturegroundS.loadFromFile("assets/gfx/Grass/grass5.png"))
        exit(1);
    if (!texturegroundD.loadFromFile("assets/gfx/Grass/grass6.png"))
        exit(1);
    if (!texturegroundZ.loadFromFile("assets/gfx/Grass/grass7.png"))
        exit(1);
    if (!texturegroundX.loadFromFile("assets/gfx/Grass/grass8.png"))
        exit(1);
    if (!texturegroundC.loadFromFile("assets/gfx/Grass/grass9.png"))
        exit(1);


    if (!texturegroundR.loadFromFile("assets/gfx/Grass/grasscorner1.png"))
        exit(1);
    if (!texturegroundT.loadFromFile("assets/gfx/Grass/grasscorner2.png"))
        exit(1);
    if (!texturegroundF.loadFromFile("assets/gfx/Grass/grasscorner3.png"))
        exit(1);
    if (!texturegroundG.loadFromFile("assets/gfx/Grass/grasscorner4.png"))
        exit(1);




    if (!texturespear.loadFromFile("assets/gfx/back/spear.png"))
        exit(1);
    if (!textureSkull.loadFromFile("assets/gfx/skull.png"))
        exit(1);
    if (!texturestar.loadFromFile("assets/gfx/back/star.png"))
        exit(1);
    if (!textureExit.loadFromFile("assets/gfx/back/exit.png"))
        exit(1);

    texturegroundQ.setSmooth(true);
    texturegroundW.setSmooth(true);
    texturegroundE.setSmooth(true);
    texturegroundA.setSmooth(true);
    texturegroundS.setSmooth(true);
    texturegroundD.setSmooth(true);
    texturegroundZ.setSmooth(true);
    texturegroundX.setSmooth(true);
    texturegroundC.setSmooth(true);
    texturegroundR.setSmooth(true);
    texturegroundT.setSmooth(true);
    texturegroundF.setSmooth(true);
    texturegroundG.setSmooth(true);
    
}

void Tile::addExit(int lineX, int lineY)
{
    //cout << "addxExit" << lineX << " " << lineY   << endl;

    spriteExit = MagicSprite(textureExit);

    

    spriteExit.setTextureRect(sf::IntRect(0, 0, MWEngine::TILESIZE, MWEngine::TILESIZE));
    spriteExit.setTexture(textureExit);
    spriteExit.scale(scaleSize, scaleSize);
    spriteExit.setPosition(rows * lineX, rows * lineY);

}



void Tile::addTile(int lineX, int lineY, int lineSize, int tileType)
{
    //cout << "addxTile" <<  " tileType " << tileType << " "  << lineX << " " << lineY    << lineSize << endl;



    MagicSprite spritegroundTmp;
    if (tileType == MWEngine::TILE_Q)
        spritegroundTmp.setTexture(texturegroundQ);
    else if (tileType == MWEngine::TILE_E)
        spritegroundTmp.setTexture(texturegroundE);
    else if (tileType == MWEngine::TILE_A)
        spritegroundTmp.setTexture(texturegroundA);
    else if (tileType == MWEngine::TILE_S)
        spritegroundTmp.setTexture(texturegroundS);
    else if (tileType == MWEngine::TILE_D)
        spritegroundTmp.setTexture(texturegroundD);
    else if (tileType == MWEngine::TILE_Z)
        spritegroundTmp.setTexture(texturegroundZ);
    else if (tileType == MWEngine::TILE_X)
        spritegroundTmp.setTexture(texturegroundX);
    else if (tileType == MWEngine::TILE_C)
        spritegroundTmp.setTexture(texturegroundC);
    else if (tileType == MWEngine::TILE_R)
        spritegroundTmp.setTexture(texturegroundR);
    else if (tileType == MWEngine::TILE_T)
        spritegroundTmp.setTexture(texturegroundT);
    else if (tileType == MWEngine::TILE_F)
        spritegroundTmp.setTexture(texturegroundF);
    else if (tileType == MWEngine::TILE_G)
        spritegroundTmp.setTexture(texturegroundG);    
    else
        spritegroundTmp.setTexture(texturegroundW);
    texturegroundW.setRepeated(true);
    spritegroundTmp.setTextureRect(sf::IntRect(0, 0, MWEngine::TILESIZE * lineSize, MWEngine::TILESIZE));
    spritegroundTmp.scale(scaleSize, scaleSize);
    //spritegroundTmp.move(-100,475);
    spritegroundTmp.move(rows * lineX, rows * lineY);
    tiles.push_back(spritegroundTmp);
    lineX = 0;
    lineY = 0;
    lineSize = 0;
}


void Tile::addSpear(int lineX, int lineY, int lineSize)
{
    //cout << "addxSpear " << lineX << " " << lineY   <<  " " << lineSize << endl;
    //lineX++; // stupid hack, tired to figure out
    texturespear.setRepeated(true);
    MagicSprite spritespear(texturespear);

    //spritespear.setTextureRect(sf::IntRect(0,0,MWEngine::TILESIZE*lineSize,196));
    spritespear.scale(scaleSize*0.5, scaleSize*0.5);
    //spritespear.move(-100,475);
    spritespear.move((rows * lineX)+rows/2*scaleSize, (rows * lineY)+rows*scaleSize);
    spears.push_back(spritespear);
    lineX = 0;
    lineY = 0;
    lineSize = 0;
}

void Tile::addSkull(int lineX, int lineY, int lineSize)
{
    //cout << "addxSkull " << lineX << " " << lineY   <<  " " << lineSize << endl;
    //lineX++; // stupid hack, tired to figure out
    textureSkull.setRepeated(true);
    MagicSprite spriteSkull;
    spriteSkull.setTexture(textureSkull);

    //spritespear.setTextureRect(sf::IntRect(0,0,MWEngine::TILESIZE*lineSize,196));

    spriteSkull.scale(scaleSize*0.5, scaleSize*0.5);
    spriteSkull.currentDirection = UP;



    //spritespear.move(-100,475);
    spriteSkull.move((rows * lineX)+rows/2*scaleSize, (rows * lineY)+rows*scaleSize*0.5);
    spriteSkull.startY = spriteSkull.getPosition().y;
    skulls.push_back(spriteSkull);    lineY = 0;
    lineSize = 0;
}


void Tile::addStar(int lineX, int lineY, int lineSize)
{
    

    int indexNumber;

    //lineX++; // stupid hack, tired to figure out
    MagicSprite spritestar(texturestar);
    texturestar.setRepeated(true);
    //spritestar.setTextureRect(sf::IntRect(0,0,MWEngine::TILESIZE*lineSize,196));
    spritestar.scale(scaleSize*0.5, scaleSize*0.5);
    spritestar.active = true;
    spritestar.toRemove = false;

    indexNumber = stars.size();

    //spritestar.move(-100,475)
    spritestar.oid = indexNumber;


    spritestar.move((rows * lineX)+rows/2*scaleSize, (rows * lineY)+rows*scaleSize*0.5);
    spritestar.startY = spritestar.getPosition().y;

    spritestar.currentDirection = UP;

    stars.push_back(spritestar);
    lineX = 0;
    lineY = 0;
    lineSize = 0;
}
Tile::Tile( const Tile &other )
    : tiles_level(other.tiles_level), texturegroundW(other.texturegroundW), spriteground(other.spriteground), texturestar(other.texturestar)
{




    tiles  = other.tiles_level;

    for (std::vector<MagicSprite>::reverse_iterator it = tiles.rbegin(); it != tiles.rend(); ++it)
    {
        MagicSprite spriteValue = *it;
        spriteValue.setTexture(texturegroundW);
        *it = spriteValue;
    }
    for (std::vector<MagicSprite>::reverse_iterator it = spears.rbegin(); it != spears.rend(); ++it)
    {
        MagicSprite spriteValue = *it;
        spriteValue.setTexture(texturespear);
        *it = spriteValue;
    }
    for (std::vector<MagicSprite>::reverse_iterator it = stars.rbegin(); it != stars.rend(); ++it)
    {
        MagicSprite spriteValue = *it;
        spriteValue.setTexture(texturestar);
        *it = spriteValue;
    }


}

Tile::~Tile()
{



}


void Tile::loadLevel(int level)
{

    stars.clear();
    tiles.clear();
    spears.clear();

    skulls.clear();

    //int lineRow = 0;
    int lineSize = 0;
    char compar;
    char lastChar = '0';
    int lineX = 0;
    int lineY = 0;
    string line;

    //string fileName = "assets/levels/level0" + to_string()
    char buff[100];
    sprintf(buff, "assets/levels/level0%d.dat", level);


    ifstream myfile (buff);
    if (myfile.is_open())
    {

        while ( myfile.good() )
        {
            getline (myfile, line);

            lineSize = 0;
            for (unsigned int lineCol = 0; lineCol < line.size(); lineCol++)
            {
                compar = line[lineCol];
                // cout << "NEW CHAR:" << compar << " lastChar "
                //      << lastChar
                //      << " lineSize " << lineSize
                //      << " lineX " << lineX
                //      << " lineY " << lineY
                //      << endl;




                if ((lineSize > 0) && (lastChar == 'W') && (compar != 'W'))
                {
                    addTile(lineX, lineY, lineSize, MWEngine::TILE_W);
                    if (compar == '*')
                    {
                        addStar(lineCol, lineY, 1);

                    }
                    else if (compar == 'q')
                    {
                        addSpear(lineCol, lineY, 1);
                    }
                    else if (compar == 'w')
                    {
                        addSkull(lineCol, lineY, 1);
                    }
                    else if (compar == '!')
                    {
                        addExit(lineCol, lineY);
                    }
                    else if (compar == 'Q')
                    {
                        addTile(lineCol, lineY, 1, MWEngine::TILE_Q);
                    }
                    else if (compar == 'E')
                    {
                        addTile(lineCol, lineY, 1, MWEngine::TILE_E);
                    }
                    else if (compar == 'A')
                    {
                        addTile(lineCol, lineY, 1, MWEngine::TILE_A);
                    }
                    else if (compar == 'S')
                    {
                        addTile(lineCol, lineY, 1, MWEngine::TILE_S);
                    }
                    else if (compar == 'D')
                    {
                        addTile(lineCol, lineY, 1, MWEngine::TILE_D);
                    }
                    else if (compar == 'Z')
                    {
                        addTile(lineCol, lineY, 1, MWEngine::TILE_Z);
                    }
                    else if (compar == 'X')
                    {
                        addTile(lineCol, lineY, 1, MWEngine::TILE_X);
                    }
                    else if (compar == 'C')
                    {
                        addTile(lineCol, lineY, 1, MWEngine::TILE_C);
                    }
                    else if (compar == 'R')
                    {
                        addTile(lineCol, lineY, 1, MWEngine::TILE_R);
                    }
                    else if (compar == 'T')
                    {
                        addTile(lineCol, lineY, 1, MWEngine::TILE_T);
                    }

                    else if (compar == 'F')
                    {
                        addTile(lineCol, lineY, 1, MWEngine::TILE_F);
                    }

                    else if (compar == 'G')
                    {
                        addTile(lineCol, lineY, 1, MWEngine::TILE_G);
                    }



                    lastChar = '0';
                    lineSize = 0;
                }
                else if ((lineSize > 0) && (compar == 'W') && (lastChar == 'W'))
                {
                    lineSize++;

                }
                else if ((lineSize == 0) && (compar == 'W'))
                {
                    //cout << "FOUND FIREST W " << endl;
                    lineSize++;
                    lineX = lineCol;
                    lastChar = 'W';
                }
                else if ((lineSize == 0) && (compar == 'q'))
                {
                    addSpear(lineCol, lineY, 1);
                    lastChar = '0';
                }
                else if ((lineSize == 0) && (compar == 'w'))
                {
                    addSkull(lineCol, lineY, 1);
                    lastChar = '0';
                }
                else if ((lineSize == 0) && (compar == '*'))
                {
                    addStar(lineCol, lineY, 1);
                    lastChar = '0';
                }
                else if ((lineSize == 0) && (compar == '!'))
                {
                    addExit(lineCol, lineY);
                    lastChar = '0';
                }
                else if ((lineSize == 0) && (compar == 'Q'))
                {
                    addTile(lineCol, lineY, 1, MWEngine::TILE_Q);
                }
                else if ((lineSize == 0) && (compar == 'E'))
                {
                    addTile(lineCol, lineY, 1, MWEngine::TILE_E);
                }
                else if ((lineSize == 0) && (compar == 'A'))
                {
                    addTile(lineCol, lineY, 1, MWEngine::TILE_A);
                }
                else if ((lineSize == 0) && (compar == 'S'))
                {
                    addTile(lineCol, lineY, 1, MWEngine::TILE_S);
                }
                else if ((lineSize == 0) && (compar == 'D'))
                {
                    addTile(lineCol, lineY, 1, MWEngine::TILE_D);
                }
                else if ((lineSize == 0) && (compar == 'Z'))
                {
                    addTile(lineCol, lineY, 1, MWEngine::TILE_Z);
                }
                else if ((lineSize == 0) && (compar == 'X'))
                {
                    addTile(lineCol, lineY, 1, MWEngine::TILE_X);
                }
                else if ((lineSize == 0) && (compar == 'C'))
                {
                    addTile(lineCol, lineY, 1, MWEngine::TILE_C);
                }
                else if ((lineSize == 0) && (compar == 'R'))
                {
                    addTile(lineCol, lineY, 1, MWEngine::TILE_R);
                }
                else if ((lineSize == 0) && (compar == 'T'))
                {
                    addTile(lineCol, lineY, 1, MWEngine::TILE_T);
                }
                else if ((lineSize == 0) && (compar == 'F'))
                {
                    addTile(lineCol, lineY, 1, MWEngine::TILE_F);
                }
                else if ((lineSize == 0) && (compar == 'G'))
                {
                    addTile(lineCol, lineY, 1, MWEngine::TILE_G);
                }



            }
            lineY++;

        }
        myfile.close();

    }

    else
    {
        exit(1);
    }

}

Tile::Tile(int level)
{



    //MWEngine::TILESIZE = 128;
    scaleSize = 0.5f;
    rows = MWEngine::TILESIZE * scaleSize;

    loadTiles();
    loadLevel(level);

    //std::ifstream infile("thefile.txt");

    //  tiles_level(tiles);
    //spears_level(spears);
    //stars_level(stars);


    //cout << rows*lineY;
    tileGroundSpeed = 400.f / 2;


}

void drawTiles(float deltaTime)
{

}

// void Tile::moveSkulls()
// {

// }

void Tile::moveLeft(float deltaTime, float characterSpeed)
{
    MagicSprite spriteValue;

    // ground
    for (std::vector<MagicSprite>::reverse_iterator it = tiles.rbegin(); it != tiles.rend(); ++it)
    {
        /* std:://cout << *it; ... */
        spriteValue = *it;
        spriteValue.move(tileGroundSpeed * characterSpeed * deltaTime, -0.f);
        *it = spriteValue;
    }
    for (std::vector<MagicSprite>::reverse_iterator it = spears.rbegin(); it != spears.rend(); ++it)
    {
        /* std::cout << *it; ... */
        spriteValue = *it;
        spriteValue.move(tileGroundSpeed * deltaTime * characterSpeed, -0.f);
        *it = spriteValue;
    }

    for (std::vector<MagicSprite>::reverse_iterator it = skulls.rbegin(); it != skulls.rend(); ++it)
    {
        /* std::cout << *it; ... */
        spriteValue = *it;
        spriteValue.move(tileGroundSpeed * deltaTime * characterSpeed, -0.f);
        *it = spriteValue;
    }

    for (std::vector<MagicSprite>::reverse_iterator it = stars.rbegin(); it != stars.rend(); ++it)
    {
        /* std::cout << *it; ... */
        spriteValue = *it;
        spriteValue.move(tileGroundSpeed * deltaTime * characterSpeed, -0.f);
        *it = spriteValue;
    }
    spriteExit.move(tileGroundSpeed * deltaTime * characterSpeed, -0.f);
    //if (spriteground.getPosition().x>0)
    //{
    //      spriteground.setPosition(-196,spriteground.getPosition().y);
    //  }



}

void Tile::moveRight(float deltaTime, float characterSpeed)
{

    // ground
    // ground
    MagicSprite spriteValue;
    for (std::vector<MagicSprite>::reverse_iterator it = tiles.rbegin(); it != tiles.rend(); ++it)
    {
        MagicSprite spriteValue = *it;
        spriteValue.move(-tileGroundSpeed * deltaTime * characterSpeed, -0.f);
        *it = spriteValue;
    }
    for (std::vector<MagicSprite>::reverse_iterator it = spears.rbegin(); it != spears.rend(); ++it)
    {
        MagicSprite spriteValue = *it;
        spriteValue.move(-tileGroundSpeed * deltaTime * characterSpeed, -0.f);
        *it = spriteValue;
    }
    for (std::vector<MagicSprite>::reverse_iterator it = skulls.rbegin(); it != skulls.rend(); ++it)
    {
        MagicSprite spriteValue = *it;
        spriteValue.move(-tileGroundSpeed * deltaTime * characterSpeed, -0.f);
        *it = spriteValue;
    }
    for (std::vector<MagicSprite>::reverse_iterator it = stars.rbegin(); it != stars.rend(); ++it)
    {
        MagicSprite spriteValue = *it;
        spriteValue.move(-tileGroundSpeed * deltaTime * characterSpeed, -0.f);
        *it = spriteValue;
    }
    spriteExit.move(-tileGroundSpeed * deltaTime * characterSpeed, -0.f);
    //spriteground.move(-tileGroundSpeed * deltaTime,-0.f);
    //  if (spriteground.getPosition().x<-196)
    //  {
    //      spriteground.setPosition(0,spriteground.getPosition().y);
    //  }

}
}