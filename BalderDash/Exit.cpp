
// Project Includes
#include "Exit.h"
#include "FrameWork/AssetManager.h"

Exit::Exit()
	: GridObject() // Initialise parent class
	, m_player()
{
	m_sprite.setTexture(AssetManager::GetTexture("graphics/DoorClosed.png"));
	m_blocksMovement = true;
}

void Exit::Update(sf::Time _frameTime)
{

		bool hasDiamonds = m_level->HasEnoughDiamonds();
		if (hasDiamonds == true)
		{
			m_sprite.setTexture(AssetManager::GetTexture("graphics/DoorOpen.png"));
		}
	
	
	
}


void Exit::Collide(GameObject& _collider)
{
	// Only do something if the thing
	// we touched was the player
	Player* castPlayer = dynamic_cast<Player*>(&_collider);
	Level* m_level = dynamic_cast<Level*>(&_collider);

	// Only do the thing if player is not null
	if (castPlayer != nullptr)
	{
		// We were touched by the player

		// if the player has the key...
		if (m_level->HasEnoughDiamonds())
		{
			// Load Next Level
			m_level->LoadNextLevel();
		}
	}
}

void Exit::SetPlayer(Player* _player)
{
	m_player = _player;
}
