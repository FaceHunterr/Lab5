#include "ColorScheme.h"

ColorScheme::ColorScheme(const sf::Vector2f& pos, const sf::Vector2f& s, const sf::Color& col,
  const sf::Color& LUcol, const sf::Color& LBcol, const sf::Color& RUcol, sf::Vector2i cls) :
  Layer(pos, s, col, false), leftUpperCol(LUcol), leftBottomCol(LBcol), rightUpperCol(RUcol), cells(cls)
{
  reDraw();
}

void ColorScheme::reDraw()
{
  double rdx, gdx, bdx, rdy, gdy, bdy;
  rdx = double(rightUpperCol.r - leftUpperCol.r) / cells.x;
  gdx = double(rightUpperCol.g - leftUpperCol.g) / cells.x;
  bdx = double(rightUpperCol.b - leftUpperCol.b) / cells.x;
  rdy = double(leftBottomCol.r - leftUpperCol.r) / cells.y;
  gdy = double(leftBottomCol.g - leftUpperCol.g) / cells.y;
  bdy = double(leftBottomCol.b - leftUpperCol.b) / cells.y;

  sf::RectangleShape rect(sf::Vector2f(getSize().x / cells.x, getSize().y / cells.y));
  for(int i = 0; i < cells.x; i++)
    for (int j = 0; j < cells.y; j++)
    {
      rect.setPosition(i * rect.getSize().x, j * rect.getSize().y);
      rect.setFillColor(sf::Color(leftUpperCol.r + int(i * rdx + j * rdy), 
                                  leftUpperCol.g + int(i * gdx + j * gdy), 
                                  leftUpperCol.b + int(i * bdx + j * bdy)));
      getRTexture().draw(rect);
    }
}

sf::Color ColorScheme::getColByCoordinate(const sf::Vector2f& point)
{
  double rdx, gdx, bdx, rdy, gdy, bdy;
  rdx = double(rightUpperCol.r - leftUpperCol.r) / cells.x;
  gdx = double(rightUpperCol.g - leftUpperCol.g) / cells.x;
  bdx = double(rightUpperCol.b - leftUpperCol.b) / cells.x;
  rdy = double(leftBottomCol.r - leftUpperCol.r) / cells.y;
  gdy = double(leftBottomCol.g - leftUpperCol.g) / cells.y;
  bdy = double(leftBottomCol.b - leftUpperCol.b) / cells.y;

  int i, j;

  i = int((point.x) / getSize().x * cells.x);
  j = int((getSize().y - point.y) / getSize().y * cells.y);

  return sf::Color(leftUpperCol.r + int(i * rdx + j * rdy),
                   leftUpperCol.g + int(i * gdx + j * gdy),
                   leftUpperCol.b + int(i * bdx + j * bdy));

}
