#pragma once
#include "Brush.h"
class Eraser : public Brush
{
private:
  
public:
  void paint(Layer& layer);
  Eraser(const sf::Vector2f& pos, const sf::Vector2f& s, const std::string& fileName, unsigned int thick = 10);
  void draw(sf::RenderWindow& win);
  void update(sf::RenderWindow& win, const Layer* layer);
  void endPaint(void) {}
};

