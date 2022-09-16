#include "Utils.h"
using namespace std;


	vector<RectangleShape> Utils::genArray(int n, sf::RenderWindow* window)
	{
		// Store the window's dimensions
		sf::Vector2u windowSize = window->getSize();
		int width = windowSize.x;
		int height = windowSize.y;

		// Create a vector for all RectangleShapes to be stored in
		vector<RectangleShape> rects;
		rects.reserve(n);

		for(int i = 1; i <= n; i++)
		{
			RectangleShape rect(sf::Vector2f((float)width / n, (((float)height / n) * i)));
			rect.setFillColor(sf::Color(0, 0, 255, 200));
			rect.setOrigin(sf::Vector2f(0.0f, ((float)height / n) * i));
			rect.setPosition(sf::Vector2f(i + (((float)width / n) - 1) * (i - 1), (float)height));

			rect.value = i;
			rects.push_back(rect);
		}

		return rects;
	}

	void Utils::shuffleArray(std::vector<RectangleShape>& arr)
	{
		// Size of the array
		int sz = arr.size();

		for(int i = 0; i < sz; i++)
		{
			int index = i + rand() % (sz - i);

			sf::Vector2f firstPos = arr[i].getPosition();
			sf::Vector2f secondPos = arr[index].getPosition();

			iter_swap(arr.begin() + i, arr.begin() + index);

			arr[i].setPosition(firstPos);
			arr[index].setPosition(secondPos);
		}

	}

