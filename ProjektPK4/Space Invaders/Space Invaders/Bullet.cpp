#include "Bullet.h"



Bullet::Bullet(sf::Vector2f position)
{

	if (!bulletTex.loadFromFile("Textures/bullet.png"))
		throw LoadingError("Bullet loading error");

	bullet.setTexture(bulletTex);
	bullet.setScale(sf::Vector2f(0.8f, 1.f));
	bullet.setOrigin(bullet.getLocalBounds().width / 2.f, bullet.getLocalBounds().height / 2.f);
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