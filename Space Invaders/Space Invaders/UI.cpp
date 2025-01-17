#include "UI.h"

int UI::renderUfoScore = 0;

sf::Text UI::createShieldText(sf::Vector2f position, sf::Color color, std::string inscription, unsigned int size)
{
	this->shieldText.setFont(*font);
	this->shieldText.setCharacterSize(size);
	this->shieldText.setFillColor(color);
	this->shieldText.setString(inscription);

	sf::FloatRect boundsShieldText = shieldText.getLocalBounds();
	sf::Vector2f centerShieldText(boundsShieldText.left + boundsShieldText.width / 2.f, boundsShieldText.top + boundsShieldText.height / 2.f);
	shieldText.setOrigin(centerShieldText);
	shieldText.setPosition(position);
	return shieldText;
}

void UI::highscoreInitialization(std::string fileName,sf::Color color, unsigned int size, sf::Vector2f position)
{
	std::string score;

	std::fstream file;
	file.open("playersData.txt", std::ios::in);
	if (!file.good())
		throw LoadingError("PlayersData loading error");

	file.seekg(0, std::ios::end);
	if (file.tellg() == 0)
		score = "0";
	else
	{
		file.seekg(0, std::ios::beg);
		std::getline(file, score);
		std::getline(file, score);
	}
		
	this->highscoreText.setFont(*font);
	this->highscoreText.setCharacterSize(size);
	this->highscoreText.setFillColor(color);
	this->highscoreText.setString("HIGHSCORE " + score);
	this->highscoreText.setPosition(position);
}

void UI::livesInitialization()
{
	this->lives.push_back(Live(sf::Vector2f(670.f, 30.f), sf::Vector2f(0.03f, 0.03f), sf::Color::Green, "Textures/ship.png"));
	this->lives.push_back(Live(sf::Vector2f(715.f, 30.f), sf::Vector2f(0.03f, 0.03f), sf::Color::Green, "Textures/ship.png"));
	this->lives.push_back(Live(sf::Vector2f(760.f, 30.f), sf::Vector2f(0.03f, 0.03f), sf::Color::Green, "Textures/ship.png"));
}

void UI::lifeTextInitialization(sf::Vector2f position, sf::Color color, std::string inscription, unsigned int size)
{
	this->liveText.setFont(*font);
	this->liveText.setCharacterSize(size);
	this->liveText.setFillColor(color);
	this->liveText.setString(inscription);
	this->liveText.setPosition(position);
}

void UI::fontInitialization(std::string fileNameFont)
{
	this->font = std::unique_ptr<sf::Font>(new sf::Font);
	if (!this->font->loadFromFile(fileNameFont))
		throw LoadingError("Font loading error!");
}

void UI::scoreTextInitialization(sf::Vector2f position, sf::Color color, unsigned int size,int score)
{
	this->scoreText.setFont(*font);
	this->scoreText.setCharacterSize(size);
	this->scoreText.setFillColor(color);
	this->scoreText.setString("SCORE " + std::to_string(score));
	this->scoreText.setPosition(position);
}

void UI::renderShieldsTexts(sf::RenderWindow*window)
{
	std::vector<sf::Text>::iterator it;
	for (it = shieldsTexts.begin(); it < shieldsTexts.end(); it++)
	{
		window->draw(*it);
	}
}

void UI::addShieldsTexts()
{
	this->shieldsTexts.push_back(sf::Text(this->createShieldText(sf::Vector2f(700, 500), sf::Color::White, "10", 20)));
	this->shieldsTexts.push_back(sf::Text(this->createShieldText(sf::Vector2f(500, 500), sf::Color::White, "10", 20)));
	this->shieldsTexts.push_back(sf::Text(this->createShieldText(sf::Vector2f(300, 500), sf::Color::White, "10", 20)));
	this->shieldsTexts.push_back(sf::Text(this->createShieldText(sf::Vector2f(100, 500), sf::Color::White, "10", 20)));
}

UI::UI()
{
	try
	{
		this->fontInitialization("Fonts/SpaceInvader.ttf");
		this->highscoreInitialization("PlayersData.txt",sf::Color::White, 15, sf::Vector2f(280.f, 25.f));
		
	}
	catch (LoadingError error)
	{
		system("pause");
		exit(EXIT_FAILURE);
	}

	this->lifeTextInitialization(sf::Vector2f(590.f,25.f),sf::Color::White,"LIVES",15);
	this->scoreTextInitialization(sf::Vector2f(15.f,25.f),sf::Color::White,15,0);
	this->ufoScoreTextInitialization(sf::Vector2f(150.f, 25.f), sf::Color::White, 15, 0);
	this->addShieldsTexts();
	this->livesInitialization();
	
}

void UI::renderLifes(sf::RenderWindow*window)
{
	std::vector<Live>::iterator it;
	for (it = lives.begin(); it < lives.end(); it++)
	{
		it->render(window);
	}
}

void UI::removeShieldsTexts()
{
	this->shieldsTexts.clear();
}

void UI::removeLive()
{
	this->lives.erase(this->lives.end() - 1);
}

void UI::render(sf::RenderWindow*window)
{
	this->renderShieldsTexts(window);
	window->draw(this->liveText);
	window->draw(this->scoreText);
	this->renderLifes(window);
	window->draw(this->highscoreText);
}

void UI::renderUfoScoreText(sf::RenderWindow*window)
{
	window->draw(this->ufoScoreText);
}

void UI::updateShieldLife(size_t index, int lifeScore,sf::Vector2f shieldPosition)
{
	this->shieldsTexts[index].setString(std::to_string(lifeScore));

	sf::FloatRect boundsShieldText = this->shieldsTexts[index].getLocalBounds();
	sf::Vector2f centerShieldText(boundsShieldText.left + boundsShieldText.width / 2.f, boundsShieldText.top + boundsShieldText.height / 2.f);
	this->shieldsTexts[index].setOrigin(centerShieldText);
	this->shieldsTexts[index].setPosition(shieldPosition);
}

void UI::updateScore(int score)
{
	this->scoreText.setString("SCORE " + std::to_string(score));
}

void UI::removeShieldsText(size_t index)
{
	this->shieldsTexts.erase(shieldsTexts.begin() + index);
}

void UI::ufoScoreTextInitialization(sf::Vector2f position, sf::Color color, unsigned int size, int score)
{
	this->ufoScoreText.setFont(*font);
	this->ufoScoreText.setCharacterSize(size);
	this->ufoScoreText.setFillColor(color);
	this->ufoScoreText.setString(std::to_string(score));
	sf::FloatRect boundsUfoScore = this->ufoScoreText.getLocalBounds();
	sf::Vector2f centerUfoScore(boundsUfoScore.left + boundsUfoScore.width / 2.f, boundsUfoScore.top + boundsUfoScore.height / 2.f);
	this->ufoScoreText.setOrigin(centerUfoScore);
	this->ufoScoreText.setPosition(position);
}

void UI::updateUfoScore(int score,sf::Vector2f position)
{
	this->ufoScoreText.setPosition(position);
	this->ufoScoreText.setString(std::to_string(score));
}

int UI::getRenderUfoScore()
{
	return UI::renderUfoScore;
}

void UI::setRenderUfoScore(int value)
{
	UI::renderUfoScore = value;
}