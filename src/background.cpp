#include "background.h"
#include <SFML/Graphics.hpp>

#include <iostream>
namespace MWEngine
{
Background::Background(int widthX, int widthY)
{
    sf::IntRect tilerect00(392, 784, MWEngine::TILESIZE, MWEngine::TILESIZE);


    if (!textureExit.loadFromFile("assets/gfx/back/exit.png"))
        exit(1);

    spriteExit.setTexture(textureExit);
    characterSpeed = 1.0f;

    if (!texturetree01.loadFromFile("assets/gfx/back/back01.png"))
        exit(1);

    if (!texturetree02.loadFromFile("assets/gfx/back/back02.png"))
        exit(1);

    /**
        Tree constructor
    */

    /*

    spritetree01.setTexture(texturetree01);
    spritetree02.setTexture(texturetree02);
    spritetree03.setTexture(texturetree01);
    spritetree04.setTexture(texturetree02);

    spritetree05.setTexture(texturetree01);
    spritetree06.setTexture(texturetree02);

    spritetree07.setTexture(texturetree01);
    spritetree08.setTexture(texturetree02);

    spritetree09.setTexture(texturetree01);
    spritetree0a.setTexture(texturetree02);

    spritetree0b.setTexture(texturetree01);
    spritetree0c.setTexture(texturetree02);

    spritetree0d.setTexture(texturetree01);
    spritetree0e.setTexture(texturetree02);
    spritetree0f.setTexture(texturetree01);



        trees[0] = spritetree01;
        trees[1] = spritetree02;
        trees[2] = spritetree03;
        trees[3] = spritetree04;

        trees2[0] = spritetree05;
        trees2[1] = spritetree06;
        trees2[2] = spritetree07;
        trees2[3] = spritetree08;

        trees3[0] = spritetree09;
        trees3[1] = spritetree0a;
        trees3[2] = spritetree0b;
        trees3[3] = spritetree0c;
        trees3[4] = spritetree0d;
        trees3[5] = spritetree0e;
        trees3[6] = spritetree0f;

    */
    if (!textureStartLevel.loadFromFile("assets/gfx/startLevel.png"))
        exit(1);
    spriteStartLevel.setTexture(textureStartLevel);

    if (!textureback.loadFromFile("assets/gfx/dark_background.png"))
        exit(1);
    spriteback.setTexture(textureback);
    spriteback.scale(2.5, 2.5);
    //std::cout << "loading 4" << std::endl;
    if (!texturebackMountain.loadFromFile("assets/gfx/background_mountains.png"))
        exit(1);


    if (!texturebackMountainNG.loadFromFile("assets/gfx/mountains_ng.png"))
        exit(1);



    spritebackMountainFront.setTexture(texturebackMountainNG);
    spritebackMountainFront.setPosition(-400, 280);
    texturebackMountainNG.setRepeated(true);
    spritebackMountainFront.setTextureRect(sf::IntRect(0, 0, 3200, 400));

    spritebackMountainBack.setTexture(texturebackMountain);
    spritebackMountainBack.setPosition(0, -300);


    spritebackMountainCenter.setTexture(texturebackMountain);
    spritebackMountainCenter.setPosition(0, -500);


    spritebackMountainBack.scale(1, 2);
    spritebackMountainCenter.scale(1, 3);
    spritebackMenu.scale(1, 1);

    spritebackMenu.setTexture(textureback);
    spritebackMenu.move(-50, 0);

    if (!textureCloud.loadFromFile("assets/gfx/cloud.png"))
        exit(1);
    spriteCloud.setTexture(textureCloud);

    textureCloud.setRepeated(true);
    spriteCloud.setTextureRect(sf::IntRect(0, 0, widthX * 10, 200));
    spriteCloud.move(0, -100);

    if (!textureplanet.loadFromFile("assets/gfx/back/planet01.png"))
        exit(1);
    spriteplanet.setTexture(textureplanet);
    spriteplanet.scale(0.3, 0.3);
    spriteplanet.move(600, 30);


    // Speed

    tileGroundSpeed = 400.f / 2;
    planetSpeed = 1.f;
    trees3Speed = 400.f / 6;
    treesSpeed = 400.f;
    trees2Speed = 400.f / 2;
    tileGroundSpeed = 400.f / 2;
    trees3Speed = 400.f / 6;
};

void Background::moveLeft(float deltaTime, float characterSpeed)
{
    // planet
    spriteplanet.move(planetSpeed * deltaTime * characterSpeed , -0.f);

    // ground
    spriteground.move(tileGroundSpeed * deltaTime * characterSpeed , -0.f);
    spriteback.move(trees2Speed * deltaTime * characterSpeed  / 10.f, -0.f);
    spritebackMountainFront.move(trees2Speed * deltaTime * characterSpeed  / 10.f * 7, -0.f);
    spritebackMountainBack.move(trees2Speed * deltaTime * characterSpeed / 10.f * 1.5, -0.f);
    spritebackMountainCenter.move(trees2Speed * deltaTime * characterSpeed  / 10.f * 5, -0.f);

    if (spritebackMountainFront.getPosition().x > -400)
    {
        spritebackMountainFront.setPosition(-2000, spritebackMountainFront.getPosition().y);
    }
    if (spritebackMountainCenter.getPosition().x > 500)
    {
        spritebackMountainCenter.setPosition(-1900, spritebackMountainCenter.getPosition().y);
    }
    if (spritebackMountainBack.getPosition().x > 500)
    {
        spritebackMountainBack.setPosition(-1900, spritebackMountainBack.getPosition().y);
    }

    if (spriteground.getPosition().x > 0)
    {
        spriteground.setPosition(-MWEngine::TILESIZE, spriteground.getPosition().y);
    }
/*
    for (int i = 0; i < 4; i++)
    {
        //cout << "test number: " << i << endl;

        trees[i].move(treesSpeed * deltaTime * characterSpeed , -0.f);
        trees2[i].move(trees2Speed * deltaTime * characterSpeed , -0.f);

        posTree = trees[i].getPosition();
        if (posTree.x > 920)
        {
            trees[i].setPosition(-120, posTree.y);
        }
        posTree = trees2[i].getPosition();
        if (posTree.x > 920)
        {
            trees2[i].setPosition(-120, posTree.y);
        }
    }



    for (int i = 0; i < 6; i++)
    {
        trees3[i].move(trees3Speed * deltaTime * characterSpeed , -0.f);
        posTree = trees3[i].getPosition();
        if (posTree.x > 920) trees3[i].setPosition(-120, posTree.y);
    }
*/
}

void Background::moveRight(float deltaTime, float characterSpeed)
{
    // planet
    spriteplanet.move(-planetSpeed * deltaTime * characterSpeed , -0.f);
    spriteback.move(-trees2Speed * deltaTime * characterSpeed  / 10.f, -0.f);
    spritebackMountainFront.move(-trees2Speed * deltaTime * characterSpeed / 10.f * 7, -0.f);
    spritebackMountainBack.move(-trees2Speed * deltaTime * characterSpeed / 10.f * 1.5, -0.f);
    spritebackMountainCenter.move(-trees2Speed * deltaTime * characterSpeed / 10.f * 5, -0.f);

    if (spritebackMountainFront.getPosition().x < -2000)
    {
        spritebackMountainFront.setPosition(-400, spritebackMountainFront.getPosition().y);
    }
    if (spritebackMountainCenter.getPosition().x < -1900)
    {
        spritebackMountainCenter.setPosition(400, spritebackMountainCenter.getPosition().y);
    }

    if (spritebackMountainBack.getPosition().x < -1900)
    {
        spritebackMountainBack.setPosition(400, spritebackMountainBack.getPosition().y);
    }

    // ground
    spriteground.move(-tileGroundSpeed * deltaTime * characterSpeed , -0.f);

    if (spriteground.getPosition().x < -MWEngine::TILESIZE)
    {
        spriteground.setPosition(0, spriteground.getPosition().y);
    }

/*    for (int i = 0; i < 4; i++)
    {

        trees[i].move(-treesSpeed * deltaTime * characterSpeed , -0.f);
        trees2[i].move(-trees2Speed * deltaTime * characterSpeed , -0.f);
        posTree = trees[i].getPosition();
        if (posTree.x < -120)
        {
            trees[i].setPosition(920, posTree.y);
        }
        posTree = trees2[i].getPosition();
        if (posTree.x < -120)
        {
            trees2[i].setPosition(920, posTree.y);
        }

    }

*/

/*    for (int i = 0; i < 6; i++)
    {
        trees3[i].move(-trees3Speed * deltaTime * characterSpeed , -0.f);
        posTree = trees3[i].getPosition();
        if (posTree.x < -120)
            trees3[i].setPosition(920, posTree.y);
    }*/

}

void Background::printMessage()
{
    //std::cout << "Hello" << std::endl;
}


void Background::initScale()
{

    // TODO: This probably will be killed

    /*
        for (int i = 0; i < 2; i++)
        {
            trees2[i].scale(0.75, 0.75);
        }

        for (int i = 0; i < 6; i++)
        {
            trees3[i].scale(0.5, 0.5);

        }
        */
}


void Background::initMove()
{
    // TODO: This probably will be killed

    /*
    // First background  fastest
    trees[00].move(550, 410);
    trees[01].move(250, 430);
    trees[02].move(350, 410);
    trees[03].move(650, 420);

    // Second background
    trees2[00].move(550, 310);
    trees2[01].move(250, 330);
    trees2[02].move(350, 310);
    trees2[03].move(650, 320);

    // Third background small
    trees3[00].move(70, 330);
    trees3[01].move(170, 330);
    trees3[02].move(270, 310);
    trees3[03].move(580, 320);
    trees3[04].move(370, 320);
    trees3[05].move(470, 320);
    */
}
}