#include "Shield.h"



Shield::Shield(int hp,sf::Vector2f position,sf::Vector2f scale,std::string shieldTex)
{
	this->hp = hp;

	try
	{
		this->shieldTex = std::shared_ptr<sf::Texture>(new sf::Texture);

		if (!this->shieldTex->loadFromFile(shieldTex))
			throw LoadingError("shield texture loading error");
	}
	catch (LoadingError error)
	{
		system("pause");
		exit(EXIT_FAILURE);
	}
	
	shield.setTexture(*this->shieldTex);
	shield.setScale(sf::Vector2f(scale));
	shield.setOrigin(shield.getLocalBounds().width / 2.f, shield.getLocalBounds().height / 2.f);
	shield.setPosition(position);
}

void Shield::removeHp()
{
	this->hp--;
}

int Shield::getHp()
{
	return this->hp;
}

void Shield::render(sf::RenderWindow*window)
{
	window->draw(this->shield);
}

sf::FloatRect Shield::getGlobalBounds()
{
	return this->shield.getGlobalBounds();
}

sf::Vector2f Shield::getPosition()
{
	return this->shield.getPosition();
}