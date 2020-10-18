#pragma once
#include "Pencil.h"
class Figure :
  public Brush
{
public:
	enum class figureType
	{
    NONE,
    ELLIPSE,
    EMPTY_ELLIPSE,
	};
private:
  sf::Vector2f figPosition;
  Pencil* mainPencil;
  bool active;
  figureType type;
  //sf::RenderTexture rTexture;
public:
  void paint(Layer& layer);
  Figure(Pencil* pencil);
  void setType(figureType t) { type = t; }
  void endPaint(void) { active = false; }


};

