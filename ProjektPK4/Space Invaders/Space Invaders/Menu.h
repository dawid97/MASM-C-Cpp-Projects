#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>

constexpr int MaxNumberOfItems = 3;

class Menu
{
public:
	Menu(int width,int height);
	~Menu();

	void draw(sf::RenderWindow &window);
	void moveUp();
	void moveDown();
	int GetPressedItem() { return selectedItemIndex; }

private:
	int selectedItemIndex;
	sf::Font font;
	sf::Text menu[MaxNumberOfItems];
};

