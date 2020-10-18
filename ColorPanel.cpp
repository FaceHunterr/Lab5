#include "ColorPanel.h"
#include "MyPaint.h"

ColorPanel::ColorPanel(const sf::Vector2f& pos, const sf::Vector2f& s, const sf::Color& col, MyPaint* myPaint) :
  Panel(pos, s, col, myPaint), active(false)
{
  addButton(sf::Vector2f(getSize().x - 51, 1), sf::Vector2f(50, 50), "Images\\cancel.png", Button::butType::CANCEL);
  addButton(sf::Vector2f(getSize().x - 101, 1), sf::Vector2f(50, 50), "Images\\accept.png", Button::butType::ACCEPT);
  colorIndicator = new Layer(getPosition() + getSize() - sf::Vector2f(90, 90), sf::Vector2f(50, 50), getAppPointer()->pencil->getColor(), false);
  colorScheme1 = new ColorScheme(getPosition() + sf::Vector2f(20, 20), sf::Vector2f(150, 150), getAppPointer()->pencil->getColor(),
    sf::Color::Black, sf::Color(255, 0, 0), sf::Color(0, 255, 0), sf::Vector2i(100, 100));
  colorScheme2 = new ColorScheme(getPosition() + sf::Vector2f(190, 20), sf::Vector2f(50, 150), getAppPointer()->pencil->getColor(),
    sf::Color::White, sf::Color(0, 0, 255), sf::Color(0, 0, 255), sf::Vector2i(1, 100));
  colorScheme1->reDraw();
}

ColorPanel::~ColorPanel()
{
  delete colorIndicator;
  delete colorScheme1;
  delete colorScheme2;
}

void ColorPanel::draw(sf::RenderWindow& win)
{
  if (isActive())
  { 
    Panel::draw(win);
    colorIndicator->draw(win);
    colorScheme1->draw(win);
    colorScheme2->draw(win);
  }
}

void ColorPanel::click(Brush& brush)
{
  if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
  {
    if (colorScheme1->isCrossed(brush))
    {
      sf::Color newColor = colorScheme1->getColByCoordinate(sf::Vector2f(brush.getPosition() - colorScheme1->getPosition()));
      newColor.b = 0;
      colorScheme2->leftUpperCol = newColor;
      newColor.b = 255;
      colorScheme2->leftBottomCol = newColor;
      colorScheme2->reDraw();
      //colorScheme2->leftUpperCol = colorIndicator->getColor();
    }
    else if (colorScheme2->isCrossed(brush))
    {
      //colorIndicator->setColor(colorScheme1->getColByCoordinate(sf::Vector2f(brush.getPosition() - colorScheme1->getPosition())));
      
      colorIndicator->setColor(colorScheme2->getColByCoordinate(sf::Vector2f(brush.getPosition() - colorScheme2->getPosition())));
      
    }
    
      
    colorIndicator->Clear();

  }
  Panel::click(brush);
  
}

void ColorPanel::activateButton(Button::butType butType)
{
  //if(getAppPointer()->event.type == sf::Event::MouseButtonReleased )
  switch (butType)
  {
  case Button::butType::CANCEL:
    setActive(false);
    break;
  case Button::butType::ACCEPT:
    getAppPointer()->pencil->setColor(colorIndicator->getColor());
    setActive(false);
    //getAppPointer()->pencil->setColor(colorIndicator->getColor());
    break;
  default:
    break;
  }

}
