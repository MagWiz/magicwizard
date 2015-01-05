#ifndef CHARACTER_H
#define CHARACTER_H
#include <SFML/Graphics.hpp>
#include "enums.h"
#include <array>
using namespace std;
namespace MWEngine
{
class Character
{


private:
    int wizRight;
    int wizCounter;
    sf::Time m_frameTime;
    sf::Time m_currentTime;

    sf::Time m_currentTimeJump;

    sf::Texture textureblood;

public:

    void start(float posX);
    int defaultY;

    int  bloodFrame;

    int charFly;
    int moving; // 0 - not moving
    int jumping; // 0 - not, 1 - up, 2 down
    int alive;
    float jumpSpeed;
    float gravity;

    float jumpSize;
    float jumpMoment;

    std::array<int,5> collides;
    std::array<int,5> direction;


    sf::IntRect wizF  [1];
    sf::IntRect wizLef  [4];
    sf::IntRect wizRig  [4];
    sf::Texture texturewizard;

    sf::Sprite spritewizard;
    sf::Sprite spriteblood;

    vector<sf::Sprite> bloodSprites;


    sf::Time getFrameTime() const;

    Character( const Character &);
    Character();
    void setFrame();
    void move(sf::Time);
    void blood(sf::Time, float, float);
    void stop();
    void stopX();
    void fall(float);
    void jump(float);
    void moveLeft(sf::Time);
    void moveRight(sf::Time);
    sf::Vector2f velocity;
};
}
#endif

