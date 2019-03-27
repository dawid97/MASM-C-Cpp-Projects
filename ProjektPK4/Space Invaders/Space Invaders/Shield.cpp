#include "Shield.h"



Shield::Shield(sf::Vector2f position)
{
	this->shieldImage = std::shared_ptr<sf::Image>(new sf::Image);

	if (!this->shieldImage->loadFromFile("Textures/shield9.png"))
		throw LoadingError("shield loading error");

	//this->shieldTex = std::shared_ptr<sf::Texture>(new sf::Texture);

	//if (!shieldTex->loadFromFile("Textures/shield.png"))
		//throw LoadingError("shield loading error");*/
	this->shieldTex = std::shared_ptr<sf::Texture>(new sf::Texture);
	this->shieldTex->loadFromImage(*this->shieldImage);
	//this->shieldTex.loadFromImage(shieldImage);

	this->shield = std::shared_ptr<sf::Sprite>(new sf::Sprite);
	shield->setTexture(*shieldTex);
	shield->setScale(sf::Vector2f(0.5f, 0.5f));
	//shield.setColor(sf::Color::Green);
	shield->setOrigin(shield->getLocalBounds().width / 2.f, shield->getLocalBounds().height / 2.f);
	shield->setPosition(position);
}


Shield::~Shield()
{

}

void Shield::render(sf::RenderWindow*window)
{
	window->draw(*this->shield);
}
