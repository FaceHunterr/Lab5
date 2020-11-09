#include "Pencil.h"
#include "Layer.h"
#include <math.h>

const double PI = 3.14159265358979323846;

/*void Pencil::update(sf::RenderWindow& win)
{
  updatePosition(win);
}*/

Pencil::Pencil(const sf::Vector2f& pos, const sf::Vector2f& s, const std::string& fileName, const sf::Color& col, unsigned int thick) :
  Brush(pos, s, fileName)
{
  setColor(col);
  thickness = thick;
}

void Pencil::paint(Layer& layer)
{
  sf::Vector2f vec1 = getPosition() - prevPosition;
  float vecLen = sqrt(vec1.x * vec1.x + vec1.y * vec1.y);
  int num = int(2 * vecLen / thickness) + 1;
  sf::Vector2f vec2(vec1.x / num, -vec1.y / num);
  sf::Vector2f startPos(prevPosition.x - layer.getPosition().x - thickness, layer.getSize().y - prevPosition.y + layer.getPosition().y - thickness);
  sf::CircleShape circle((float)thickness);
  circle.setFillColor(getColor());
  for (int i = 0; i < num; i++)
  {
    circle.setPosition(startPos + sf::Vector2f(vec2.x * i, vec2.y * i));
    layer.getRTexture().draw(circle);
  }
  
}

void Pencil::draw(sf::RenderWindow& win)
{
  if(isVisible())
  {
    sf::CircleShape circle((float)thickness);
    circle.setFillColor(getColor());
    circle.setPosition(getPosition().x  - thickness, getPosition().y - thickness);
    win.draw(circle);
  }
  Brush::draw(win);
}
