#include "Enemy.h"

void Enemy::enemyInitialization(sf::Vector2f scale, sf::Vector2f position)
{
	this->enemy.setScale(scale);
	

	if (enemyType == "squid")
	{
		this->currentTexture = 0;
		this->enemy.setTexture(this->enemyTextures[0]);
	}
	else if (enemyType == "crab")
	{
		this->currentTexture = 2;
		this->enemy.setTexture(this->enemyTextures[2]);
	}
	else if (enemyType == "octopus")
	{
		this->currentTexture = 4;
		this->enemy.setTexture(this->enemyTextures[4]);
	}

	this->enemy.setOrigin(this->enemy.getLocalBounds().width / 2.f, this->enemy.getLocalBounds().height / 2.f);
	this->enemy.setPosition(position);
}

Enemy::Enemy(sf::Vector2f position,sf::Vector2f scale,std::string enemyType)
{
	this->enemyType = enemyType;
	this->enemyInitialization(scale,position);
}

float Enemy::maxSpeed = 10;
int Enemy::moveTimer = 53;
int Enemy::currentMoveTimer = Enemy::moveTimer;
int Enemy::textureFlag = 0;

int Enemy::shootTimer = 1;
int Enemy::currentShootTimer = Enemy::shootTimer;

std::vector<sf::Texture> Enemy::enemyTextures;

std::vector<Bullet> Enemy::bullets;

void Enemy::texturesInitialization()
{
	sf::Texture enemyTex;

	//squid [0]
	if (!enemyTex.loadFromFile("Textures/enemy11.png"))
		throw LoadingError("enemy texture loading error");

	
    Enemy::enemyTextures.push_back(sf::Texture(enemyTex)); 

	//squid [1]
	if (!enemyTex.loadFromFile("Textures/enemy12.png"))
		throw LoadingError("enemy texture loading error");

	Enemy::enemyTextures.push_back(sf::Texture(enemyTex));

	//crab [2]
	if (!enemyTex.loadFromFile("Textures/enemy21.jpg"))
		throw LoadingError("enemy texture loading error");

	Enemy::enemyTextures.push_back(sf::Texture(enemyTex));

	//crab [3]
	if (!enemyTex.loadFromFile("Textures/enemy22.png"))
		throw LoadingError("enemy texture loading error");

	Enemy::enemyTextures.push_back(sf::Texture(enemyTex));

	//octopus [4]
	if (!enemyTex.loadFromFile("Textures/enemy31.png"))
		throw LoadingError("enemy texture loading error");

	Enemy::enemyTextures.push_back(sf::Texture(enemyTex));

	//octopus [5]
	if (!enemyTex.loadFromFile("Textures/enemy32.png"))
		throw LoadingError("enemy texture loading error");

	Enemy::enemyTextures.push_back(sf::Texture(enemyTex));

	//bulletEnemy1 [6]
	if (!enemyTex.loadFromFile("Textures/bulletEnemy1.png"))
		throw LoadingError("bullet1 texture loading error");

	Enemy::enemyTextures.push_back(sf::Texture(enemyTex));

	//bulletEnemy2 [7]
	if (!enemyTex.loadFromFile("Textures/bulletEnemy2.png"))
		throw LoadingError("bullet2 texture loading error");

	Enemy::enemyTextures.push_back(sf::Texture(enemyTex));
}

std::vector<sf::SoundBuffer> Enemy::soundsBuffer;
std::vector<sf::Sound> Enemy::sounds;

