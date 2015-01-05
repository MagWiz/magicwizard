#include "helpers.h"

namespace MWEngine {
sf::VertexArray getRTVertices(sf::RenderTarget& target)
  {
    /*
     * Returns VertexArray vertices for provided RenderTarget
     * Inspired by https://github.com/LaurentGomila/SFML-Game-Development-Book/blob/master/10_Network/Source/PostEffect.cpp
     */
    sf::Vector2f targetSize = static_cast<sf::Vector2f>(target.getSize());
    sf::VertexArray vertices(sf::TrianglesStrip, 4);
    vertices[0] = sf::Vertex(sf::Vector2f(0, 0),            sf::Vector2f(0, 1));
    vertices[1] = sf::Vertex(sf::Vector2f(targetSize.x, 0), sf::Vector2f(1, 1));
    vertices[2] = sf::Vertex(sf::Vector2f(0, targetSize.y), sf::Vector2f(0, 0));
    vertices[3] = sf::Vertex(sf::Vector2f(targetSize),      sf::Vector2f(1, 0));
    return vertices;
  }
  

}
