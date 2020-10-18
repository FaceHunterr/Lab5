#include "Panel.h"
#include "MyPaint.h"



Panel::Panel(const sf::Vector2f& pos, const sf::Vector2f& s, const sf::Color& col, MyPaint* myPaint) :
  Layer(pos, s, col, false)
{
  thisApp = myPaint;
}

Panel::~Panel()
{
  for (auto button : buttons)
  {
    delete button;
  }
}

void Panel::addButton(const sf::Vector2f& relativePos, const sf::Vector2f& relativeSize, const std::string& fileName, Button::butType t)
{
  sf::Vector2f pos = relativePos + getPosition();
  sf::Vector2f s = relativeSize;
  if (relativePos.x < 1)
    pos.x = relativePos.x * getPosition().x + getPosition().x;
  if (relativePos.y < 1)
    pos.y = relativePos.y * getPosition().y + getPosition().y;
  if (relativeSize.x < 1)
    s.x = relativeSize.x * getSize().x;
  if (relativeSize.y < 1)
    s.y = relativeSize.y * getSize().y;

  buttons.push_back(new Button(
    pos,
    s,
    fileName,
    t));
}

void Panel::draw(sf::RenderWindow& win)
{
  Layer::draw(win);
  for (auto button : buttons)
  {
    button->draw(win);
  }
}
 
void Panel::click(Brush& brush)
{

  if (thisApp->event.type == sf::Event::MouseButtonReleased && thisApp->event.key.code == sf::Mouse::Left && !buttPressed)
  {
    for (auto button : buttons)
    {
      if (button->isCrossed((Object&)brush))
      {
        activateButton(button->getType());
        break;
      }
    }
    buttPressed = true;
  }
  if (thisApp->event.type != sf::Event::MouseButtonReleased)
    buttPressed = false;
}

void Panel::activateButton(Button::butType butType)
{
  switch (butType)
  {
  case Button::butType::ERRASER:
    thisApp->curBrush = thisApp->eraser;
    thisApp->figureLayer->setActive(false);
    break;
  case Button::butType::PENCIL:
    thisApp->curBrush = thisApp->pencil;
    thisApp->figureLayer->setActive(false);
    break;
  case Button::butType::THICK_UP:
    if(thisApp->curBrush == thisApp->eraser)
      thisApp->curBrush->changeThickness(1);
    else
    {
      thisApp->pencil->changeThickness(1);
    }
    break;
  case Button::butType::THICK_DOWN:
    if (thisApp->curBrush == thisApp->eraser)
      thisApp->curBrush->changeThickness(-1);
    else
    {
      thisApp->pencil->changeThickness(-1);
    }
    break;
  case Button::butType::CLEAR_ALL:
    thisApp->drawingSpace->getRTexture().clear(thisApp->drawingSpace->getColor());
    break;
  case Button::butType::COLOR_PANEL:
    thisApp->colorPanel->setActive(true);
    break;
  case Button::butType::FIGURE_ELLIPSE:
    thisApp->figureLayer->setActive(true);
    thisApp->curBrush = thisApp->figure;
    thisApp->figure->setType(Figure::figureType::ELLIPSE);
    break;
  case Button::butType::FIGURE_EMPTY_ELLIPSE:
    thisApp->figureLayer->setActive(true);
    thisApp->curBrush = thisApp->figure;
    thisApp->figure->setType(Figure::figureType::EMPTY_ELLIPSE);
    break;
  default:
    break;
  }
}