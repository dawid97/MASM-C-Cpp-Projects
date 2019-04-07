#include "Life.h"
#include "Exceptions.h"



Life::Life(sf::Vector2f position)
{
	this->lifeTex = std::shared_ptr<sf::Texture>(new sf::Texture);

	if (!lifeTex->loadFromFile("Textures/ship.png"))
		throw LoadingError("live loading error");

	life.setTexture(*lifeTex);
	life.setScale(sf::Vector2f(0.03f, 0.03f));
	life.setColor(sf::Color::Green);
	life.setOrigin(life.getLocalBounds().width / 2.f, life.getLocalBounds().height / 2.f);
	life.setPosition(position);
	
}


Life::~Life()
{

}


void Life::render(sf::RenderWindow*window)
{
	window->draw(this->life);
}
