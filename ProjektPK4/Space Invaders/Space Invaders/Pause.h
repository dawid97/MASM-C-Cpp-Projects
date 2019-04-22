#pragma once
#include"GameOver.h"

class Pause: public GameOver
{
private:

public:
	Pause(sf::RenderWindow*window);
	~Pause();
};

