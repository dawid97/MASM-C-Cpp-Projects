#include "Bullet.h"



Bullet::Bullet(float speed,sf::Vector2f position,sf::Vector2f scale,std::string fileNameTex)
{
	this->speed = speed;

	try
	{
		//bulletTexture
		this->bulletTex = std::shared_ptr<sf::Texture>(new sf::Texture);

		if (!bulletTex->loadFromFile(fileNameTex))
			throw LoadingError("Bullet texture loading error");
	}
	catch (LoadingError error)
	{
		system("pause");
		exit(EXIT_FAILURE);
	}

	bullet.setScale(scale);
	bullet.setTexture(*bulletTex);
	bullet.setOrigin(bullet.getLocalBounds().width / 2.f,bullet.getLocalBounds().height/2.f);
	bullet.setPosition(position);
}

void Bullet::render(sf::RenderWindow*window)
{
	window->draw(this->bullet);
}

void Bullet::move(sf::Vector2f position)
{
	this->bullet.move(position);
}

bool Bullet::isIntersects(sf::FloatRect object)
{
	return this->bullet.getGlobalBounds().intersects(object);
}
	
sf::Vector2f Bullet::getPosition()
{
	return this->bullet.getPosition();
}

float Bullet::getSpeed()
{
	return this->speed;
}

sf::FloatRect Bullet::getGlobalBounds()
{
	return this->bullet.getGlobalBounds();
}








