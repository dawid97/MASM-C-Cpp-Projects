#pragma once
#include<SFML/Graphics.hpp>
#include "Exceptions.h"

class Player
{
private:
	std::unique_ptr<sf::Sprite>player;
	std::unique_ptr<sf::Texture>playerTex;
	int maxSpeed;
	
public:
	//Ship(Score* score, EntityManager* manager, float x, float y);
	//void Update(sf::RenderWindow* window);
	//void Collision(Entity* entity);

	Player(sf::RenderWindow*window);
	void Render(sf::RenderWindow*window);
	void Update(sf::RenderWindow*window);
	~Player();
};

