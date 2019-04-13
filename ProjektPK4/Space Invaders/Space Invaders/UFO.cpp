#include "UFO.h"



UFO::UFO(sf::Vector2f position, sf::Vector2f scale, float speed, std::string ufoLowPitch, std::string ufoHighPitch, std::string ufoTexWhite, std::string ufoTexRed)
{
	this->texIndex = 0;
	this->maxSpeed = 10;
	this->moveTimer = 20;
	this->currentMoveTimer = moveTimer;

	try
	{
		this->texturesInitialization(ufoTexWhite, ufoTexRed);
		this->soundsInitialization(ufoLowPitch, ufoHighPitch);
	}
	catch (LoadingError error)
	{
		system("pause");
		exit(EXIT_FAILURE);
	}

	ufo.setTexture(this->textures[0]);
	ufo.setScale(sf::Vector2f(scale));
	ufo.setOrigin(ufo.getLocalBounds().width / 2.f, ufo.getLocalBounds().height / 2.f);
	ufo.setPosition(position);
}

void UFO::render(sf::RenderWindow*window)
{
	window->draw(this->ufo);
}

void UFO::update()
{
	this->move();
}

void UFO::texturesInitialization(std::string ufoTexWhite,std::string ufoTexRed)
{
	sf::Texture ufoTex;

	if (!ufoTex.loadFromFile(ufoTexWhite))
		throw LoadingError("ufo texture loading error");

	this->textures.push_back(sf::Texture(ufoTex));

	if (!ufoTex.loadFromFile(ufoTexRed))
		throw LoadingError("ufo texture loading error");

	this->textures.push_back(sf::Texture(ufoTex));
}

void UFO::soundsInitialization(std::string ufoLowPitch,std::string ufoHighPitch)
{
	sf::SoundBuffer soundBuffer;
	sf::Sound sound;

	this->soundsBuffer.push_back(sf::SoundBuffer(soundBuffer));
	this->soundsBuffer.push_back(sf::SoundBuffer(soundBuffer));


	if (!soundsBuffer[0].loadFromFile(ufoLowPitch))
		throw LoadingError("ufo sound loading error");

	sound.setBuffer(this->soundsBuffer[0]);
	this->sounds.push_back(sf::Sound(sound));

	if (!soundsBuffer[1].loadFromFile(ufoHighPitch))
		throw LoadingError("ufo sound loading error");

	sound.setBuffer(this->soundsBuffer[1]);
	this->sounds.push_back(sf::Sound(sound));
}

void UFO::move()
{
	//update move
	if (currentMoveTimer < moveTimer)
		currentMoveTimer += 1;

	//move
	if (currentMoveTimer >= moveTimer)
	{
		this->changeTexture();
		currentMoveTimer = 0;
	}

	this->ufo.move(2.f, 0.f);
	
}

void UFO::changeTexture()
{
	if (this->texIndex == 0)
	{
		this->ufo.setTexture(this->textures[1]);
		this->texIndex = 1;
	}
	else
	{
		this->ufo.setTexture(this->textures[0]);
		this->texIndex = 0;
	}
}