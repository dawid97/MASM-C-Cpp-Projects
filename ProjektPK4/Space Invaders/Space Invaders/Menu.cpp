#include "Menu.h"




Menu::Menu(int width,int height)
{
	if (!font.loadFromFile("Fonts/space_invaders.ttf"))  //uzycie wyjatkow
		std::cout << "blad wczytywania czcionki" << std::endl;

	this->menu[0].setFont(font);
	this->menu[0].setFillColor(sf::Color::Red);
	this->menu[0].setString("Play");
	this->menu[0].setPosition(sf::Vector2f(float(width / 2.f), float(height / (MaxNumberOfItems + 1)*1)));

	this->menu[1].setFont(font);
	this->menu[1].setFillColor(sf::Color::White);
	this->menu[1].setString("Options");
	this->menu[1].setPosition(sf::Vector2f(float(width / 2.f), float(height / (MaxNumberOfItems + 1) * 2)));

	this->menu[2].setFont(font);
	this->menu[2].setFillColor(sf::Color::White);
	this->menu[2].setString("Exit");
	this->menu[2].setPosition(sf::Vector2f(float(width / 2.f), float(height / (MaxNumberOfItems + 1) * 3)));

	this->selectedItemIndex = 0;
}


Menu::~Menu()
{

}

void Menu::draw(sf::RenderWindow &window)
{
	for (int i = 0; i < MaxNumberOfItems; i++)
	{
		window.draw(menu[i]);
	}
}

void Menu::moveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}

void Menu::moveDown()
{
	if (selectedItemIndex + 1 < MaxNumberOfItems)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}
