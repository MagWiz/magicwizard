#include "videoeffect.h"
#include "helpers.h"
#include <SFML/Graphics.hpp>

#include <iostream>

using namespace std;
namespace MWEngine
{
VideoEffect::VideoEffect()
: sizeX(1)
, sizeY(1)
{
  if (!brightShader.loadFromFile("assets/shaders/simply.vert", "assets/shaders/bright.frag"))
  {
    std::exit(1);
  }
  
  if (!gBlurShader.loadFromFile("assets/shaders/simply.vert", "assets/shaders/gblur.frag"))
  {
    std::exit(1);
  }
  
  if (!addShader.loadFromFile("assets/shaders/simply.vert", "assets/shaders/mix.frag"))
  {
    std::exit(1);
  }
}

void VideoEffect::apply(const sf::Shader& shader, sf::RenderTarget& output)
{
  sf::RenderStates states;
  states.shader    = &shader;
  states.blendMode = sf::BlendNone;
  output.draw(getRTVertices(output), states);
}

void VideoEffect::bright(const sf::RenderTexture& input, sf::RenderTexture& output)
{
  brightShader.setParameter("source", input.getTexture());
  apply(brightShader, output);
  output.display();
}


void VideoEffect::blur(const sf::RenderTexture& input, sf::RenderTexture& output)
{
 gBlurShader.setParameter("source", input.getTexture());
  apply(gBlurShader, output);
  output.display();
}

void VideoEffect::add(const sf::RenderTexture& input1,const sf::RenderTexture& input2,   sf::RenderTexture& output)
{
  addShader.setParameter("source1", input1.getTexture());
  addShader.setParameter("source2", input2.getTexture());
  apply(addShader, output);
  output.display();
}



}
