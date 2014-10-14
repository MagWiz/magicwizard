#ifndef MAGICSPRITE_H
#define MAGICSPRITE_H
#include <SFML/Graphics.hpp>
#include "enums.h"
#include <iostream>

using namespace std;
namespace MWEngine
{
class MagicSprite : public sf::Sprite
{

public:
	sf::Vector2f direction;
	int currentDirection;

    explicit MagicSprite(const sf::Texture& texture); 
    MagicSprite();
	void animate(float);
	void collect(float);
	bool active;

	bool toRemove;
	float speed;

	float startY;
	float currentY;
	int diff;

	int oid;
	int directionModifier;

	void setActive(bool);


private: 



};
}
#endif