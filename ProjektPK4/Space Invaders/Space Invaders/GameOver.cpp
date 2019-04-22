#include "GameOver.h"


GameOver::GameOver(sf::RenderWindow*window)
{
	this->selectedItemIndex = 0;
	this->maxNumberOfItems = 3;
	this->downKey = false;
	this->upKey = false;

	//main block
	this->blocks.push_back(Block(sf::Vector2f(window->getSize().x / 4.f, window->getSize().y / 2.5f),
		sf::Color(180, 180, 180, 70), 2.f, sf::Color::Green, sf::Vector2f(window->getSize().x / 2.f, window->getSize().y / 2.f),"GAME OVER",sf::Vector2f(400.f,210.f),sf::Color::Red));

	//buttons
	this->buttons.push_back(Button(sf::Color::Black,2.f,sf::Color::Green,sf::Vector2f(170.f,50.f),sf::Vector2f(400.f,260.f),"MAIN MENU",17, sf::Color(0, 191, 255)));
	this->buttons.push_back(Button(sf::Color::Black, 2.f, sf::Color::Green, sf::Vector2f(170.f, 50.f), sf::Vector2f(400.f, 330.f),"SUBMIT SCORE",17,sf::Color::White));
	this->buttons.push_back(Button(sf::Color::Black, 2.f, sf::Color::Green, sf::Vector2f(170.f, 50.f), sf::Vector2f(400.f, 400.f),"EXIT GAME",17,sf::Color::White));
}

void GameOver::render(sf::RenderWindow*window)
{
	for (size_t i = 0; i < this->blocks.size(); i++)
		this->blocks[i].render(window);

	for (size_t i = 0; i < this->buttons.size(); i++)
		this->buttons[i].render(window);
}

void GameOver::moveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		buttons[selectedItemIndex].setTextColor(sf::Color::White);
		selectedItemIndex--;
		buttons[selectedItemIndex].setTextColor(sf::Color(0, 191, 255));
	}
}

void GameOver::moveDown()
{
	if (selectedItemIndex + 1 < maxNumberOfItems)
	{
		buttons[selectedItemIndex].setTextColor(sf::Color::White);
		selectedItemIndex++;
		buttons[selectedItemIndex].setTextColor(sf::Color(0, 191, 255));
	}
}

int GameOver::update(sf::RenderWindow* window)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) && !this->upKey)
	{
		this->moveUp();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) && !this->downKey)
	{
		this->moveDown();
	}

	this->upKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up);
	this->downKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter) && buttons[0].getTextColor() == sf::Color(0, 191, 255))
		return 0;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter) && buttons[1].getTextColor() == sf::Color(0, 191, 255))
		return 1;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter) && buttons[2].getTextColor() == sf::Color(0, 191, 255))
		return 2;

	return -1;
}


