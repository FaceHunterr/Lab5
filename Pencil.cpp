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
  setThickness(thick);
}

void Pencil::paint(Layer& layer)
{
  sf::Vector2f vec1 = getPosition() - getPrevPosition();
  float vecLen = sqrt(vec1.x * vec1.x + vec1.y * vec1.y);
  int num = int(2 * vecLen / getThickness()) + 1;
  sf::Vector2f vec2(vec1.x / num, -vec1.y / num);
  sf::Vector2f startPos(getPrevPosition().x - layer.getPosition().x - getThickness(), layer.getSize().y - getPrevPosition().y + layer.getPosition().y - getThickness());
  sf::CircleShape circle((float)getThickness());
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
    sf::CircleShape circle((float)getThickness());
    circle.setFillColor(getColor());
    circle.setPosition(getPosition().x  - getThickness(), getPosition().y - getThickness());
    win.draw(circle);
  }
  Brush::draw(win);
}
