#pragma once
#include<SFML/Graphics.hpp>
#include"Block.h"
#include"Button.h"

class GameOver
{
protected:
	std::vector<Block> blocks;
	std::vector<Button> buttons;
	int selectedItemIndex;
	int maxNumberOfItems;
	bool upKey, downKey;
	void moveUp();
	void moveDown();

public:
	GameOver(sf::RenderWindow*window);
	void render(sf::RenderWindow*window);
	int update(sf::RenderWindow* window);
};

