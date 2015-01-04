#include "game.h"

namespace MWEngine
{

/**
    Checks if character collides with tile by index of tiles vector
    */
bool Game::doesCollide(int tileVector)
{
    wizardPos = character.spritewizard.getGlobalBounds();
    ccx2 = wizardPos.left + wizardPos.width;
    ccy1 = wizardPos.top;
    ccy2 = wizardPos.top + wizardPos.height;
    sf::Sprite localSprite;
    localSprite = tile.tiles.at(tileVector);
    sf::FloatRect tilePos = localSprite.getGlobalBounds();
    float ocx1, ocx2, ocy1, ocy2;
    ocx1 = tilePos.left; // TODO:
    ocy1 = tilePos.top; // TODO: moves character over the tile
    ocx2 = tilePos.left + tilePos.width;
    ocy2 = tilePos.top + tilePos.height;

    // r1 is a character float rect
    sf::FloatRect
    r1(
        sf::Vector2f(ccx1, ccy1),
        sf::Vector2f(ccx2 - ccx1, ccy2 - ccy1)
    );

    // r1 is a title float rect
    sf::FloatRect
    r2(
        sf::Vector2f(ocx1, ocy1),
        sf::Vector2f(ocx2 - ocx1, ocy2 - ocy1)
    );
    rct2.setSize(sf::Vector2f(ocx2 - ocx1, ocy2 - ocy1));
    rct2.setPosition(ocx1, ocy1);
    if (r1.intersects(r2))
    {
        // std::cout << "intersects " << tileVector << "\n";
        return true;
    }
    else
    {
        return false;
    }

}
/**
    Checks if character collides with
    */
bool Game::doesCollideDirection(int tileVector, int direction)
{

    wizardPos = character.spritewizard.getGlobalBounds();
    ccx2 = wizardPos.left + wizardPos.width;
    ccy1 = wizardPos.top;
    ccy2 = wizardPos.top + wizardPos.height;
    sf::Sprite localSprite;
    localSprite = tile.tiles.at(tileVector);
    sf::FloatRect tilePos = localSprite.getGlobalBounds();
    float ocx1, ocx2, ocy1, ocy2;
    ocx1 = tilePos.left; // TODO:
    ocy1 = tilePos.top; // TODO: moves character over the tile
    ocx2 = tilePos.left + tilePos.width;
    ocy2 = tilePos.top + tilePos.height;

    // r1 is a character float rect
    sf::FloatRect
    r1(
        sf::Vector2f(ccx1, ccy1),
        sf::Vector2f(ccx2 - ccx1, ccy2 - ccy1)
    );

    // r1 is a title float rect
    sf::FloatRect
    r2(
        sf::Vector2f(ocx1, ocy1),
        sf::Vector2f(ocx2 - ocx1, ocy2 - ocy1)
    );
    int collisionDirectionResult = checkCollisionDirection(r1, r2);
    if (collisionDirectionResult == direction)
        return true;
    else
        return false;

}



/**
    Checks direction of the collision
    */
int Game::checkCollisionDirection(sf::FloatRect r1, sf::FloatRect r2)
{

    float ccx1 = r1.left;
    float ccx2 = r1.left + r1.width;
    float ccy1 = r1.top;
    float ccy2 = r1.top + r1.height;

    float ocx1 = r2.left;
    float ocx2 = r2.left + r2.width;
    float ocy1 = r2.top;
    //float ocy2 = r2.top + r2.height;





    /** Tile left side */
    if (
        ((ccx2 > ocx2) && (ccy1 - footSize > ocy1)) ||
        // ((ccx2 > ocx2) && (character.jumping != 0)) ||
        ((ccx2 > ocx2) && (ccy2 - footSize > ocy1))
    )
    {
        // cout << "special detected colision on the left side" << endl;
        return LEFT;
    }


    /** Tile on right side */
    if (
        ((ccx1 < ocx1) && (ccy1 - footSize > ocy1)) ||
        // ((ccx1 < ocx1) && (character.jumping != 0)) ||
        ((ccx1 < ocx1) && (ccy2 - footSize > ocy1))
    )
    {
        // cout << "special detected colision on the right side" << endl;
        return RIGHT;

    }

    // /** Tile on up side */
    // if (ccy1 < ocy1)
    // {
    //     //colisDirectionY = MWEngine::DOWN;
    //     // cout << "colision on the DOWN side" << endl;

    // }

    // /** Tile on down side */
    // if (ccy2 > ocy2)
    // {
    //     //colisDirectionY = MWEngine::DOWN;
    //     // cout << "colision on the down side" << endl;

    // }
    return STOP;

}

/**
    Validates list of collisions and removes historical ones
    */
void Game::validateCollisions()
{
    std::array<int, 4> validDirections = {LEFT, RIGHT, UP, DOWN };
    for (int &direction : validDirections)
    {
        for (int &collision_test : collisions[direction])
        {

            bool validResult = doesCollide(collision_test);
            if (validResult == false)
            {
                delCollision(direction, collision_test);
            }
            else
            {
                if (doesCollideDirection( collision_test, direction) == false)
                {
                    delCollision(direction, collision_test);
                }
            }


        }
    }

}

/**
    Checks if character can move in specific direction
    */
bool Game::canMove(int direction)
{
    if (collisions[direction].size() > 1)
    {
        return false;
    }

    return true;

}

/**
    Adds a collision to the vector
    */
void Game::addCollision(int direction, int index)
{
    // http://stackoverflow.com/questions/3450860/check-if-a-stdvector-contains-a-certain-object
    if (std::find(collisions[direction].begin(), collisions[direction].end(), index) != collisions[direction].end())
    {
        /* v does contain x */
    }
    else
    {
        /* v does not contain x */
        collisions[direction].push_back(index);
    }
}

/**
    Deletes a collision from the vector
    */
void Game::delCollision(int direction, int index)
{

    // http://stackoverflow.com/questions/3385229/c-erase-vector-element-by-value-rather-than-by-position
    collisions[direction].erase(std::remove(collisions[direction].begin(), collisions[direction].end(), index), collisions[direction].end());
}

/**
    Main even loop
    */
void Game::eventLoop()
{
    if (event.type == sf::Event::Closed)
        window.close();
    /*

        E V E N T S
        handling

    */

    /**
        Checking which screen is a current one.

        */

    /** Home screen */
    if (gameState == STATE_MENU)
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
        {
            livesCur = livesStart;
            hud.points = 0;
            startLevel(0);

        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
            window.close();
    }


    if (gameState == STATE_STARTLEVEL)
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            start();
            restartLevel();
        }


    }

    /** Game screen */
    if ((gameState == STATE_GAMEPLAY) && (alive == 1) && (!showGameOver))
    {
        /// Character is alive

        /** Quits gameplay  - ESC*/
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            gameState = STATE_MENU;
            audioEngine.stopMusicGame();
            audioEngine.playMusicMenu();
        }

        /** Jumps - UP */
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            if (character.jumping == 0)
            {
                character.jumping = 4;
                audioEngine.playJump();
            }
        }


        /** Walks - RIGHT */
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            direction = MWEngine::RIGHT;

            // cout << "PRAWO" << endl;
        }

        /** Walks - LEFT */
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            direction = MWEngine::LEFT;

            // cout << "LEWO" << endl;
        }
        else
        {
            directionPrevious = MWEngine::STOP;
            direction = MWEngine::STOP;
            characterSpeed = 0.0f;
            runningClock.restart();
            runningTime = 0.0f;
        } /// Stops
    }
    else if ((gameState == STATE_GAMEPLAY) && (alive == 0) && (showGameOver))
    {
        /// Character is dead
        /** Hides GameOver banner */
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            showGameOver = false;
        character.bloodFrame = 5;

        audioEngine.stopMusicGame();
        audioEngine.playMusicMenu();
        gameState = STATE_MENU;
            }
    } else if (gameState == STATE_LOSTLIFE)
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            restartLevel();
            gameState = STATE_GAMEPLAY;
        }


    }
}

