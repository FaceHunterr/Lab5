#include "FigureLayer.h"
#include "Brush.h"

FigureLayer::FigureLayer(const sf::Vector2f& pos, const sf::Vector2f& s) :
  Layer(pos, s, sf::Color::Transparent, true, false)
{
  readyToDraw = false;
  drawed = true;
}

void FigureLayer::update()
{
  Clear();
}

void FigureLayer::click(Brush& brush)
{
  if (isDrawing() && sf::Mouse::isButtonPressed(sf::Mouse::Left))
  {
    drawed = false;
    Clear();
    brush.paint(*this);
    
  }
  if (isDrawing() && !sf::Mouse::isButtonPressed(sf::Mouse::Left))
  {
    if (!drawed)
    {
      //std::cout << "2";
      readyToDraw = true;
      drawed = true;
      //Clear();
    }
    brush.endPaint();
  }
}

void FigureLayer::draw(Layer& l)
{
  sf::Sprite newSprite(getSprite());
  //std::cout << getPosition().y + 23;
  newSprite.setTextureRect(sf::IntRect(0, int(getSize().y), int(getSize().x), -int(getSize().y)));
  newSprite.setPosition(sf::Vector2f(getPosition().x - l.getPosition().x,-getPosition().y + l.getPosition().y));
  l.getRTexture().draw(newSprite);
}
