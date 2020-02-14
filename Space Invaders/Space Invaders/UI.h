#pragma once
#include<SFML/Graphics.hpp>
#include"Exceptions.h"
#include"Player.h"
#include"Live.h"
#include<fstream>



class UI
{
private:
	std::unique_ptr<sf::Font>font;
	sf::Text shieldText;
	sf::Text scoreText;
	sf::Text ufoScoreText;
	sf::Text highscoreText;


	sf::Text liveText;
	std::vector<Live> lives;
	std::vector<sf::Text>shieldsTexts;


	sf::Text createShieldText(sf::Vector2f position,sf::Color color,std::string inscription,unsigned int size);
	void livesInitialization();
	void lifeTextInitialization(sf::Vector2f position, sf::Color color, std::string inscription, unsigned int size);
	void highscoreInitialization(std::string fileName,sf::Color color, unsigned int size, sf::Vector2f position);
	void fontInitialization(std::string fileNameFon);
	void scoreTextInitialization(sf::Vector2f position, sf::Color color, unsigned int size, int score);
	void ufoScoreTextInitialization(sf::Vector2f position, sf::Color color, unsigned int size, int score);
	void renderShieldsTexts(sf::RenderWindow*window);
	void renderLifes(sf::RenderWindow*window);
	static int renderUfoScore;

	
public:
	UI();
	void removeLive();
	void render(sf::RenderWindow*window);
	void updateShieldLife(size_t index, int lifeScore, sf::Vector2f shieldPosition);
	void updateScore(int score);
	void removeShieldsText(size_t index);
	void removeShieldsTexts();
	void addShieldsTexts();
	void renderUfoScoreText(sf::RenderWindow*window);
	void updateUfoScore(int score,sf::Vector2f position);
	static int getRenderUfoScore();
	static void setRenderUfoScore(int value);
};

