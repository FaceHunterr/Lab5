#pragma once
#include "Panel.h"
#include "ColorScheme.h"
class ColorPanel : public Panel
{
private:
  bool active;
  Layer* colorIndicator;
  ColorScheme* colorScheme1;
  ColorScheme* colorScheme2;
  
public:
  ColorPanel(const sf::Vector2f& pos, const sf::Vector2f& s, const sf::Color& col, MyPaint* myPaint);
  void setActive(bool act) { active = act; }
  bool isActive(void) { return active; }
  void draw(sf::RenderWindow& win);
  void activateButton(Button::butType butType);
  void click(Brush& brush);
  ~ColorPanel();
};

