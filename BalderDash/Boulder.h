#pragma once

// Project Includes
#include "GridObject.h"

// Library Includes
#include <SFML/Audio.hpp>

class Boulder : public GridObject
{

public:

	Boulder();
	virtual void Update(sf::Time _frameTime);
	bool AttemptPush(sf::Vector2i _direction);

private:

	sf::Sound m_pushSound;
	sf::Sound m_squashSound;
	float emptyTimer;
	float fallTimer;
	
};