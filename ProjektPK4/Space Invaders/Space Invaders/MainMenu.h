#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
#include<vector>
#include"Exceptions.h"

class MainMenu
{
private:
	std::unique_ptr<sf::Font>font;
	std::unique_ptr<sf::Text>chooseActionText;
	std::unique_ptr<sf::Text>title;
	std::unique_ptr<sf::Sprite>background;
	std::unique_ptr<sf::Texture>backgroundTex;
	std::vector<sf::Text> texts;
	std::vector<sf::RectangleShape> blocks;
	//bool enterKey;
	int selectedItemIndex;
	int maxNumberOfItems;
	bool upKey, downKey;
	void moveUp();
	void moveDown();


public:
	MainMenu(sf::RenderWindow* window);
	void Update(sf::RenderWindow* window);
	void Render(sf::RenderWindow* window);
};



