#pragma once
#include <vector>
#include "RectangleShape.h"
#include <chrono>
#include <thread>
using namespace std;

namespace BubbleSort
{
	void runSort(vector<RectangleShape>& arr, sf::RenderWindow* window, int delay)
	{
		int n = arr.size();
		for(int i = 0; i < n - 1; i++)
		for(int j = 0; j < n - 1 - i; j++)
		{
			if(arr[j].value > arr[j + 1].value)
			{
				sf::Vector2f firstPos = arr[j].getPosition();
				sf::Vector2f secondPos = arr[j + 1].getPosition();

				iter_swap(arr.begin() + j, arr.begin() + j + 1);

				arr[j].setPosition(firstPos);
				arr[j + 1].setPosition(secondPos);

				arr[j + 1].setFillColor(sf::Color(255, 0, 0, 255));

				window->clear(sf::Color(255, 255, 255, 255));

				for(unsigned int k = 0; k < arr.size(); k++)
				{
					window->draw(arr[k]);
				}

				window->display();

				arr[j + 1].setFillColor(sf::Color(0, 0, 255, 255));

				this_thread::sleep_for(chrono::milliseconds(delay));
			}
		}


		// Clear unwanted rectangles after the sorting is finished
		window->clear(sf::Color(255, 255, 255, 255));
		for(int i = 0; i < n; i++)
		{
			arr[i].setFillColor(sf::Color(46, 139, 87, 255));
			window->draw(arr[i]);
		}
		window->display();
	}
}

namespace InsertionSort
{
	void runSort(vector<RectangleShape>& arr, sf::RenderWindow* window, int delay)
	{
		int n = arr.size();
		for(int i = 0; i < n; i++)
		for(int j = i; j > 0; j--)
		{
			if(arr[j - 1].value > arr[j].value)
			{
				sf::Vector2f firstPos = arr[j - 1].getPosition();
				sf::Vector2f secondPos = arr[j].getPosition();

				iter_swap(arr.begin() + j, arr.begin() + j - 1);

				arr[j - 1].setPosition(firstPos);
				arr[j].setPosition(secondPos);

				arr[j - 1].setFillColor(sf::Color(255, 0, 0, 255));

				window->clear(sf::Color(255, 255, 255, 255));
				for(unsigned int k = 0; k < arr.size(); k++)
				{
					window->draw(arr[k]);
				}
				window->display();

				arr[j - 1].setFillColor(sf::Color(0, 0, 255, 255));

				this_thread::sleep_for(chrono::microseconds(delay));
			}
		}

		// Clear unwanted rectangles after the sorting is finished
		window->clear(sf::Color(255, 255, 255, 255));
		for(int i = 0; i < n; i++)
		{
			arr[i].setFillColor(sf::Color(46, 139, 87, 255));
			window->draw(arr[i]);
		}
		window->display();
	}
}

namespace SelectionSort
{
	void runSort(vector<RectangleShape>& arr, sf::RenderWindow* window, int delay)
	{
		int n = arr.size();

		for(int i = 0; i < n - 1; i++)
		{
			int min = i;

			for(int j = i + 1; j < n; j++)
				if(arr[j].value < arr[min].value)
					min = j;

			if(min != i)
			{
				sf::Vector2f firstPos = arr[i].getPosition();
				sf::Vector2f secondPos = arr[min].getPosition();

				iter_swap(arr.begin() + min, arr.begin() + i);

				arr[i].setPosition(firstPos);
				arr[min].setPosition(secondPos);

				arr[i].setFillColor(sf::Color(255, 0, 0, 255));

				window->clear(sf::Color(255, 255, 255, 255));
				for(unsigned int k = 0; k < arr.size(); k++)
				{
					window->draw(arr[k]);
				}
				window->display();

				arr[i].setFillColor(sf::Color(0, 0, 255, 255));

				this_thread::sleep_for(chrono::microseconds(delay));
			}
		}
		window->clear(sf::Color(255, 255, 255, 255));
		for(int i = 0; i < n; i++)
		{
			arr[i].setFillColor(sf::Color(46, 139, 87, 255));
			window->draw(arr[i]);
		}
		window->display();
	}
}

