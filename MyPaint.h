#pragma once
#include "SFML/Graphics.hpp"
#include "Layer.h"
#include "Pencil.h"
#include "Eraser.h"
#include "Panel.h"
#include "ColorPanel.h"
#include "Figure.h"
#include "FigureLayer.h"
class MyPaint
{
private:
  sf::RenderWindow window;
  Layer* backGround;
  Layer* drawingSpace;
  FigureLayer* figureLayer;
  Brush* curBrush;
  Pencil* pencil;
  Eraser* eraser;
  Layer* curLayer;
  Panel* mainPanel;
  ColorPanel* colorPanel;
  Figure* figure;
  sf::Event event;


public:
  MyPaint(const std::string& title, int width, int height);
  ~MyPaint();
  void go(void);
  void update(void);
  void draw(void);
  void mouseClick(void);
  void setCurLayer(void);
  friend class Panel;
  friend class ColorPanel;
};

