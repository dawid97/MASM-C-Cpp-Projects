#pragma once
#include<SFML/Graphics.hpp>
#include"Exceptions.h"
#include"Player.h"
#include"Live.h"

class UI
{
private:
	std::unique_ptr<sf::Font>font;
	sf::Text shieldText;
	sf::Text scoreText;


	sf::Text liveText;
	std::vector<Live> lives;
	std::vector<sf::Text>shieldsTexts;


	sf::Text createShieldText(sf::Vector2f position,sf::Color color,std::string inscription,unsigned int size);
	void livesInitialization();
	void lifeTextInitialization(sf::Vector2f position, sf::Color color, std::string inscription, unsigned int size);
	void fontInitialization(std::string fileNameFon);
	void scoreTextInitialization(sf::Vector2f position, sf::Color color, unsigned int size, int score);
	void renderShieldsTexts(sf::RenderWindow*window);
	void renderLifes(sf::RenderWindow*window);

	
public:
	UI();
	void removeLive();
	void render(sf::RenderWindow*window);
	void updateShieldLife(size_t index, int lifeScore, sf::Vector2f shieldPosition);
	void updateScore(int score);
	void removeShieldsText(size_t index);
	void removeShieldsTexts();
	void addShieldsTexts();
};

