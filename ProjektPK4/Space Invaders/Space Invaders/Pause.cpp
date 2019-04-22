#include "Pause.h"



Pause::Pause(sf::RenderWindow*window):GameOver(window)
{
	this->blocks.clear();
	this->blocks.push_back(Block(sf::Vector2f(window->getSize().x / 4.f, window->getSize().y / 2.5f),
		sf::Color(180, 180, 180, 70), 2.f, sf::Color::Green, sf::Vector2f(window->getSize().x / 2.f, window->getSize().y / 2.f), "PAUSE", sf::Vector2f(400.f, 210.f), sf::Color::Red));

	this->buttons[0].setString("RESUME");
	this->buttons[1].setString("MAIN MENU");
	this->buttons[2].setString("EXIT GAME");
}


Pause::~Pause()
{

}
