#ifndef BLOOMEFFECT_H
#define BLOOMEFFECT_H
#include "videoeffect.h"
#include <SFML/Graphics.hpp>

namespace MWEngine
{
class BloomEffect
: public MWEngine::VideoEffect
{ 
public:
    sf::RenderTexture textureBright;
    sf::RenderTexture textureBlur;
    
    void perform(const sf::RenderTexture& input, sf::RenderTexture& output);
    void perform(const sf::RenderTexture& input, sf::RenderTexture& output, float sineOscilator);

    

public:
    BloomEffect();
    
    
private:
  
  
    
};
}
#endif