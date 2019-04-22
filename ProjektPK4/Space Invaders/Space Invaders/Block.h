#pragma once
#include<SFML/Graphics.hpp>
#include"Exceptions.h"

class Block
{
private:
	sf::RectangleShape block;
	std::shared_ptr<sf::Font> font;
	std::shared_ptr<sf::Text> text;

	void fontInitialization(std::string fileNameFont);
	void blockInitialization(sf::Vector2f size, sf::Color color, float outlineThickness, sf::Color outlineColor, sf::Vector2f position);
	void textInitialization(std::string name, sf::Vector2f position, sf::Color textColor);
public:
	Block(sf::Vector2f size, sf::Color color, float outlineThickness, sf::Color outlineColor, sf::Vector2f position,std::string name,sf::Vector2f textPosition, sf::Color textColor);
	void render(sf::RenderWindow*window);
	~Block();
};

