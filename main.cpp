#include <SFML/Graphics.hpp>
#include <vector>
#include <stdio.h>
#include <iostream>
#include "RectangleShape.h"
#include "Utils.h"
#include "Algorithms.h"

// All sorting algorithms stored in an enum
using namespace std;

enum SortType
{
	BUBBLE_SORT,
	INSERTION_SORT,
	SELECTION_SORT
};

int main()
{
	int n, windowWidth =1020, windowHeight = 720, sortType,delay;
	bool sorted = false;

	// Ask the user for the desired number of bars
	cout << "Enter the number of items that need to be sorted.\n";
	cin >> n;

	// Ask the user for the desired delay between comparisons
	cout << "Enter the delay between comparisons and draw calls, in milliseconds.\n";
	cin >> delay;

	// Ask the user for which algorithm to use
	cout << "Enter the algorithm you would like to use.\n";
	cout << "(BubbleSort = 0 | InsertionSort = 1 | SelectionSort = 2)\n";
	cin >> sortType;

	// Create window
	sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Sorting");
	window.setFramerateLimit(60);

	vector<RectangleShape> bars = Utils::genArray(n, &window);
	Utils::shuffleArray(bars);

	// Render loop
	while(window.isOpen())
	{
		sf::Event e;
		while(window.pollEvent(e))
		{
			if(e.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		if(!sorted)
		{
			switch(sortType)
			{
			case BUBBLE_SORT:
				BubbleSort::runSort(bars, &window, delay);
				sorted = true;
				break;

			case INSERTION_SORT:
				InsertionSort::runSort(bars, &window, delay);
				sorted = true;
				break;

			case SELECTION_SORT:
				SelectionSort::runSort(bars, &window, delay);
				sorted = true;
				break;

			default:
				std::cout << "Invalid value for sort algorithm type entered!\n";
				return 0;
			}
		} else
		{
			window.clear(sf::Color(255, 255, 255, 255));
			for(int i = 0; i < n; i++)
			{
				window.draw(bars[i]);
			}
			window.display();
			window.close();

		}

	}
	return 0;
}
