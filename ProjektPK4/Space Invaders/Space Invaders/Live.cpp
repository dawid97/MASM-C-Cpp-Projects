#include "Live.h"
#include "Exceptions.h"



Live::Live(sf::Vector2f position,sf::Vector2f scale,sf::Color color,std::string liveTex)
{

	try
	{
		this->lifeTex = std::shared_ptr<sf::Texture>(new sf::Texture);

		if (!lifeTex->loadFromFile(liveTex))
			throw LoadingError("live texture loading error");
	}
	catch (LoadingError error)
	{
		system("pause");
		exit(EXIT_FAILURE);
	}
	
	live.setTexture(*lifeTex);
	live.setScale(sf::Vector2f(scale));
	live.setColor(color);
	live.setOrigin(live.getLocalBounds().width / 2.f, live.getLocalBounds().height / 2.f);
	live.setPosition(position);
}

void Live::render(sf::RenderWindow*window)
{
	window->draw(this->live);
}
