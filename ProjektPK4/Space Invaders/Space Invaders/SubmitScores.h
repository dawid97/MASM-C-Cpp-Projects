#pragma once
#include<SFML/Graphics.hpp>
#include<vector>
#include"Exceptions.h"

class SubmitScores
{
	std::unique_ptr<sf::Font>font;
	std::unique_ptr<sf::Sprite>background;
	std::unique_ptr<sf::Texture>backgroundTex;
	std::unique_ptr<sf::Text>nameTex;
	std::unique_ptr<sf::Text>name;
	std::vector<sf::Text> texts;
	std::vector<sf::RectangleShape> blocks;
	//bool enterKey;
	int selectedItemIndex;
	int maxNumberOfItems;
	bool upKey, downKey, keyPressed;
	void moveUp();
	void moveDown();


public:
	SubmitScores(sf::RenderWindow* window);
	void Update(sf::RenderWindow* window);
	void Render(sf::RenderWindow* window);
	void updateUserName(sf::RenderWindow*window,sf::Event*event);
};

