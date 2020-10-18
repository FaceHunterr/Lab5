#pragma once
#include "Layer.h"
#include "Button.h"
#include <vector>

class MyPaint;

class Panel : public Layer
{
private:
  std::vector<Button*> buttons;
  MyPaint* thisApp;
  bool buttPressed = false;

public:
  Panel(const sf::Vector2f& pos, const sf::Vector2f& s, const sf::Color& col, MyPaint* myPaint);
  ~Panel();
  void addButton(const sf::Vector2f& relativePos, const sf::Vector2f& RelativeSize, const std::string& fileName, Button::butType t);
  virtual void draw(sf::RenderWindow& win);
  virtual void click(Brush& brush);
  virtual void activateButton(Button::butType butType);
  MyPaint* getAppPointer(void) { return thisApp; }

};

