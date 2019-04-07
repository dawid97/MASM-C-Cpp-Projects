#include "Bullet.h"



Bullet::Bullet(sf::Vector2f position)
{
	this->bulletTex=std::shared_ptr<sf::Texture>(new sf::Texture);
	if (!bulletTex->loadFromFile("Textures/bullet.png"))
		throw LoadingError("Bullet loading error");

	bullet.setTexture(*bulletTex);
	bullet.setScale(sf::Vector2f(0.1f, 0.2f));
	bullet.setColor(sf::Color::Green);
	bullet.setOrigin(bullet.getLocalBounds().width / 2.f, 0.f);
	bullet.setPosition(position);
}


Bullet::~Bullet()
{

}

void Bullet::move(sf::Vector2f xy)
{
	this->bullet.move(xy);
}

sf::Vector2f Bullet::getPosition()
{
	return this->bullet.getPosition();
}


void Bullet::render(sf::RenderWindow*window)
{
	window->draw(this->bullet);
}

bool Bullet::isIntersects(sf::FloatRect object)
{
	return this->bullet.getGlobalBounds().intersects(object);
}