#include "Shield.h"



Shield::Shield(sf::Vector2f position)
{
	this->hp = 10;

	this->shieldTex = std::shared_ptr<sf::Texture>(new sf::Texture);

	if(!this->shieldTex->loadFromFile("Textures/shield9.png"))
	throw LoadingError("shield loading error");

	shield.setTexture(*shieldTex);
	shield.setScale(sf::Vector2f(0.35f, 0.35f));
	shield.setOrigin(shield.getLocalBounds().width / 2.f, shield.getLocalBounds().height / 2.f);
	shield.setPosition(position);
}

void Shield::removeLife()
{
	this->hp--;
}

int Shield::getHp()
{
	return this->hp;
}


Shield::~Shield()
{

}


sf::Vector2f Shield::getPosition()
{
	return this->shield.getPosition();
}



void Shield::render(sf::RenderWindow*window)
{
	window->draw(this->shield);
}

sf::FloatRect Shield::getGlobalBounds()
{
	return this->shield.getGlobalBounds();
}

