#pragma once
#include "Layer.h"
class FigureLayer : public Layer
{
private:
  bool readyToDraw;
  bool drawed;
public:
  FigureLayer(const sf::Vector2f& pos, const sf::Vector2f& s);
  void update();
  void click(Brush& brush);
  bool isReadyToDraw(void) { return readyToDraw; }
  void setReadyToDraw(bool r) { readyToDraw = r; }
  void draw(Layer& l);
  void draw(sf::RenderWindow& win) { Object::draw(win); }
  void draw(sf::RenderTexture& rTexture) { Object::draw(rTexture); }
};

