#pragma once
#include "Object.h"
#include <string>
#include "Layer.h"

class Layer;

class Brush : public Object
{
private:
  sf::Texture texture;
  int thickness;
  sf::Color color;
  bool visible;
  sf::Vector2f prevPosition;
protected:
  Brush(const sf::Vector2f& pos, const sf::Vector2f& s, const std::string& fileName);
  Brush(const Brush& br);
public:
  void setTexture(const std::string& fileName);
  virtual void draw(sf::RenderWindow& win);
  void updatePosition(sf::RenderWindow& win);
  void setColor(const sf::Color& col) { color = col; }
  void setThickness(int thick) { thickness = thick; }
  void changeThickness(int thick) { thickness += thick; }
  bool isVisible(void) { return visible; }
  void setPrevPosition(const sf::Vector2f& pos) { prevPosition = pos; }
  const sf::Vector2f& getPrevPosition(void) { return prevPosition; }
  const sf::Color& getColor(void) const { return color; }
  unsigned int getThickness(void) const { return thickness; }
  virtual void update(sf::RenderWindow& win, const Layer* layer);
  virtual void paint(Layer& layer) = 0;
  virtual void endPaint(void) = 0;
};