/**
    Logic loop of the game
    */
void Game::logicLoop()
{
    /*
         LOGIC
     */
    //int myDirection;
    if ((gameState == STATE_GAMEPLAY) && (alive == 1))
    {
        validateCollisions();
        
        /** Processing of height */
        character.jump(deltaTime);
        character.fall(deltaTime);
        /// Moves background
        bgd.spriteback.setPosition(bgd.spriteback.getPosition().x , (-character.spritewizard.getPosition().y / 16 - 20) - 40);

	
	
        bool colis = false;
        int colisDirectionX = MWEngine::STOP;
        if ((direction == MWEngine::STOP) && (character.moving == 1))
        {

            
            character.stop();
        }

        /**
            Moving environment

            Right
            */
        if ((direction == MWEngine::RIGHT))
        {
            if (canMove(RIGHT) == true)
            {
                character.collides[LEFT] = false;
                character.direction[LEFT] = true;
                character.direction[RIGHT] = false;
                character.moveRight(dT);
                tile.moveRight(deltaTime, characterSpeed);
                bgd.moveRight(deltaTime, characterSpeed);
            }
            else
            {
                // std::cout << "cant move";
            }
        }

        /** Left */
        if ((direction == MWEngine::LEFT))
        {
            if (canMove(LEFT) == true)
            {
                
                character.collides[RIGHT] = false;
                character.direction[LEFT] = false;
                character.direction[RIGHT] = true;
                character.moveLeft(dT);
                tile.moveLeft(deltaTime, characterSpeed);
                bgd.moveLeft(deltaTime, characterSpeed);
            }
            else
            {
                // std::cout << "cant move";
                
            }
        }

        /** Colision detection */

        if ((character.moving != 0) || (character.jumping != 0))
        {
            /** Describes if character is standing on stable area */
            bool safe = false;
            //bool colis = false;

            /** Gets coordinates of the character */
            wizardPos = character.spritewizard.getGlobalBounds();
            ccx1 = wizardPos.left;
            ccx2 = wizardPos.left + wizardPos.width;
            ccy1 = wizardPos.top;
            ccy2 = wizardPos.top + wizardPos.height;

            sf::FloatRect exitPos = tile.spriteExit.getGlobalBounds();

            /** Gets coordinates of the exit */
            float ecx1, ecx2, ecy1, ecy2;
            ecx1 = exitPos.left;
            ecy1 = exitPos.top;
            ecx2 = exitPos.left + exitPos.width;
            ecy2 = exitPos.top + exitPos.height;

            /**
                Creates two rectangles (character and exit point)
                and checks them against each other.

                TODO: Encapsulate

                */

            sf::FloatRect
            re1(
                sf::Vector2f(ccx1, ccy1),
                sf::Vector2f(ccx2 - ccx1, ccy2 - ccy1)
            );

            sf::FloatRect
            re2(
                sf::Vector2f(ecx1, ecy1),
                sf::Vector2f(ecx2 - ecx1, ecy2 - ecy1)
            );

            if (re1.intersects(re2))
            {
                nextLevel = true;
            }


            /**
                Iteration over all tiles - colision detection happens here

                */
            int loopCounter = 0;
            for (std::vector<MagicSprite>::reverse_iterator it = tile.tiles.rbegin(); it != tile.tiles.rend(); ++it)
            {
                /**
                    Assign a tile to localSprite, next create the rectangles
                    to compate them with each other

                    */
                sf::Sprite localSprite;
                localSprite = *it;
                sf::FloatRect tilePos = localSprite.getGlobalBounds();
                float ocx1, ocx2, ocy1, ocy2;
                ocx1 = tilePos.left; // TODO:
                ocy1 = tilePos.top; // TODO: moves character over the tile
                ocx2 = tilePos.left + tilePos.width;
                ocy2 = tilePos.top + tilePos.height;



                // r1 is a character float rect
                sf::FloatRect
                r1(
                    sf::Vector2f(ccx1, ccy1),
                    sf::Vector2f(ccx2 - ccx1, ccy2 - ccy1)
                );
                // r1 is a title float rect
                sf::FloatRect
                r2(
                    sf::Vector2f(ocx1, ocy1),
                    sf::Vector2f(ocx2 - ocx1, ocy2 - ocy1)
                );
                rct2.setSize(sf::Vector2f(ocx2 - ocx1, ocy2 - ocy1));
                rct2.setPosition(ocx1, ocy1);

                /** Characters colision with tile */

                sf::FloatRect collisionIntersect;
                if (r1.intersects(r2, collisionIntersect))
                {
                    rct1.setSize(sf::Vector2f(ccx2 - ccx1, ccy2 - ccy1));
                    rct1.setPosition(ccx1, ccy1);
                    rctColl.setPosition(ocx1, ocy1);
                    rctColl.setSize(sf::Vector2f(ocx2 - ocx1, ocy2 - ocy1));


                    if (collisionIntersect.height > 30)
                    {
                        runningClock.restart();
                        runningTime = 0.0f;
                    }

                    colis = true;

                    if (showRect)
                    {
                        offscreen.draw(rct1);
                        offscreen.draw(rct1);
                        offscreen.draw(rct2);
                    }


     

                    /** Tile on right side */
                    if (
                        ((ccx1 < ocx1) && (ccy1 - footSize > ocy1)) ||
                        ((ccx1 < ocx1) && (character.jumping != 0)) ||
                        ((ccx1 < ocx1) && (ccy2 - footSize > ocy1))
                    )
                    {
                        colisDirectionX = MWEngine::RIGHT;
                        character.collides[RIGHT] = true;
                        addCollision(RIGHT, loopCounter);
                        // cout << "detected colision on the right side" << endl;

                    }

   

                    /** Tile left side */
                    if (
                        ((ccx2 > ocx2) && (ccy1 - footSize > ocy1)) ||
                        ((ccx2 > ocx2) && (ccy2 - footSize > ocy1))
                    )
                    {
                        colisDirectionX = MWEngine::LEFT;
                        character.collides[LEFT] = true;
                        addCollision(LEFT, loopCounter);

                         // cout << "detected colision on the left side" << endl;

                    }


 
                    loopCounter ++;

                }


                // up and down checks
                if (
                    (ccx1 + (wizardPos.width) > int(ocx1)) &&
                    (ccx2 < int(ocx2 + (wizardPos.width)))
                )
                {
                    // Check if it fits horizontally
                    if ((ocy1 - ccy1 < wizardPos.height) && (ocy1 - ccy1 > 0))
                    {
                        // check is is above
                        safe = true;
                        if (ccy2 < ocy1)
                        {
                            if ((character.jumping < 3) && (character.jumping > 0))
                            {
                                character.spritewizard.setPosition(character.spritewizard.getPosition().x, ocy1 - tile.rows - 7);
                            }
                        }
                        if (character.jumping == 1)
                        {
                            if (collisionIntersect.width > 10)
                            {
                                // Landing - and fixing character position to stand on a tile
                                character.spritewizard.setPosition(character.spritewizard.getPosition().x, ocy1 - tile.rows + footSize * 4);
                                character.jumping = 0;
                            }
                        }
                    }


                    if ((ccy1 - ocy1 < tile.rows + 8) && (ocy1 < ccy1) && (ocy2 < ccy2))
                    {
                        // head on when jump
                        if (character.jumping == 3)
                        {
                            if (collisionIntersect.width > 10)
                            {
                                character.jumping = 2;
                            }
                        }
                    }

                }
                else
                {


                }
            }

            if (!colis)
            {
                oldY = character.spritewizard.getPosition().y;
            }

            if (!safe)
            {
                if (character.jumping == 0)
                {
                    //cout << "FAIL " << endl;
                    character.jumping = 2;
                }
            }

        }

        if ((direction == MWEngine::LEFT) && (directionPrevious == MWEngine::STOP))
        {
            runningClock.restart();
            directionPrevious = MWEngine::LEFT;
            runningTime = 0.0f;
        }

        if ((direction == MWEngine::RIGHT) && (directionPrevious == MWEngine::STOP))
        {
            runningClock.restart();
            runningTime = 0.0f;
            directionPrevious = MWEngine::RIGHT;
        }

        /* Normalization of the speed */
        if ((direction == MWEngine::LEFT) || (directionPrevious == MWEngine::RIGHT))
        {
            if ((runningTime < 5.0f) && (characterSpeed < characterSpeedMax))
            {
                runningTime = runningClock.getElapsedTime().asSeconds();
            }

            else

            {
                runningTime = 5.0f;
            }


        }
        else

        {
            directionPrevious = MWEngine::STOP;
            runningTime = 0.0f;
        }

        speedGearPrevious = speedGear;
        if (runningTime==0.0f)
        {
            speedGear = 0;
            gameView.setSize(screenWidth, screenHeight);

            characterSpeed = 1.0f;
        }

        else if (runningTime > 0.0f && runningTime < 1.0f)
        {
            speedGear = 1;
            gameView.setSize(805, 602);

            characterSpeed = 1.1f;
        }

        else if

        (runningTime > 1.0f && runningTime < 2.0f)
        {
            speedGear = 1;
            gameView.setSize(810, 605);
            characterSpeed = 1.3f;
        }
        else if
        (runningTime > 2.0f && runningTime < 3.0f)
        {
            speedGear = 2;
            gameView.setSize(820, 610);

            characterSpeed = 1.6f;
        }
        else if (runningTime > 3.0f && runningTime < 4.0f)
        {
            speedGear = 3;
            gameView.setSize(830, 615);

            characterSpeed = 1.9f;
        }
        else if (runningTime > 4.0f && runningTime < 5.0f)
        {
            speedGear = 4;
            gameView.setSize(840, 620);

            characterSpeed = 2.2f;
        }
        else if ( runningTime == 5.0f)
        {
            speedGear = 5;
            gameView.setSize(850, 625);

            characterSpeed = characterSpeedMax;
        }

        else if (characterSpeed > characterSpeedMax)
        {
            speedGear = 5;
            gameView.setSize(860, 630);

            characterSpeed = characterSpeedMax;
        }


        // std::cout << runningTime << " " << direction << " " <<  directionPrevious << " " << characterSpeed<< std::endl;

        if (colis)
        {

            if ((canMove(RIGHT) == false) || (canMove(LEFT) == false) || (direction==MWEngine::STOP))
            {
                runningTime = 0.0f;
                runningClock.restart();
            }


            // std::cout << "problem 000 jumping" <<  character.jumping << " safe " << std::endl;
            if ((direction == MWEngine::LEFT) && (colisDirectionX == MWEngine::LEFT))
            {
                character.spritewizard.setPosition(characterOldPos.left, character.spritewizard.getGlobalBounds().top);
                tile.moveRight(deltaTime, characterSpeed);
                bgd.moveRight(deltaTime, characterSpeed);
                character.stopX();
                //std::cout << "problem 000 jumping" <<  character.jumping << " safe " << std::endl;


            }
            if ((direction == MWEngine::RIGHT) && (colisDirectionX == MWEngine::RIGHT))
            {
                character.spritewizard.setPosition(characterOldPos.left, character.spritewizard.getGlobalBounds().top);
                tile.moveLeft(deltaTime, characterSpeed);
                bgd.moveLeft(deltaTime, characterSpeed);
                character.stopX();


            }
        }
        else
        {
            // std::cout << "problem 007" << std::endl;
            characterOldPos = character.spritewizard.getGlobalBounds();

        }
        colis = false;

        if (nextLevel)
        {
            level++;

            hud.setLevel(level);
            tile.loadLevel(level);
            character.start();
            //hud.restart();
            nextLevel = false;
            character.moving = 0;
            direction = MWEngine::STOP;
            bgd.spriteback.setPosition(-350, (-character.spritewizard.getPosition().y / 16 - 20) - 400);
            startLevel(level);

        }

        /** Global iteration over spear sprites */
        for (std::vector<MagicSprite>::reverse_iterator its = tile.spears.rbegin(); its != tile.spears.rend(); ++its)
        {
            sf::FloatRect tilePos = its->getGlobalBounds();

            // MagicSprite localSprite;
            // localSprite = *its;

            float ocx1, ocx2, ocy1, ocy2;

            ocx1 = tilePos.left;
            ocy1 = tilePos.top;
            ocx2 = tilePos.left + tilePos.width;
            ocy2 = tilePos.top + tilePos.height;

            sf::FloatRect r1(sf::Vector2f(ccx1, ccy1), sf::Vector2f(ccx2 - ccx1, ccy2 - ccy1));
            sf::FloatRect r2(sf::Vector2f(ocx1, ocy1), sf::Vector2f(ocx2 - ocx1, ocy2 - ocy1));

            rct2.setSize(sf::Vector2f(ocx2 - ocx1, ocy2 - ocy1));
            rct2.setPosition(ocx1, ocy1);

            if (r1.intersects(r2))
            {
                alive = 0;
                direction = MWEngine::STOP;
                character.moving = 0;
                livesCur--;

                audioEngine.musicStab();
                audioEngine.playStab();
            }
        }
        colCounter = tile.stars.size();


        /** Global iteration over skull sprites */
        for (std::vector<MagicSprite>::reverse_iterator its = tile.skulls.rbegin(); its != tile.skulls.rend(); ++its)
        {
            sf::FloatRect tilePos = its->getGlobalBounds();
            its->animate(deltaTime);


            float ocx1, ocx2, ocy1, ocy2;

            ocx1 = tilePos.left;
            ocy1 = tilePos.top;
            ocx2 = tilePos.left + tilePos.width;
            ocy2 = tilePos.top + tilePos.height;

            sf::FloatRect r1(sf::Vector2f(ccx1, ccy1), sf::Vector2f(ccx2 - ccx1, ccy2 - ccy1));

            sf::FloatRect r2(sf::Vector2f(ocx1, ocy1), sf::Vector2f(ocx2 - ocx1, ocy2 - ocy1));

            rct2.setSize(sf::Vector2f(ocx2 - ocx1, ocy2 - ocy1));
            rct2.setPosition(ocx1, ocy1);

            if (r1.intersects(r2))
            {
                alive = 0;
                direction = MWEngine::STOP;
                character.moving = 0;
                livesCur--;
                audioEngine.musicStab();

                audioEngine.playStab();
            }
        }
        colCounter = tile.stars.size() - 1;

        /** Global iteration over stars sprites */
        for (std::vector<MagicSprite>::reverse_iterator its = tile.stars.rbegin(); its != tile.stars.rend(); ++its)
        {
            if ((its->toRemove == true) && (its->active == false))
            {
                //tile.stars.erase(tile.stars.begin() + colCounter);

            }
            else  if (its->active == true)
            {

                // good SPRITES

                sf::FloatRect tilePos = its->getGlobalBounds();

                float ocx1, ocx2, ocy1, ocy2;

                ocx1 = tilePos.left;
                ocy1 = tilePos.top;
                ocx2 = tilePos.left + tilePos.width;
                ocy2 = tilePos.top + tilePos.height;

                sf::FloatRect r1(sf::Vector2f(ccx1, ccy1), sf::Vector2f(ccx2 - ccx1, ccy2 - ccy1));
                sf::FloatRect r2(sf::Vector2f(ocx1, ocy1), sf::Vector2f(ocx2 - ocx1, ocy2 - ocy1));

                rct2.setSize(sf::Vector2f(ocx2 - ocx1, ocy2 - ocy1));
                rct2.setPosition(ocx1, ocy1);

                if (r1.intersects(r2))
                {

                    its->setActive(false);
                    its->toRemove = false;

                    colStar = colCounter;

		    
		            //particles = ParticleSystem(1000);

                    hud.collectStar();

                    audioEngine.playStar();

                }
                else
                {
                    its->active = true;
                    its->toRemove = false;
                }

                colCounter--;
            }
            else
            {
                its->collect(deltaTime);
            }


        }



        if (colStar > -1)
        {
           // TODO: remove
        }
    }
    window.clear(sf::Color(0, 0, 0));
offscreen.clear(sf::Color(0,0,0));
    



    /*

        Hud Logic
    */

    if ((gameState == STATE_GAMEPLAY) && (!nextLevel))
    {
        /* This was making points floating around
         * hud.textPoints.setPosition(window.getPosition().x+10, window.getPosition().y);
         */
    }

    if ((gameState == STATE_GAMEPLAY) && (alive == 0) && (!nextLevel))
    {
        if (character.bloodFrame != -1)
        {
            character.blood(dT, character.spritewizard.getPosition().x, character.spritewizard.getPosition().y);
        }
    }

}

