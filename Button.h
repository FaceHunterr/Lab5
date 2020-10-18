#pragma once
#include "Object.h"
class Button : public Object
{

public:
	enum class butType
	{
		PENCIL,
		ERRASER,
		THICK_UP,
		THICK_DOWN,
		CLEAR_ALL,
		ACCEPT,
		CANCEL,
		COLOR_PANEL,
		FIGURE_ELLIPSE,
		FIGURE_EMPTY_ELLIPSE,
		
	};
private:
	sf::Texture texture;
	butType type;
	sf::RectangleShape frame;
public:
	Button(const sf::Vector2f& pos, const sf::Vector2f& s, const std::string& fileName, butType t);
	void setType(const butType& t) { type = t; }
	butType getType(void) { return type; }
	void draw(sf::RenderWindow& win);


};

