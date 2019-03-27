#pragma once
#include<sfml/Graphics.hpp>
#include"Exceptions.h"

class Shield
{
private:
	std::shared_ptr<sf::Image> shieldImage;
	std::shared_ptr<sf::Sprite> shield;
	std::shared_ptr<sf::Texture> shieldTex;

	//std::shared_ptr<sf::Texture>shieldTex;
public:
	void render(sf::RenderWindow*window);
	Shield(sf::Vector2f position);
	~Shield();
};