void Game::drawLoop()
{
    /**
        DRAWING

        */
    
    if (gameState == STATE_MENU)
    {
        drawHome();
    }
    
    
    if (((gameState == STATE_GAMEPLAY) || (gameState == STATE_LOSTLIFE))  && (!nextLevel))
        drawGamePlay();


    if (gameState == STATE_LOSTLIFE)
    {
        offscreen.draw(hud.pressToContinue);
    }

    if ((gameState == STATE_GAMEPLAY) && (alive == 0) && (character.bloodFrame > 0) && (!nextLevel))
        drawCharacterBlood();

    if (gameState == STATE_STARTLEVEL)
        drawStartLevel();

    if (showGameOver)
        drawGameOver();

    if ((alive == 0) && (livesCur > 0) && (character.bloodFrame < 0))
    {
        gameState = STATE_LOSTLIFE;
        //restartLevel();
    }

    if ((alive == 0) && (livesCur == 0) && (character.bloodFrame == 4))
    {
        showGameOver = true;
    }


        updateOffScreen();

}

/**
    Drawing of the home screen

    */
void Game::drawHome()
{
    offscreen.setView(defaultView);
    homeScreen.animate(deltaTime, screenHeight);
    offscreen.draw(bgd.spritebackMenu);
    offscreen.draw(homeScreen.textTitle);
    offscreen.draw(homeScreen.textStart);
    updateOffScreen();

}

