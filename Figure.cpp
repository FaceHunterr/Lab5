#include "Figure.h"
#include "EllipseShape.h"

Figure::Figure(Pencil* pencil)
  : Brush(*pencil)
{
  mainPencil = pencil;
  active = false;
  type = figureType::NONE;
}

void Figure::paint(Layer& layer)
{
  if (!active)
  {
    active = true;
    figPosition = getPosition();
    //std::cout << "1";
  }
  sf::Vector2f resultSize;
  sf::Vector2f resultPos;
  

  switch (type)
  {
    case figureType::ELLIPSE:
    {
      resultPos.x = figPosition.x < getPosition().x ? figPosition.x : getPosition().x;
      resultPos.y = figPosition.y > getPosition().y ? figPosition.y : getPosition().y;
        //resultPos.y = (figPosition.y);
        resultSize.x = abs(getPosition().x - figPosition.x) / 2;
        resultSize.y = abs(getPosition().y - figPosition.y) / 2;

      EllipseShape shape(resultSize);
      shape.setFillColor(mainPencil->getColor());
      shape.setPosition( - layer.getPosition().x + resultPos.x, layer.getPosition().y + layer.getSize().y - resultPos.y);
      layer.getRTexture().draw(shape);
      break;
    }
    case figureType::EMPTY_ELLIPSE:
    {
      resultPos.x = figPosition.x < getPosition().x ? figPosition.x : getPosition().x;
      resultPos.y = figPosition.y > getPosition().y ? figPosition.y : getPosition().y;
      //resultPos.y = (figPosition.y);
      resultSize.x = abs(getPosition().x - figPosition.x) / 2;
      resultSize.y = abs(getPosition().y - figPosition.y) / 2;

      EllipseShape shape(resultSize);
      shape.setFillColor(sf::Color::Transparent);
      shape.setOutlineColor(mainPencil->getColor());
      shape.setOutlineThickness(mainPencil->getThickness());
      shape.setPosition(-layer.getPosition().x + resultPos.x, layer.getPosition().y + layer.getSize().y - resultPos.y);
      layer.getRTexture().draw(shape);
      break;
    }

  default:
    break;
  }
}
