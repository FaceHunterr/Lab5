#pragma once
#include "Brush.h"
class Pencil : public Brush 
{
private:
  
public:
  //void update(sf::RenderWindow& win);
  friend class Figure;
  void paint(Layer& layer);
  Pencil(const sf::Vector2f& pos, const sf::Vector2f& s, const std::string& fileName, const sf::Color& col = sf::Color::Black, unsigned int thick = 5);
  void draw(sf::RenderWindow& win);
  void endPaint(void) {}
};

