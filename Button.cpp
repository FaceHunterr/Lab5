#include "Button.h"

Button::Button(const sf::Vector2f& pos, const sf::Vector2f& s, const std::string& fileName, butType t) :
  Object(pos, s), type(t)
{
  texture.loadFromFile(fileName);
  setSprite(texture);
  frame.setSize(getSize());
  frame.setPosition(getPosition());
  frame.setFillColor(sf::Color::Transparent);
  frame.setOutlineThickness(1);
  frame.setOutlineColor(sf::Color::Black);
}

void Button::draw(sf::RenderWindow& win)
{
  Object::draw(win);
  win.draw(frame);
}