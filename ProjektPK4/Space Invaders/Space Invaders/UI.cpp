#include "UI.h"



UI::UI()
{
	this->score = 0;

	this->fontInitialization();
	this->lifeTextInitialization();
	this->scoreTextInitialization();
	this->addShieldsText();
	
}

void UI::renderShieldText(sf::RenderWindow*window)
{
	std::vector<sf::Text>::iterator it;
	for (it = shieldsText.begin(); it < shieldsText.end(); it++)
	{
		window->draw(*it);
	}
}

void UI::removeShieldsText()
{
	this->shieldsText.clear();
}

void UI::addShieldsText()
{
	this->shieldsText.push_back(sf::Text(this->shieldTextInitialization(sf::Vector2f(700, 500))));
	this->shieldsText.push_back(sf::Text(this->shieldTextInitialization(sf::Vector2f(500, 500))));
	this->shieldsText.push_back(sf::Text(this->shieldTextInitialization(sf::Vector2f(300, 500))));
	this->shieldsText.push_back(sf::Text(this->shieldTextInitialization(sf::Vector2f(100, 500))));
}

void UI::lifeTextInitialization()
{
	this->lifeText.setFont(*font);
	this->lifeText.setCharacterSize(15);
	this->lifeText.setFillColor(sf::Color::White);
	this->lifeText.setString("LIFES");
	this->lifeText.setPosition(sf::Vector2f(590.f,25.f));
}

void UI::scoreTextInitialization()
{
	this->scoreText.setFont(*font);
	this->scoreText.setCharacterSize(15);
	this->scoreText.setFillColor(sf::Color::White);
	this->scoreText.setString("SCORE "+std::to_string(this->score));
	this->scoreText.setPosition(sf::Vector2f(15.f, 25.f));
}



void UI::render(sf::RenderWindow*window)
{
	this->renderShieldText(window);
	window->draw(this->lifeText);
	window->draw(this->scoreText);
}

void UI::fontInitialization()
{
	this->font = std::unique_ptr<sf::Font>(new sf::Font);
	if (!this->font->loadFromFile("Fonts/SpaceInvader.ttf"))
		throw LoadingError("Font loading error!");
}

sf::Text UI::shieldTextInitialization(sf::Vector2f position)
{
	this->shieldText.setFont(*font);
	this->shieldText.setCharacterSize(25);
	this->shieldText.setFillColor(sf::Color::White);
	this->shieldText.setString("10");

	sf::FloatRect boundsShieldText = shieldText.getLocalBounds();
	sf::Vector2f centerShieldText(boundsShieldText.left + boundsShieldText.width / 2.f, boundsShieldText.top + boundsShieldText.height / 2.f);
	shieldText.setOrigin(centerShieldText);
	shieldText.setPosition(position);
	return shieldText;
}

void UI::updateShieldLife(size_t index, int lifeScore,sf::Vector2f shieldPosition)
{
	this->shieldsText[index].setString(std::to_string(lifeScore));

	sf::FloatRect boundsShieldText = this->shieldsText[index].getLocalBounds();
	sf::Vector2f centerShieldText(boundsShieldText.left + boundsShieldText.width / 2.f, boundsShieldText.top + boundsShieldText.height / 2.f);
	this->shieldsText[index].setOrigin(centerShieldText);
	this->shieldsText[index].setPosition(shieldPosition);
}

void UI::removeShieldsText(size_t index)
{
	this->shieldsText.erase(shieldsText.begin() + index);
}

void UI::updateScore()
{
	this->scoreText.setString("SCORE " + std::to_string(this->score));
}

void UI::addScore(int enemyType)
{
	//enemies1
	if (enemyType == 1)
	{
		this->score += 100;
	}
	//enemies2
	else if (enemyType == 2)
	{
		this->score += 200;
	}
	//enemies3
	else if(enemyType==3)
	{
		this->score += 300;
	}
}



UI::~UI()
{

}
