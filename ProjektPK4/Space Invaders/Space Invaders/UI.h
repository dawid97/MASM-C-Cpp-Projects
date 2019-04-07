#pragma once
#include<SFML/Graphics.hpp>
#include"Exceptions.h"


class UI
{
private:
	std::unique_ptr<sf::Font>font;
	sf::Text shieldText;
	sf::Text scoreText;
	sf::Text lifeText;
	int score;

	sf::Text shieldTextInitialization(sf::Vector2f position);
	void fontInitialization();
	void lifeTextInitialization();
	void scoreTextInitialization();
	void renderShieldText(sf::RenderWindow*window);
	std::vector<sf::Text>shieldsText;
	
	
public:
	UI();
	void removeShieldsText(size_t index);
	void render(sf::RenderWindow*window);
	void updateShieldLife(size_t index, int lifeScore,sf::Vector2f shieldPosition);
	void updateScore();
	void addScore(int enemyType);
	void removeShieldsText();
	void addShieldsText();
	~UI();
};

