#include <iostream>
#include "character.h"
#include <SFML/Graphics.hpp>


using namespace std;
namespace MWEngine
{
void Character::start(float posX)
{
    stop();
    spritewizard.setPosition(posX, -0.0f);
}

Character::Character()
{
    alive = 1;

    collides[STOP] = false;
    collides[LEFT] = false;
    collides[RIGHT] = false;
    collides[UP] = false;
    collides[DOWN] = false;   

    direction[STOP] = false;
    direction[LEFT] = false;
    direction[RIGHT] = false;
    direction[UP] = false;
    direction[DOWN] = false;
    

    //* Blood description */
    textureblood.loadFromFile("assets/gfx/blood.png");
    bloodFrame = 5;

    // /spriteblood.setTexture(textureblood);
    //setTextureRect(sf::IntRect(0,0,130,130));
    bloodSprites.push_back(sf::Sprite (textureblood, sf::IntRect(260, 131, 130, 130) ));
    bloodSprites.push_back(sf::Sprite (textureblood, sf::IntRect(130, 131, 130, 130) ));
    bloodSprites.push_back(sf::Sprite (textureblood, sf::IntRect(0, 131, 130, 130) ));
    bloodSprites.push_back(sf::Sprite (textureblood, sf::IntRect(260, 0, 130, 130) ));
    bloodSprites.push_back(sf::Sprite (textureblood, sf::IntRect(130, 0, 130, 130) ));
    bloodSprites.push_back(sf::Sprite (textureblood, sf::IntRect(0, 0, 130, 130) ));

    //blood_d/blood_d_0001.png
    defaultY = 440;
    wizRight = 0;
    wizCounter = 0;

    charFly = 0;
    /*
        0 - stands
        1 - jumps
        2 - falls
    */

    gravity = 0.01f;
    velocity = sf::Vector2f(0, 0);
    jumpSpeed = 10.0f;
    jumping = 2;
    jumpSize = 200.0f;

    m_frameTime = sf::seconds(0.2);

    sf::IntRect wf1(0, 0, 60, 90);
    sf::IntRect wl1(0, 360, 60, 90);
    sf::IntRect wl2(60, 360, 60, 90);
    sf::IntRect wl3(120, 360, 60, 90);
    sf::IntRect wl4(180, 360, 60, 90);
    sf::IntRect wr1(240, 360, 60, 90);
    sf::IntRect wr2(300, 360, 60, 90);
    sf::IntRect wr3(360, 360, 60, 90);
    sf::IntRect wr4(420, 360, 60, 90);
    wizF [0] = wf1;
    wizLef [0] = wl1;
    wizLef [1] = wl2;
    wizLef [2] = wl3;
    wizLef [3] = wl4;
    wizRig [0] = wr1;
    wizRig [1] = wr2;
    wizRig [2] = wr3;
    wizRig [3] = wr4;
    if (!texturewizard.loadFromFile("assets/gfx/wizard_2.png"))
        exit(1);
    texturewizard.setSmooth(true);
    spritewizard.setTexture(texturewizard);
    spritewizard.setTextureRect(wl1);
    spritewizard.scale(0.8, 0.5);
    spritewizard.setPosition(0,0);
    stop();


}

void Character::setFrame()
{
    wizCounter++;

    // std::cout << "setFrame wizCounter " << wizCounter << " wizRight " << wizRight << std::endl;


    if (wizCounter > 3)
    {
        wizCounter = 0;
    }
    //cout << wizCounter << endl;

    if (wizRight == 1)
    {
        spritewizard.setTextureRect(wizRig[wizCounter]);
    }
    else
    {
        spritewizard.setTextureRect(wizLef[wizCounter]);
    }

}



void Character::stop()
{
    moving = 0;
    spritewizard.setTextureRect(wizF[0]);
    m_currentTime += m_frameTime;
    direction[LEFT] = false;
    direction[RIGHT] = false;

}

void Character::stopX()
{
    moving = MWEngine::STOP;

    spritewizard.setTextureRect(wizF[0]);
    m_currentTime += m_frameTime;
    direction[LEFT] = false;
    direction[RIGHT] = false;

}



Character::Character( const Character &other )
    : spritewizard(other.spritewizard)
{

    spritewizard.setTexture(texturewizard);
}

void Character::jump(float deltaTime)
{

    if (jumping == 4)
    {
        defaultY = spritewizard.getPosition().y;

        velocity.y = 40 * -jumpSpeed;
        jumping = 3;
    }


    if ((jumping == 3) || (jumping == 4))
    {
        if (spritewizard.getPosition().y > defaultY - jumpSize )

        {
          
            spritewizard.move(0, velocity.y * deltaTime);
            velocity.y += gravity;
        }
        else
        {

            jumping = 2;
        }

    }

}






void Character::fall(float deltaTime)
{
    if (jumping == 2)
    {
        velocity.y = 30 * jumpSpeed;
        jumping = 1;
    }

    if ((jumping == 1) || (jumping == 2))
    {
        spritewizard.move(0, velocity.y * deltaTime);
        velocity.y += (gravity);
    }
}
void Character::blood(sf::Time deltaTime, float x, float y)
{


    if (alive == 1)
    {
        m_currentTime = sf::Time::Zero;
        alive = 0;

    }
    else m_currentTime += deltaTime;


    if (alive == 0)
    {
        spriteblood = bloodSprites[bloodFrame];
        spriteblood.setPosition(x - 40, y - 40);
        if (m_currentTime >= m_frameTime)
        {

            // reset time
            m_currentTime = sf::Time::Zero;
            bloodFrame--;

        }
    }
}


void Character::move(sf::Time deltaTime)
{

    if (moving == 0)
        m_currentTime += m_frameTime;


    moving = 1;


    m_currentTime += deltaTime;

    if (m_currentTime >= m_frameTime)
    {

        m_currentTime = sf::Time::Zero;

        setFrame();
    }


}


void Character::moveRight(sf::Time deltaTime)
{
    if (wizRight == 0)
    {
        wizRight = 1;
        wizCounter = 0;
        m_currentTime += m_frameTime;
    }
    move(deltaTime);

}

void Character::moveLeft(sf::Time deltaTime)
{


    if (wizRight == 1)
    {
        wizRight = 0;
        wizCounter = 0;
        m_currentTime += m_frameTime;
    }
    move(deltaTime);
}
}