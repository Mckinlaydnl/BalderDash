#pragma once

// Project Includes
#include "GridObject.h"

// Library Includes
#include <SFML/Audio.hpp>

class Boulder : public GridObject
{

public:

	Boulder();

	bool AttemptPush(sf::Vector2i _direction);

private:

	sf::Sound m_pushSound;
};