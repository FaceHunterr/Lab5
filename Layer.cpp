#include "Layer.h"
#include "Brush.h"


Layer::Layer(const sf::Vector2f& pos, const sf::Vector2f& s, bool canDraw, bool isActive) :
  Object(pos, s), Interactive(canDraw, isActive)
{
  color = sf::Color(255, 255, 255, 255);
  rTexture.create(int(s.x), int(s.y));
  rTexture.clear(color);
  setSprite(rTexture.getTexture());

}

Layer::Layer(const sf::Vector2f& pos, const sf::Vector2f& s, const sf::Color& col, bool canDraw, bool isActive) :
  Object(pos, s), Interactive(canDraw, isActive)
{
  color = col;
  rTexture.create(int(s.x), int(s.y));
  rTexture.clear(color);
  setSprite(rTexture.getTexture());
}

void Layer::update()
{
  //getRTexture().clear(getColor());
}

void Layer::Clear()
{
  getRTexture().clear(getColor());
}

void Layer::click(Brush& brush)
{

  if (isDrawing() && sf::Mouse::isButtonPressed(sf::Mouse::Left))
  {
    brush.paint(*this);
  }
}

/*void Layer::draw(sf::RenderWindow& win)
{
  rTexture.clear(color);
  rTexture.display();
  setSprite(rTexture.getTexture());
  win.draw(getSprite());
}*/
