#pragma once
#include "Object.h"
#include "Interactive.h"
class Layer : public Object, public Interactive
{
private:
  sf::RenderTexture rTexture;
  sf::Texture texture;
  sf::Color color;
public:
  Layer(const sf::Vector2f& pos, const sf::Vector2f& s, bool canDraw = true, bool isActive = true);
  Layer(const sf::Vector2f& pos, const sf::Vector2f& s, const sf::Color& col, bool canDraw = true, bool isActive = true);
  void update(void);
  virtual void click(Brush& brush);
  sf::RenderTexture& getRTexture(void) { return rTexture; }
  const sf::Color& getColor(void) const { return color; }
  void setColor(const sf::Color& col) { color = col; }
  void Clear();
  
  //void draw(sf::RenderWindow& win);
};

