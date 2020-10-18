#pragma once
class Brush;
class Interactive
{
private:
  bool drawing;
  bool active;
public:
  Interactive(bool canDraw, bool isActive = true) : drawing(canDraw), active(isActive) {}
  virtual void click(Brush& brush) = 0;
  bool isDrawing(void) const { return drawing; }
  void setDrawing(bool dr) { drawing = dr; }
  bool isActive(void) { return active; }
  void setActive(bool isActive) { active = isActive; }
};

