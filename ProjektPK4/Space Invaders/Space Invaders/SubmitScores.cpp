#include "SubmitScores.h"



SubmitScores::SubmitScores(sf::RenderWindow* window)
{
	this->maxNumberOfItems = 2;
	this->selectedItemIndex = -1;
	this->downKey = false;
	this->upKey = false;
	//this->enterKey = false;

	this->background = std::unique_ptr<sf::Sprite>(new sf::Sprite());
	this->backgroundTex = std::unique_ptr<sf::Texture>(new sf::Texture());
	if (!backgroundTex->loadFromFile("Textures/background.png"))
		throw LoadingError("Background loading error");


	background->setTexture(*backgroundTex);
	background->setScale(sf::Vector2f(0.8f, 1.f));
	background->setOrigin(background->getLocalBounds().width / 2.f, background->getLocalBounds().height / 2.f);
	background->setPosition(window->getSize().x / 2.f, window->getSize().y / 2.f);


	this->font = std::unique_ptr<sf::Font>(new sf::Font());
	if (!this->font->loadFromFile("Fonts/SpaceInvader.ttf"))
		throw LoadingError("Font loading error!");


	this->name = std::unique_ptr<sf::Text>(new sf::Text());
	name->setFont(*font);
	this->name->setCharacterSize(15);



	sf::RectangleShape mainBlock;
	mainBlock.setSize(sf::Vector2f(window->getSize().x / 4.f, window->getSize().y / 2.5f));
	mainBlock.setFillColor(sf::Color(180, 180, 180, 70));
	mainBlock.setOutlineThickness(2.f);
	mainBlock.setOutlineColor(sf::Color::Green);
	mainBlock.setOrigin(mainBlock.getGlobalBounds().width / 2.f, mainBlock.getGlobalBounds().height / 2.f);
	mainBlock.setPosition(window->getSize().x / 2.f, window->getSize().y / 2.f);
	blocks.push_back(mainBlock);


	sf::RectangleShape nameBlock(mainBlock);
	nameBlock.setSize(sf::Vector2f(nameBlock.getSize().x / 1.2f, nameBlock.getSize().y / 5.f));
	nameBlock.setFillColor(sf::Color(0, 191, 255));
	nameBlock.setOrigin(nameBlock.getGlobalBounds().width / 2.f, nameBlock.getGlobalBounds().height / 2.f);
	nameBlock.setPosition(nameBlock.getPosition().x, nameBlock.getPosition().y / 1.3f);
	blocks.push_back(nameBlock);


	sf::RectangleShape submitScores(nameBlock);
	submitScores.setFillColor(sf::Color::Black);
	submitScores.setPosition(mainBlock.getPosition().x, mainBlock.getPosition().y);
	blocks.push_back(submitScores);

	sf::RectangleShape exitGame(nameBlock);
	exitGame.setFillColor(sf::Color::Black);
	exitGame.setPosition(mainBlock.getPosition().x, mainBlock.getPosition().y / 0.81f);
	blocks.push_back(exitGame);



	this->nameTex= std::unique_ptr<sf::Text>(new sf::Text());
	nameTex->setFont(*font);
	nameTex->setCharacterSize(17);
	nameTex->setFillColor(sf::Color::White);
	nameTex->setString("ENTER NAME");
	sf::FloatRect boundsName = nameTex->getLocalBounds();
	sf::Vector2f centerName(boundsName.left + boundsName.width / 2.f, boundsName.top + boundsName.height / 2.f);
	nameTex->setOrigin(centerName);
	nameTex->setPosition(window->getSize().x / 2.f, window->getSize().y / 3.15f);


	sf::Text submitScoresText(*nameTex);
	submitScoresText.setString("SUBMIT SCORE");
	sf::FloatRect boundsSubmitScores = submitScoresText.getLocalBounds();
	sf::Vector2f centerSubmitScores(boundsSubmitScores.left + boundsSubmitScores.width / 2.f, boundsSubmitScores.top + boundsSubmitScores.height / 2.f);
	submitScoresText.setOrigin(centerSubmitScores);
	submitScoresText.setPosition(window->getSize().x / 2.f, window->getSize().y / 2.f);
	texts.push_back(submitScoresText);

	sf::Text exitText(*nameTex);
	exitText.setString("EXIT GAME");
	sf::FloatRect boundsExit = exitText.getLocalBounds();
	sf::Vector2f centerExit(boundsExit.left + boundsExit.width / 2.f, boundsExit.top + boundsExit.height / 2.f);
	exitText.setOrigin(centerExit);
	exitText.setPosition(window->getSize().x / 2.f, window->getSize().y / 1.63f);
	texts.push_back(exitText);
}

void SubmitScores::Update(sf::RenderWindow* window)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) && !this->upKey)
	{
		this->moveUp();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) && !this->downKey)
	{
		this->moveDown();
	}

	this->upKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up);
	this->downKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down);
}

void SubmitScores::Render(sf::RenderWindow* window)
{
	window->draw(*this->background);

	std::vector<sf::RectangleShape>::iterator it1;
	for (it1 = blocks.begin(); it1 < blocks.end(); it1++)
		window->draw(*it1);

	window->draw(*this->nameTex);

	std::vector<sf::Text>::iterator it2;
	for (it2 = texts.begin(); it2 < texts.end(); it2++)
		window->draw(*it2);

	window->draw(*name);
}

void SubmitScores::updateUserName(sf::RenderWindow*window,sf::Event*event)
{
	if (event->text.unicode < 128)
	{
		std::unique_ptr<sf::String>str(new sf::String);
		*str = this->name->getString();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Backspace))
		{
			if (str->getSize() > 0)
				str->erase(str->getSize() - 1, 1);
		}
		if (isprint(event->text.unicode) && str->getSize()<15 && this->blocks[1].getFillColor()==sf::Color(0, 191, 255))
		{
			*str += static_cast<char>(event->text.unicode);
			std::cout << "ASCII character typed: " << static_cast<char>(event->text.unicode) << std::endl;
		}
		this->name->setString(*str);
		this->name->setOrigin(this->name->getLocalBounds().left + this->name->getLocalBounds().width / 2.f, this->name->getLocalBounds().top + this->name->getLocalBounds().height / 2.f);
		this->name->setPosition(this->blocks[1].getPosition().x,this->blocks[1].getPosition().y);
	}
}

void SubmitScores::moveUp()
{
	if(selectedItemIndex == 0)
    {
		blocks[1].setFillColor(sf::Color(0, 191, 255));
		texts[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
    }
	if (selectedItemIndex - 1 >= 0)
	{
		texts[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		texts[selectedItemIndex].setFillColor(sf::Color(0, 191, 255));

	}
}

void SubmitScores::moveDown()
{
	if (selectedItemIndex == -1)
	{
		blocks[1].setFillColor(sf::Color::Black);
		selectedItemIndex++;
		texts[selectedItemIndex].setFillColor(sf::Color(0, 191, 255));
	}
	else if (selectedItemIndex + 1 < maxNumberOfItems) 
	{
		texts[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		texts[selectedItemIndex].setFillColor(sf::Color(0, 191, 255));
	}
}