void Enemy::soundsInitialization()
{
	sf::SoundBuffer soundBuffer;

	Enemy::soundsBuffer.push_back(sf::SoundBuffer(soundBuffer));
	Enemy::soundsBuffer.push_back(sf::SoundBuffer(soundBuffer));
	Enemy::soundsBuffer.push_back(sf::SoundBuffer(soundBuffer));
	Enemy::soundsBuffer.push_back(sf::SoundBuffer(soundBuffer));
	Enemy::soundsBuffer.push_back(sf::SoundBuffer(soundBuffer));

	sf::Sound sound;

	//invaderKilled sound [0]
	if (!Enemy::soundsBuffer[0].loadFromFile("Sounds/invaderKilled.wav"))
		throw LoadingError("sound invader killed loading error");

	sound.setBuffer(Enemy::soundsBuffer[0]);
	Enemy::sounds.push_back(sf::Sound(sound));


	//invaderFast1 sound [1]
	if (!soundsBuffer[1].loadFromFile("Sounds/fastinvader1.wav"))
		throw LoadingError("sound fastinvader1 loading error");

	sound.setBuffer(Enemy::soundsBuffer[1]);
	Enemy::sounds.push_back(sf::Sound(sound));

	//invaderFast2 sound [2]
	if (!soundsBuffer[2].loadFromFile("Sounds/fastinvader2.wav"))
		throw LoadingError("sound fastinvader2 loading error");

	sound.setBuffer(Enemy::soundsBuffer[2]);
	Enemy::sounds.push_back(sf::Sound(sound));

	//invaderFast3 sound [3]
	if (!soundsBuffer[3].loadFromFile("Sounds/fastinvader3.wav"))
		throw LoadingError("sound fastinvader3 loading error");

	sound.setBuffer(Enemy::soundsBuffer[3]);
	Enemy::sounds.push_back(sf::Sound(sound));

	//invaderFast4 sound [4]
	if (!soundsBuffer[4].loadFromFile("Sounds/fastinvader4.wav"))
		throw LoadingError("sound fastinvader4 loading error");

	sound.setBuffer(Enemy::soundsBuffer[4]);
	Enemy::sounds.push_back(sf::Sound(sound));
}

float Enemy::getMaxSpeed()
{
	return	Enemy::maxSpeed;
}

int Enemy::getCurrentMoveTimer()
{
	return Enemy::currentMoveTimer;
}

int Enemy::getMoveTimer()
{
	return Enemy::moveTimer;
}

void Enemy::setCurrentMoveTimer(int value)
{
	Enemy::currentMoveTimer = value;
}

void Enemy::incrementCurrentMoveTimer()
{
	Enemy::currentMoveTimer++;
}

void Enemy::changeDirection()
{
	Enemy::maxSpeed = -Enemy::maxSpeed;
}

void Enemy::playInvaderKilledSound()
{
	Enemy::sounds[0].play();
}

void Enemy::changeTextureFlag()
{
	if (Enemy::textureFlag == 0)
		Enemy::textureFlag = 1;
	else
		Enemy::textureFlag = 0;
}

int Enemy::getTextureFlag()
{
	return Enemy::textureFlag;
}

void Enemy::playInvaderMoveSound(size_t vectorSize)
{
	if (vectorSize <= 50 && vectorSize >= 30)
		Enemy::sounds[1].play();
	else if (vectorSize <= 29 && vectorSize >= 20)
		Enemy::sounds[2].play();
	else if (vectorSize <= 19 && vectorSize >= 10)
		Enemy::sounds[3].play();
	else if (vectorSize <= 9 && vectorSize >= 1)
		Enemy::sounds[4].play();
}

void Enemy::decrementMoveTimer()
{
	Enemy::moveTimer--;
}

void Enemy::render(sf::RenderWindow*window)
{
	window->draw(this->enemy);
}

void Enemy::setPosition(sf::Vector2f position)
{
	this->enemy.setPosition(position);
}

void Enemy::setTexture(int index)
{
	this->enemy.setTexture(this->enemyTextures[index]);

	if (Enemy::textureFlag == 0)
		this->currentTexture++;
	else
		this->currentTexture--;
}

int Enemy::getCurrentTexture()
{
	return this->currentTexture;
}

sf::FloatRect Enemy::getGlobalBounds()
{
	return this->enemy.getGlobalBounds();
}

sf::Vector2f Enemy::getPosition()
{
	return this->enemy.getPosition();
}

std::string Enemy::getEnemyType()
{
	return this->enemyType;
}

void Enemy::renderBullets(sf::RenderWindow*window)
{
	std::vector<Bullet>::iterator it;
	for (it = bullets.begin(); it < bullets.end(); it++)
	{
		it->render(window);
	}
}

int Enemy::getCurrentShootTimer()
{
	return Enemy::currentShootTimer;
}

int Enemy::getShootTimer()
{
	return Enemy::shootTimer;
}

void Enemy::incrementCurrentShootTimer()
{
	Enemy::currentShootTimer++;
}

void Enemy::setCurrentShootTimer(int value)
{
	Enemy::currentShootTimer = value;
}

void Enemy::incrementShootTimer()
{
	Enemy::shootTimer++;
}

void Enemy::setMoveTimer(int value)
{
	Enemy::moveTimer = value;
}

void Enemy::setShootTimer(int value)
{
	Enemy::shootTimer = value;
}

void Enemy::setTextureFlag(int value)
{
	Enemy::textureFlag = value;
}

void Enemy::clearSounds()
{
	Enemy::sounds.clear();
}

void Enemy::clearSoundsBuffer()
{
	Enemy::soundsBuffer.clear();
}
