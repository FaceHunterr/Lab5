#include "MyPaint.h"

MyPaint::MyPaint(const std::string& title, int width, int height) :
  window(sf::VideoMode(width, height), title)
{
  backGround = new Layer(sf::Vector2f(0, 0), sf::Vector2f(window.getSize()), sf::Color(120, 130, 160), false);
  drawingSpace = new Layer(sf::Vector2f(float(window.getSize().x * 0.03), float(window.getSize().y * 0.15)), 
    sf::Vector2f(float(window.getSize().x * 0.94), float(window.getSize().y * 0.82)), sf::Color(225, 225, 225));
  mainPanel = new Panel(sf::Vector2f(float(window.getSize().x * 0.03), float(window.getSize().y * 0.03)),
    sf::Vector2f(float(window.getSize().x * 0.94), float(window.getSize().y * 0.1)), sf::Color(200, 200, 200), this);
  
  mainPanel->addButton(sf::Vector2f(float(window.getSize().y * 0.01), float(window.getSize().y * 0.01)), sf::Vector2f(float(window.getSize().y * 0.08), float(window.getSize().y * 0.08)), "Images\\pencil.png", Button::butType::PENCIL);
  mainPanel->addButton(sf::Vector2f(float(window.getSize().y * 0.12), float(window.getSize().y * 0.01)), sf::Vector2f(float(window.getSize().y * 0.08), float(window.getSize().y * 0.08)), "Images\\eraser.png", Button::butType::ERRASER);
  mainPanel->addButton(sf::Vector2f(float(window.getSize().y * 0.21), float(window.getSize().y * 0.01)), sf::Vector2f(float(window.getSize().y * 0.035), float(window.getSize().y * 0.035)), "Images\\plus.png", Button::butType::THICK_UP);
  mainPanel->addButton(sf::Vector2f(float(window.getSize().y * 0.21), float(window.getSize().y * 0.055)), sf::Vector2f(float(window.getSize().y * 0.035), float(window.getSize().y * 0.035)), "Images\\minus.png", Button::butType::THICK_DOWN);
  mainPanel->addButton(sf::Vector2f(float(window.getSize().y * 0.26), float(window.getSize().y * 0.01)), sf::Vector2f(float(window.getSize().y * 0.08), float(window.getSize().y * 0.08)), "Images\\clear.png", Button::butType::CLEAR_ALL);
  mainPanel->addButton(sf::Vector2f(float(window.getSize().y * 0.35), float(window.getSize().y * 0.01)), sf::Vector2f(float(window.getSize().y * 0.08), float(window.getSize().y * 0.08)), "Images\\color_panel.png", Button::butType::COLOR_PANEL);
  mainPanel->addButton(sf::Vector2f(float(window.getSize().y * 0.50), float(window.getSize().y * 0.01)), sf::Vector2f(float(window.getSize().y * 0.035), float(window.getSize().y * 0.035)), "Images\\circle.png", Button::butType::FIGURE_ELLIPSE);
  mainPanel->addButton(sf::Vector2f(float(window.getSize().y * 0.50), float(window.getSize().y * 0.055)), sf::Vector2f(float(window.getSize().y * 0.035), float(window.getSize().y * 0.035)), "Images\\empty_circle.png", Button::butType::FIGURE_EMPTY_ELLIPSE);
  pencil = new Pencil(sf::Vector2f(sf::Mouse::getPosition(window)), sf::Vector2f(20, 20), "Images\\pencil.png");
  eraser = new Eraser(sf::Vector2f(sf::Mouse::getPosition(window)), sf::Vector2f(20, 20), "Images\\eraser.png");
  colorPanel = new ColorPanel(sf::Vector2f(float(window.getSize().x * 0.57), float(window.getSize().y * 0.03)),
    sf::Vector2f(float(window.getSize().x * 0.40), float(window.getSize().y * 0.35)), sf::Color(200, 200, 255), this);
  figure = new Figure(pencil);
  figureLayer = new FigureLayer(drawingSpace->getPosition(), drawingSpace->getSize());
  curBrush = pencil;
  curLayer = drawingSpace;
  
}

MyPaint::~MyPaint()
{
  delete backGround;
  delete drawingSpace;
  delete pencil;
  delete eraser;
  delete mainPanel;
  delete colorPanel;
  delete figure;
  delete figureLayer;
}

void MyPaint::go()
{
  while (window.isOpen())
  {
    while (window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
        window.close();
      
      /*if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space)
      {

        if (curBrush == pencil)
        {
          curBrush = eraser;
        }
        else
          curBrush = pencil;
      }*/
    }
    update();
    draw();
  }
}

void MyPaint::update()
{
  setCurLayer();
  mouseClick();
  //figureLayer->update();
  backGround->update();
  drawingSpace->update();
  mainPanel->update();
  curBrush->update(window, curLayer);
}

void MyPaint::draw()
{
  window.clear();
  backGround->draw(window);
  drawingSpace->draw(window);
  figureLayer->draw(window);
  if (figureLayer->isReadyToDraw())
  {
    //std::cout << "90";
    figureLayer->draw(*drawingSpace);
    figureLayer->setReadyToDraw(false);
    figureLayer->Clear();
  }
  

  mainPanel->draw(window);
  colorPanel->draw(window);
  curBrush->draw(window);
  window.display();
}

void MyPaint::mouseClick()
{
    curLayer->click(*curBrush);
}

void MyPaint::setCurLayer()
{
  if (colorPanel->isActive() && colorPanel->isCrossed(*curBrush))
  {
    curLayer = colorPanel;
    return;
  }
  if (figureLayer->isActive() && figureLayer->isCrossed(*curBrush))
  {
    curLayer = figureLayer;
    return;
  }
  if (drawingSpace->isCrossed(*curBrush))
  {
    curLayer = drawingSpace;
    return;
  }
  if (mainPanel->isCrossed(*curBrush))
  {
    curLayer = mainPanel;
    return;
  }
  if (backGround->isCrossed(*curBrush))
  {
    curLayer = backGround;
    return;
  }

  
}
