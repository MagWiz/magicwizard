#ifndef VIDEOEFFECT_H
#define VIDEOEFFECT_H
#include <SFML/Graphics.hpp>

namespace MWEngine
{
class VideoEffect

{
public:
    

public:
    VideoEffect();
    void apply(const sf::Shader&, sf::RenderTarget&);
    void bright(const sf::RenderTexture& input, sf::RenderTexture& output);
    void blur(const sf::RenderTexture& input, sf::RenderTexture& output);
    void add(const sf::RenderTexture& input1,const sf::RenderTexture& input2,   sf::RenderTexture& output);
    int sizeX;
    int sizeY;
    float sineMod;
    
private:
  sf::Shader brightShader;
  sf::Shader gBlurShader;
  sf::Shader addShader;

  
  
    
};
}
#endif