void Game::restartLevel()
{

    tile.loadLevel(level);
    character.start();
    hud.createLives(livesCur);
    alive = 1;
    gameState = STATE_GAMEPLAY;
    character.bloodFrame = 5;
    bgd.spriteback.setPosition(-350, (-character.spritewizard.getPosition().y / 16 - 20) - 400);
    audioEngine.restartLevel();
       // particles = ParticleSystem(10000);

}

void Game::drawCharacterBlood()
{
    offscreen.setView(gameView);
    offscreen.draw(character.spriteblood);
}

void Game::drawGameOver()
{
    offscreen.setView(gameView);
    offscreen.draw(hud.gameOver);
}


void Game::drawStartLevel()
{
    offscreen.setView(defaultView);
    offscreen.draw(bgd.spriteStartLevel);
    offscreen.draw(hud.startLevel);
}

void Game::drawTrees()
{
    //offscreen.draw(bgd.spriteback);
    // for (int i = 0; i < 6; i++)
    // {
    //     offscreen.draw(bgd.trees3[i]);
    // }

    // /** Drawing trees */
    // for (int i = 0; i < 4; i++)
    // {
    //     offscreen.draw(bgd.trees2[i]);
    //     offscreen.draw(bgd.trees[i]);
    // }
}

void Game::drawGamePlay()
{
    /** Drawing background */

    offscreen.setView(gameView);

    offscreen.draw(bgd.spriteback);
    offscreen.draw(bgd.spritebackMountainBack);
    
    sf::Vector2f parPos = sf::Vector2f(character.spritewizard.getPosition());
    
    parPos.x =parPos.x + (character.spritewizard.getLocalBounds().width)/2;
    parPos.y =parPos.y + (character.spritewizard.getLocalBounds().height)/2;
    
    
    //particles.setEmitter(parPos);

    sf::Time tmpTime(dT);
    
      //particles.update(tmpTime);
    //offscreen.draw(bgd.spritebackMountainCenter);
    offscreen.draw(bgd.spritebackMountainFront);

    /** Drawing a cloud */
    offscreen.draw(bgd.spriteCloud);

    /** Drawing a planet */
    offscreen.draw(bgd.spriteplanet);

    /** Drawing trees */
    //drawTrees();

    drawEnvironment();

    /** Drawing exit */
    offscreen.draw(tile.spriteExit);

    /** Drawing blood - if necessary */
    // if (character.bloodFrame > 4)
    //     offscreen.draw(character.spritewizard, &spriteShader);

     offscreen.draw(character.spritewizard);

        


    /** DEBUG DRAW */
    if (showRect)
    {
        offscreen.draw(rct1);
        offscreen.draw(rctColl);
    }
    
    
    //if ((character.jumping==3) || (character.jumping==1))
    //{
    // offscreen.draw(particles);
    //}
    
    
    
    offscreen.setView(defaultView);

    /** Drawing HUD head up display */
    for (int i = 0; i < livesCur; i++)
        offscreen.draw(hud.lives[i]);

    if ((character.spritewizard.getPosition().y > screenHeight + 100) && alive == 1)
    {
        alive = 0;
        livesCur--;
    }
    offscreen.draw(hud.textPoints);

    //updateOffScreen();
    
    

    
}


