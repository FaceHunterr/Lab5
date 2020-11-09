#include "Brush.h"


void Brush::setTexture(const std::string& fileName)
{
  texture.loadFromFile(fileName);
}

Brush::Brush(const sf::Vector2f& pos, const sf::Vector2f& s, const std::string& fileName):
  Object(pos, s), color(sf::Color::Black), thickness(5)
{
  setTexture(fileName);
  setSprite(texture);
  visible = false;
}

Brush::Brush(const Brush& brush) :
  Object(brush.getPosition(), brush.getSize())
{
  color = brush.getColor();
  thickness = brush.thickness;
  setSprite(*brush.getSprite().getTexture());
  visible = false;
}

void Brush::draw(sf::RenderWindow& win)
{
  if (visible) {
    win.setMouseCursorVisible(false);
    win.draw(getSprite());
  }
  else
    win.setMouseCursorVisible(true);
}

void  Brush::update(sf::RenderWindow& win, const Layer* layer)
{
  if ((*layer).isDrawing())
    visible = true;
  else
    visible = false;
  updatePosition(win);
  if (thickness > 25)
    thickness = 25;
  else if (thickness < 2)
    thickness = 2;
}

void Brush::updatePosition(sf::RenderWindow& win)
{
  //std::cout << sf::Mouse::getPosition().x - win.getPosition().x << "  " << sf::Mouse::getPosition().y - win.getPosition().y << "\n";
  prevPosition = getPosition();
  setPosition(sf::Vector2f(sf::Mouse::getPosition(win).x, sf::Mouse::getPosition(win).y));
}
