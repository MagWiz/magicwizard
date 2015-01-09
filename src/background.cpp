#include "background.h"
#include <SFML/Graphics.hpp>

#include <iostream>
namespace MWEngine {
Background::Background ( int widthX, int widthY )
{
     sf::IntRect tilerect00 ( 392, 784, MWEngine::TILESIZE, MWEngine::TILESIZE );


     if ( !textureExit.loadFromFile ( "assets/gfx/back/exit.png" ) )
          exit ( 1 );

     spriteExit.setTexture ( textureExit );
     characterSpeed = 1.0f;


     oscClock = sf::Clock();
     oscSinCurrentAngle = 0.0f;
     oscInterval = 0.1;
     oscMod = 1;
     // Configure water
     textureWater.create ( 1408,64 );
     textureWater.setRepeated ( true );
     if ( !textureWater.loadFromFile ( "assets/gfx/kenney/liquidWaterTop.png" ) )
          exit ( 1 );
     spriteWater.setTexture ( textureWater );
     spriteWater.setTextureRect ( sf::IntRect ( 0, 0, 1408, 64 ) );
     spriteWater.setPosition ( 0,720 - 60 );


     textureWater2.create ( 1408,64 );
     textureWater2.setRepeated ( true );
     if ( !textureWater2.loadFromFile ( "assets/gfx/kenney/liquidWaterTop_mid.png" ) )
          exit ( 1 );
     spriteWater2.setTexture ( textureWater2 );
     spriteWater2.setTextureRect ( sf::IntRect ( 0, 0, 1408, 64 ) );
     spriteWater2.setPosition ( 0,630 );





     if ( !tmpBlueTexture.loadFromFile ( "assets/gfx/bg_basic_blue.png" ) )
          exit ( 1 );

     if ( !tmpDarkBlueTexture.loadFromFile ( "assets/gfx/background_mountains.png" ) )
          exit ( 1 );

     spriteBgBasicBlue.setTexture ( tmpBlueTexture );
     spriteBgBasicBlue.setPosition ( 0,0 );


     texturebackMountainNG.create ( 3200,405 );
     texturebackMountainNG.setRepeated ( true );

     spriteBgBasicDarkBlue.setTexture ( tmpDarkBlueTexture );
     spriteBgBasicDarkBlue.setPosition ( 0,0 );

     if ( !texturetree01.loadFromFile ( "assets/gfx/back/back01.png" ) )
          exit ( 1 );

     if ( !texturetree02.loadFromFile ( "assets/gfx/back/back02.png" ) )
          exit ( 1 );

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
     if ( !textureStartLevel.loadFromFile ( "assets/gfx/startLevel.png" ) )
          exit ( 1 );
     spriteStartLevel.setTexture ( textureStartLevel );

     if ( !textureback.loadFromFile ( "assets/gfx/dark_background.png" ) )
          exit ( 1 );
     spriteback.setTexture ( textureback );
     spriteback.scale ( 2.5, 2.5 );
     //std::cout << "loading 4" << std::endl;
     if ( !texturebackMountain.loadFromFile ( "assets/gfx/background_mountains.png" ) )
          exit ( 1 );


     if ( !texturebackMountainNG.loadFromFile ( "assets/gfx/mountains_ng.png" ) )
          exit ( 1 );



     texturebackMountainNG.setRepeated ( true );
     spritebackMountainFront.setTexture ( texturebackMountainNG );
     spritebackMountainFront.setPosition ( -400, 380 );
     spritebackMountainFront.setTextureRect ( sf::IntRect ( 0, 0, 4800, 405 ) );



     spritebackMountainBack.setTexture ( texturebackMountain );
     spritebackMountainBack.setPosition ( 0, 0 );


     spritebackMountainCenter.setTexture ( texturebackMountain );
     spritebackMountainCenter.setPosition ( 0, -500 );


     //spritebackMountainBack.scale(1, 2);
     spritebackMountainCenter.scale ( 1, 3 );
     spritebackMenu.scale ( 1, 1 );

     spritebackMenu.setTexture ( textureback );
     spritebackMenu.move ( -50, 0 );

     if ( !textureCloud.loadFromFile ( "assets/gfx/cloud.png" ) )
          exit ( 1 );
     spriteCloud.setTexture ( textureCloud );

     textureCloud.setRepeated ( true );
     spriteCloud.setTextureRect ( sf::IntRect ( 0, 0, widthX * 10, 200 ) );
     spriteCloud.move ( 0, -100 );

     if ( !textureplanet.loadFromFile ( "assets/gfx/back/planet01.png" ) )
          exit ( 1 );
     spriteplanet.setTexture ( textureplanet );
     spriteplanet.scale ( 0.3, 0.3 );
     spriteplanet.move ( 600, 30 );


     // Speed

     tileGroundSpeed = 400.f / 2;
     planetSpeed = 1.f;
     trees3Speed = 400.f / 6;
     treesSpeed = 400.f;
     trees2Speed = 400.f / 2;
     tileGroundSpeed = 400.f / 2;
     trees3Speed = 400.f / 6;
};

void Background::moveLeft ( float deltaTime, float characterSpeed )
{
     // planet
     spriteplanet.move ( planetSpeed * deltaTime * characterSpeed , -0.f );

     // ground
     spriteground.move ( tileGroundSpeed * deltaTime * characterSpeed , -0.f );
     spriteback.move ( trees2Speed * deltaTime * characterSpeed  / 10.f, -0.f );
     spritebackMountainFront.move ( trees2Speed * deltaTime * characterSpeed  / 10.f * 7, -0.f );
     spriteWater.move ( trees2Speed * deltaTime * characterSpeed / 100.f * 7, -0.f );
     spriteWater2.move ( trees2Speed * deltaTime * characterSpeed / 33.3f * 7, -0.f );

//     spritebackMountainBack.move(trees2Speed * deltaTime * characterSpeed / 10.f * 1.5, -0.f);
//     spritebackMountainCenter.move(trees2Speed * deltaTime * characterSpeed  / 10.f * 5, -0.f);
     //std::cout << spritebackMountainFront.getPosition().x << std::endl;


     if ( spriteWater.getPosition().x > 0 ) {
          spriteWater.setPosition ( -64, spriteWater.getPosition().y );
     }
     if ( spriteWater2.getPosition().x > 0 ) {
          spriteWater2.setPosition ( -64, spriteWater2.getPosition().y );
     }

//         std::cout << "GO LEFT " << spriteWater.getPosition().x << std::endl;

     if ( spritebackMountainFront.getPosition().x > -400 ) {
          spritebackMountainFront.setPosition ( -2000, spritebackMountainFront.getPosition().y );
// 	std::cout << "SWAP LEFT" << std::endl;
     }
//     if (spritebackMountainCenter.getPosition().x > 500)
//     {
//         spritebackMountainCenter.setPosition(-1900, spritebackMountainCenter.getPosition().y);
//     }
//     if (spritebackMountainBack.getPosition().x > 500)
//     {
//         spritebackMountainBack.setPosition(-1900, spritebackMountainBack.getPosition().y);
//     }

     if ( spriteground.getPosition().x > 0 ) {
          spriteground.setPosition ( -MWEngine::TILESIZE, spriteground.getPosition().y );
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

void Background::moveRight ( float deltaTime, float characterSpeed )
{
     // planet
     spriteplanet.move ( -planetSpeed * deltaTime * characterSpeed , -0.f );
     spriteback.move ( -trees2Speed * deltaTime * characterSpeed  / 10.f, -0.f );
     spritebackMountainFront.move ( -trees2Speed * deltaTime * characterSpeed / 10.f * 7, -0.f );
     spriteWater.move ( -trees2Speed * deltaTime * characterSpeed / 100.f * 7, -0.f );
     spriteWater2.move ( -trees2Speed * deltaTime * characterSpeed / 33.3f * 7, -0.f );


     //spritebackMountainBack.move(-trees2Speed * deltaTime * characterSpeed / 10.f * 1.5, -0.f);
     //spritebackMountainCenter.move(-trees2Speed * deltaTime * characterSpeed / 10.f * 5, -0.f);

     if ( spriteWater.getPosition().x < -64 ) {
          spriteWater.setPosition ( 0, spriteWater.getPosition().y );
          
     }

    if ( spriteWater2.getPosition().x < -64 ) {
          spriteWater2.setPosition ( 0, spriteWater2.getPosition().y );
          
     }
     
     
     if ( spritebackMountainFront.getPosition().x < -2000 ) {
          spritebackMountainFront.setPosition ( -400, spritebackMountainFront.getPosition().y );

     }
//     if (spritebackMountainCenter.getPosition().x < -1900)
//     {
//         spritebackMountainCenter.setPosition(400, spritebackMountainCenter.getPosition().y);
//     }
//
//     if (spritebackMountainBack.getPosition().x < -1900)
//     {
//         spritebackMountainBack.setPosition(400, spritebackMountainBack.getPosition().y);
//     }

     // ground
     spriteground.move ( -tileGroundSpeed * deltaTime * characterSpeed , -0.f );

     if ( spriteground.getPosition().x < -MWEngine::TILESIZE ) {
          spriteground.setPosition ( 0, spriteground.getPosition().y );
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

void Background::moveVert ( float deltaTime, float posY )
{
     spritebackMountainFront.setPosition ( spritebackMountainFront.getPosition().x, 380+ ( posY/25.0f ) );
     // For the second background - not active now
     //spriteBgBasicDarkBlue.setPosition(spriteBgBasicDarkBlue.getPosition().x, -120-(posY/15.0f));
}

void Background::printMessage()
{
     //std::cout << "Hello" << std::endl;
}

void Background::update ( float deltaTime )
{
     spriteWater.setPosition ( spriteWater.getPosition().x, 723 - 60 +sin ( oscSinCurrentAngle+90.f ) /1.5f );
     spriteWater2.setPosition ( spriteWater2.getPosition().x, 636 +sin ( oscSinCurrentAngle ) );

     if ( oscClock.getElapsedTime().asSeconds() >oscInterval ) {
          oscSinCurrentAngle += deltaTime*500.0f*oscMod;
          oscClock.restart();
          if ( ( oscSinCurrentAngle>=180 ) && ( oscMod==1 ) ) {
               oscMod = oscMod * -1;
          }
          if ( ( oscSinCurrentAngle<=0 ) && ( oscMod==-1 ) ) {
               oscMod = oscMod * -1;
          }
     }
}




}
