#include "Block.h"



Block::Block(sf::Vector2f size,sf::Color color,float outlineThickness,sf::Color outlineColor,sf::Vector2f position,std::string name,sf::Vector2f textPosition,sf::Color textColor)
{
	try
	{
		this->fontInitialization("Fonts/SpaceInvader.ttf");
	}
	catch (LoadingError error)
	{
		system("pause");
		exit(EXIT_FAILURE);
	}

	this->blockInitialization(size,color,outlineThickness,outlineColor,position);
	this->textInitialization(name, textPosition,textColor);
}

void Block::textInitialization(std::string name, sf::Vector2f textPosition,sf::Color textColor)
{
	this->text = std::shared_ptr<sf::Text>(new sf::Text());

	this->text->setFont(*this->font);
	this->text->setCharacterSize(17);
	this->text->setFillColor(textColor);
	this->text->setString(name);
	sf::FloatRect boundsText = this->text->getLocalBounds();
	sf::Vector2f centerText(boundsText.left + boundsText.width / 2.f, boundsText.top + boundsText.height / 2.f);
	this->text->setOrigin(centerText);
	this->text->setPosition(textPosition);
}

void Block::blockInitialization(sf::Vector2f size, sf::Color color, float outlineThickness, sf::Color outlineColor, sf::Vector2f position)
{
	this->block.setSize(size);
	this->block.setFillColor(color);
	this->block.setOutlineThickness(outlineThickness);
	this->block.setOutlineColor(outlineColor);
	this->block.setOrigin(this->block.getGlobalBounds().width / 2.f, this->block.getGlobalBounds().height / 2.f);
	this->block.setPosition(position);
}

void Block::fontInitialization(std::string fileNameFont)
{
	this->font = std::shared_ptr<sf::Font>(new sf::Font());

	if (!this->font->loadFromFile(fileNameFont))
		throw LoadingError("Font loading error!");
}

void Block::render(sf::RenderWindow*window)
{
	window->draw(this->block);
	window->draw(*this->text);
}


Block::~Block()
{

}