void Game::updateOffScreen()
{
  
      spriteShader.setParameter("source", offscreen.getTexture());

    sf::Sprite temp(offscreen.getTexture());
    temp.scale(screenWidth/1920.0, screenHeight/1080.0);
    temp.setPosition(0, 0);
    
    // Without this everything was upside down :)    
    offscreen.display();

    //sf::Texture temp2 =  temp.getTexture();
    
    
    
    window.draw(temp);
    //temp.display();
    //window.draw(temp);
    window.display();
}



void Game::drawEnvironment()
{

    offscreen.setView(gameView);

    /** Drawing tiles */
    drawTiles();
    /** Drawing stars */
    drawStars();
    /** Drawing spears */
    drawSpears();
}


/**
    Drawing stars

    */
void Game::drawStars()
{
    for (std::vector<MagicSprite>::reverse_iterator it = tile.stars.rbegin(); it != tile.stars.rend(); ++it)
    {
        if (it->toRemove == false)
            offscreen.draw(*it);
    }
}

void Game::drawSpears()
{
    for (std::vector<MagicSprite>::reverse_iterator it = tile.spears.rbegin(); it != tile.spears.rend(); ++it)
    {
        offscreen.draw(*it);
    }
    for (std::vector<MagicSprite>::reverse_iterator it = tile.skulls.rbegin(); it != tile.skulls.rend(); ++it)
    {
        offscreen.draw(*it);
    }
}

