#pragma once
#include "Layer.h"
class ColorScheme : public Layer
{
private:
  sf::Color leftUpperCol;
  sf::Color leftBottomCol;
  sf::Color rightUpperCol;
  sf::Vector2f cells;
  friend class ColorPanel;
public:
  ColorScheme(const sf::Vector2f& pos, const sf::Vector2f& s, const sf::Color& col, 
    const sf::Color& LUcol, const sf::Color& LBcol, const sf::Color& RUcol, sf::Vector2i cls);
  void reDraw(void);
  sf::Color getColByCoordinate(const sf::Vector2f& point);
};

