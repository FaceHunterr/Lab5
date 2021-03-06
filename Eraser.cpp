#include "Eraser.h"
#include "Layer.h"

void Eraser::paint(Layer& layer)
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

Eraser::Eraser(const sf::Vector2f& pos, const sf::Vector2f& s, const std::string& fileName, unsigned int thick) :
  Brush(pos, s, fileName) {
  setThickness(thick);
}

void Eraser::update(sf::RenderWindow& win, const Layer* layer)
{
  if(layer->isDrawing())
    setColor(layer->getColor());
  Brush::update(win, layer);
}

void Eraser::draw(sf::RenderWindow& win)
{
  if (isVisible()) {
    sf::CircleShape circle((float)getThickness());
    circle.setFillColor(getColor());
    circle.setOutlineColor(sf::Color::Black);
    circle.setOutlineThickness(1);
    circle.setPosition(getPosition().x - getThickness(), getPosition().y - getThickness());
    win.draw(circle);
  }
  Brush::draw(win);
}