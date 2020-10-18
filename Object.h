#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
class Object
{
private:
  sf::Vector2f position;
  sf::Vector2f size;
  sf::Sprite sprite;
protected:
  Object(const sf::Vector2f& pos, const sf::Vector2f& s);
public:
  void setPosition(const sf::Vector2f& pos);
  void setSize(const sf::Vector2f& s);
  void setSprite(const sf::Texture& texture);
  const sf::Vector2f& getPosition(void) const { return position; }
  const sf::Vector2f& getSize(void) const { return size; }
  const sf::Sprite& getSprite() const { return sprite; }
  void draw(sf::RenderWindow& win);
  void draw(sf::RenderTexture& rTexture);
  bool isCrossed(Object& obj2) const;
};

