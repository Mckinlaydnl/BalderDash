#pragma once

#include "GridObject.h"

// Library Includes
#include <SFML/Audio.hpp>
class Diamond : public GridObject
{

public:

	Diamond();
	virtual void Update(sf::Time _frameTime);
	bool AttemptPush(sf::Vector2i _direction);

private:

	sf::Sound m_pushSound;
	float emptyTimer;
	float fallTimer;

};