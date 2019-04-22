#pragma once
#include<SFML/Graphics.hpp>
#include"Exceptions.h"

class Button
{
private:
	std::shared_ptr<sf::Font> font;
	std::shared_ptr<sf::Text> text;
	sf::RectangleShape block;


	void fontInitialization(std::string fileNameFont);
	void textInitialization(std::string name, sf::Vector2f position, unsigned int fontSize, sf::Color fontFillColor);
	void blockInitialization(sf::Color fillColor, float outlineThickness, sf::Color outlineColor, sf::Vector2f size, sf::Vector2f position);
public:
	Button(sf::Color fillColor, float outlineThickness, sf::Color outlineColor, sf::Vector2f size, sf::Vector2f position,std::string name, unsigned int fontSize, sf::Color fontFillColor);
	void render(sf::RenderWindow*window);
	void setTextColor(sf::Color color);
	sf::Color getTextColor();
	void setString(std::string name);
	void setFillColor(sf::Color color);
	sf::Color getFillColor();
	sf::Vector2f getPosition();
	~Button();
};

