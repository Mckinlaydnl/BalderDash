#pragma once

// Project Includes
#include "SpriteObject.h"
#include "Player.h"

class Pickup : public GridObject
{
public:

	Pickup();

	// Overriding Methods
	void Collide(GameObject& _collider);

private:

	virtual void OnPickup(Player& _player);

};