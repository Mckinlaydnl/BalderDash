// Project Includes
#include "Boulder.h"
#include "Framework/AssetManager.h"
#include "Level.h"

Boulder::Boulder()
	: GridObject()
	, m_pushSound()
{
	m_sprite.setTexture(AssetManager::GetTexture("graphics/boulder.png"));
	m_blocksMovement = true;
	m_pushSound.setBuffer(AssetManager::GetSoundBuffer("audio/push.wav"));

}


bool Boulder::AttemptPush(sf::Vector2i _direction)
{
	// Attempt to move the box in the given direction

	// Get current position
	// Calculate target position
	sf::Vector2i targetPos = m_gridPosition + _direction;

	// Check if the space is empty

	// Get list of objects in our target position
	std::vector<GridObject*> targetCellContents = m_level->GetObjectAt(targetPos);

	// Check if any of those objects block movement
	bool blocked = false;
	for (int i = 0; i < targetCellContents.size(); ++i)
	{
		if (targetCellContents[i]->GetBlocksMovement() == true)
		{
			blocked = true;
		}
	}

	// If empty, move there
	if (blocked == false)
	{
		m_pushSound.play();
		return m_level->MoveObjectTo(this, targetPos);
	}

	// If movement is blocked, do nothing, return false
	// Default
	return false;
}