void Game::drawTiles()
{
    for (std::vector<MagicSprite>::reverse_iterator it = tile.tiles.rbegin(); it != tile.tiles.rend(); ++it)
    {
        offscreen.draw(*it);
    }
}
/**
    Game Constructor

    */
Game::Game(int screenWidthInit, int screenHeightInit)
    : audioEngine()
    , tile(0)
    , character()
    , hud(screenWidthInit, screenHeightInit, character.spritewizard, 0)
    , bgd(screenWidthInit, screenHeightInit)
    , Clock()
    , deltaTime(Clock.restart().asSeconds())
    , homeScreen(screenWidthInit, screenHeightInit)
    , ownVideoMode(screenWidthInit, screenHeightInit)
    , window(ownVideoMode, "Magic Wizard")
    , wizardPos(character.spritewizard.getGlobalBounds())
    , showRect(false)
    ,defaultView(window.getDefaultView())
    , gameView(sf::FloatRect(0, 0, screenWidthInit, screenHeightInit))
    //, particles(10)
   
{
  
  if (!spriteShader.loadFromFile("assets/shaders/simply.vert", "assets/shaders/simply.frag"))
{
  
  std::exit(1);
}

  
  
  if(!offscreen.create(1920,1080,false))
  {
    std::exit(1);
  }
  offscreen.setSmooth(true);
  //defaultView.=
  
   //defaultView =
  
  
  //defaultView(offscreen.getDefaultView());
    screenWidth = screenWidthInit;
    screenHeight = screenHeightInit;

    /* Screen Definition

    0 - main screen
    1 - game screen
    2 - pause screen
    */


    gameView.zoom(1);
    gameState = STATE_MENU;
    level = 0;
    nextLevel = false;
    alive = 1;
    showGameOver = false;
    characterOldPos = character.spritewizard.getGlobalBounds();
    speedGear = 1;
    speedGear = 5;
    /* lives of the character */
    livesStart = 3;
    livesCur = livesStart;
    colStar = -1;
    rct1.setSize(sf::Vector2f(0, 0));
    rct2.setSize(sf::Vector2f(0, 0));
    rct1.setFillColor(sf::Color(255, 255, 120, 120));
    rctColl.setFillColor(sf::Color(125, 255, 220, 120));
    rct1.setOutlineThickness(0);
    rct1.setPosition(10, 20);
    rct2.setOutlineThickness(5);
    rct2.setPosition(100, 100);
    rctColl.setPosition(0, 0);
    rctColl.setOutlineColor(sf::Color::Red);
    srand (time(NULL));
    border = 20.0f;
    MWEngine::Game gameEngine(MWEngine::Audio myAudioEngine);
    audioEngine.playMusicMenu();
    direction = MWEngine::STOP;
    directionPrevious = MWEngine::STOP;
    bgd.initScale();
    bgd.initMove();


    characterSpeed = 1.0f;
    characterSpeedMax = 2.5f;

    runningTime = 0.0f;



    footSize = 5;

    /// Main loop of the game
    while (window.isOpen())
    {
        deltaTime = Clock.restart().asSeconds();
        dT = sf::seconds(deltaTime);
        while (window.pollEvent(event))
            eventLoop();
        logicLoop();
        drawLoop();
    }


}



void Game::startLevel(int levelNumber)
{
    alive = 1;
    gameState = STATE_STARTLEVEL;
    audioEngine.stopMusicMenu();
    audioEngine.stopMusicGame();
    audioEngine.playMusicStartLevel();
    level = levelNumber;
    hud.setLevel(level);
    


}


/**
    Starts the game

    */

void Game::start()
{
    alive = 1;
    gameState = STATE_GAMEPLAY;
    tile.loadLevel(level);
    character.start();
    //livesCur = livesStart;
    hud.createLives(100);
    hud.restart();
    audioEngine.restartLevel();
    audioEngine.stopMusicMenu();
    audioEngine.stopMusicStartLevel();
    audioEngine.playMusicGame();
    character.moving = 0;
    direction = 0;
    hud.setLevel(level);
}

/**
    Main loop

    */
void Game::loop()
{

}

/**
    Stops the game

    */

void Game::stop()
{

}


}
