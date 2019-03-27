#include "Live.h"
#include "Exceptions.h"



Live::Live(sf::Vector2f position)
{
	this->liveTex = std::shared_ptr<sf::Texture>(new sf::Texture);

	if (!liveTex->loadFromFile("Textures/ship.png"))
		throw LoadingError("live loading error");

	live.setTexture(*liveTex);
	live.setScale(sf::Vector2f(0.04f, 0.04f));
	live.setColor(sf::Color::Green);
	live.setOrigin(live.getLocalBounds().width / 2.f, live.getLocalBounds().height / 2.f);
	live.setPosition(position);
	
}


Live::~Live()
{

}

void Live::render(sf::RenderWindow*window)
{
	window->draw(this->live);
}
