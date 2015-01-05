#include "bloomeffect.h"
#include "helpers.h"
#include <SFML/Graphics.hpp>

#include <iostream>
#include <cmath>

using namespace std;
namespace MWEngine
{
BloomEffect::BloomEffect()
: VideoEffect()

{
}

void BloomEffect::perform(const sf::RenderTexture& input, sf::RenderTexture& output, float sineOscilator)
{
  sineMod = sineOscilator;
  perform(input, output);
}

void BloomEffect::perform(const sf::RenderTexture& input, sf::RenderTexture& output)
{
  
  sf::Vector2f inputSize(input.getSize());
   
  if ((inputSize.x!=sizeX)||(inputSize.y!=sizeY))
  {
    
    textureBright.create(inputSize.x, inputSize.y);
    textureBlur.create(inputSize.x, inputSize.y);  
    textureBright.setSmooth(true);
    textureBlur.setSmooth(true);
    output.setSmooth(true);
    sizeX = inputSize.x;
    sizeY = inputSize.y;
  }
  
  
  
  bright(input, textureBright);
  blur(textureBright,textureBlur);
  add(input, textureBlur, output);
  
}

}