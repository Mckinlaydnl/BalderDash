#pragma once

// Project Includes
#include "GridObject.h"
#include "Player.h"
#include "Level.h"

class Exit : public GridObject
{
public:
	Exit();

	// Overriding Methods
	void Update(sf::Time _frameTime);
	void Collide(GameObject& _collider);

	// Public Score Methods
	void SetPlayer(Player* _player);
	
private:

	Player* m_player;
};