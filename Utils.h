#pragma once
#include "RectangleShape.h"
#include <SFML/Graphics.hpp>
#include <vector>

namespace Utils
{
	std::vector<RectangleShape> genArray(int n, sf::RenderWindow* window);

	void shuffleArray(std::vector<RectangleShape>& arr);
}
