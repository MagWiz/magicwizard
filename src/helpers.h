#ifndef HELPERS_H
#define HELPERS_H
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/VertexArray.hpp>

namespace MWEngine
{
  sf::VertexArray  getRTVertices(sf::RenderTarget& output);
}
#endif