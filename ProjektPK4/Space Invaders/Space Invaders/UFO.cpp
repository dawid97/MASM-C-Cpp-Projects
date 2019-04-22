#include "UFO.h"


UFO::UFO(float maxSpeed,sf::Vector2f position, sf::Vector2f scale, float speed, std::string ufoLowPitch, std::string ufoHighPitch, std::string ufoTexWhite, std::string ufoTexRed)
{
	this->texIndex = 0;
	this->maxSpeed = maxSpeed;

	srand(unsigned int(time(NULL)));

	this->score = std::rand() % 201 + 50;

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
	this->ufo.move(maxSpeed, 0.f);
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

int UFO::moveTimer = 1000;
int UFO::currentMoveTimer = 0;

int UFO::textureTimer = 200;
int UFO::currentTextureTimer = UFO::textureTimer;

int UFO::getMoveTimer()
{
	return UFO::moveTimer;
}

int UFO::getCurrentMoveTimer()
{
	return UFO::currentMoveTimer;
}

void UFO::resetCurrentMoveTimer()
{
	UFO::currentMoveTimer = 0;
}

void UFO::incrementCurrentMoveTimer()
{
	UFO::currentMoveTimer++;
}

sf::Vector2f UFO::getPosition()
{
	return this->ufo.getPosition();
}

int UFO::getTextureTimer()
{
	return UFO::textureTimer;
}

int UFO::getCurrentTextureTimer()
{
	return UFO::currentTextureTimer;
}

void UFO::resetCurrentTextureTimer()
{
	UFO::currentTextureTimer = 0;
}

void UFO::incrementCurrentTextureTimer()
{
	UFO::currentTextureTimer++;
}

void UFO::playLowPitch()
{
	this->sounds[0].play();
}

void UFO::playHighPitch()
{
	this->sounds[1].play();
}

sf::FloatRect UFO::getGlobalBounds()
{
	return this->ufo.getGlobalBounds();
}

int UFO::getScore()
{
	return this->score;
}

void UFO::setCurrentTextureTimer(int value)
{
	UFO::currentTextureTimer = value;
}