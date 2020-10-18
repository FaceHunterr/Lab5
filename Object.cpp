#include "Object.h"

Object::Object(const sf::Vector2f& pos, const sf::Vector2f& s)
{
  setPosition(pos);
  setSize(s);
}

void Object::setPosition(const sf::Vector2f& pos)
{
  position = pos;
  sprite.setPosition(pos);
}

void Object::setSize(const sf::Vector2f& s)
{
  size = s;
  sprite.setScale(size.x / sprite.getLocalBounds().width,
    size.y / sprite.getLocalBounds().height);
}

void Object::setSprite(const sf::Texture& texture)
{
  sprite.setTexture(texture);
  sprite.setScale(size.x / sprite.getLocalBounds().width,
    size.y / sprite.getLocalBounds().height);
}

void Object::draw(sf::RenderWindow& win)
{
  win.draw(getSprite());
}

void Object::draw(sf::RenderTexture& rTexture)
{
  //sf::Sprite newSprite(getSprite());
  //newSprite.setPosition(sf::Vector2f(rTexture.get getPosition().x))
  rTexture.draw(getSprite());
}

bool Object::isCrossed(Object& obj2) const
{
  
  if (obj2.getPosition().x > position.x&& obj2.getPosition().x < position.x + size.x &&
    obj2.getPosition().y > position.y&& obj2.getPosition().y < position.y + size.y)
  {
    
    return true;
  }
  return false;
}
