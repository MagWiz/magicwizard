#include "magicsprite.h"

namespace MWEngine
{
MagicSprite::MagicSprite()
    : direction(0.0f, -1.0f)
    , currentDirection(UP)
    , active(true)
    , toRemove(false)
    , speed(85.0f)
    , startY(0)
    , currentY(0)
    , diff(1)
{

}

void MagicSprite::animate(float deltaTime)
{
    currentY = getPosition().y;
    float diff(startY - currentY);
    if (currentDirection == UP)
    {
        move(0.0f, speed * deltaTime * -1);
        if (diff > 100.0f)
        {
            currentDirection = DOWN;
        }

    }
    else if (currentDirection == DOWN)
    {
        move(0.0f, speed * deltaTime);
        if (currentY > startY)
        {
            currentDirection = UP;
        }

    }

}

void MagicSprite::collect(float deltaTime)
{

    if (toRemove == false)

    {

    	speed = 85.0f;

    	//std::cout << "false" << std::endl;
        diff = 0;
        currentY = (int) getPosition().y;
        diff = (int) startY - currentY;

        if (diff==0)
        	diff = 1;

        directionModifier = 1;
        //std::cout << active << " " << toRemove << " " << currentY << " " <<  startY << " " << " " << " " << "collect " << diff << std::endl;
        float movement = 10;
        movement = -speed * deltaTime;
        if ((movement > 2.0f) || (movement < -2.0f) || (movement==0.0f))
        {
            movement = 1.001 * directionModifier;

        }

        setColor(sf::Color(245, 121, 0, 255 - diff));

            move(0, abs(movement) * -3);
            //scale(1.01, 1.01);


            if (startY - getPosition().y > 255)
            {

				setColor(sf::Color(245, 121, 0, 250));
                toRemove = true;
                currentDirection = STOP;
            }
        
    }

}

void MagicSprite::setActive(bool newActive)
{

    active = newActive;
}

MagicSprite::MagicSprite(const sf::Texture &texture):
    sf::Sprite(texture)
{

}

}

