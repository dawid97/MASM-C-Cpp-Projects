#include "Button.h"



Button::Button(sf::Color fillColor,float outlineThickness,sf::Color outlineColor,sf::Vector2f size,sf::Vector2f position,std::string name, unsigned int fontSize, sf::Color fontFillColor)
{
	this->blockInitialization(fillColor, outlineThickness, outlineColor, size, position);

	try
	{
		this->fontInitialization("Fonts/SpaceInvader.ttf");
	}
	catch (LoadingError error)
	{
		system("pause");
		exit(EXIT_FAILURE);
	}

	this->textInitialization(name, position,fontSize,fontFillColor);
}

void Button::blockInitialization(sf::Color fillColor, float outlineThickness, sf::Color outlineColor, sf::Vector2f size, sf::Vector2f position)
{
	this->block.setSize(size);
	this->block.setOutlineThickness(outlineThickness);
	this->block.setOutlineColor(outlineColor);
	this->block.setFillColor(fillColor);
	this->block.setOrigin(this->block.getGlobalBounds().width / 2.f, this->block.getGlobalBounds().height / 2.f);
	this->block.setPosition(position);
}

void Button::setTextColor(sf::Color color)
{
	this->text->setFillColor(color);
}

sf::Color Button::getTextColor()
{
	return this->text->getFillColor();
}

void Button::setString(std::string name)
{
	this->text->setString(name);
	sf::FloatRect boundsText = this->text->getLocalBounds();
	sf::Vector2f centerText(boundsText.left + boundsText.width / 2.f, boundsText.top + boundsText.height / 2.f);
	this->text->setOrigin(centerText);
}

void Button::setFillColor(sf::Color color)
{
	this->block.setFillColor(color);
}

sf::Color Button::getFillColor()
{
	return this->block.getFillColor();
}

sf::Vector2f Button::getPosition()
{
	return this->block.getPosition();
}

void Button::textInitialization(std::string name,sf::Vector2f position,unsigned int fontSize,sf::Color fontFillColor)
{
	this->text = std::shared_ptr<sf::Text>(new sf::Text());

	this->text->setFont(*this->font);
	this->text->setCharacterSize(fontSize);
	this->text->setFillColor(fontFillColor);
	this->text->setString(name);
	sf::FloatRect boundsText = this->text->getLocalBounds();
	sf::Vector2f centerText(boundsText.left + boundsText.width / 2.f, boundsText.top + boundsText.height / 2.f);
	this->text->setOrigin(centerText);
	this->text->setPosition(position);
}

void Button::fontInitialization(std::string fileNameFont)
{
	this->font = std::shared_ptr<sf::Font>(new sf::Font());

	if (!this->font->loadFromFile(fileNameFont))
		throw LoadingError("Font loading error!");
}

void Button::render(sf::RenderWindow*window)
{
	window->draw(this->block);
	window->draw(*this->text);
}


Button::~Button()
{

}
