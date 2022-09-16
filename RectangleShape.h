#pragma once
#include <SFML/Graphics.hpp>
class RectangleShape : public sf::RectangleShape
{
public:
	using sf::RectangleShape::RectangleShape;

	int value;
};


