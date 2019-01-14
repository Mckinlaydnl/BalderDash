// Project Includes
#include "Diamond.h"
#include "Framework/AssetManager.h"

Diamond::Diamond()
	: GridObject()
	, m_pushSound()
	, emptyTimer(0)
	, fallTimer(0.9f)
{
	m_sprite.setTexture(AssetManager::GetTexture("graphics/diamond.png"));
	m_blocksMovement = true;
	m_pushSound.setBuffer(AssetManager::GetSoundBuffer("audio/push.wav"));
	m_squashSound.setBuffer(AssetManager::GetSoundBuffer("audio/squash.wav"));

}

// Project Includes
#include "Diamond.h"
#include "Framework/AssetManager.h"
#include "Level.h"
#include "Player.h"


void Diamond::Update(sf::Time _frameTime)
{
	emptyTimer += _frameTime.asSeconds();
	if (fallTimer < emptyTimer)
	{
		AttemptPush(sf::Vector2i(0, 1));
		emptyTimer = 0;
	}

}


bool Diamond::AttemptPush(sf::Vector2i _direction)
{


	// Attempt to move the box in the given direction

	// Get current position
	// Calculate target position
	sf::Vector2i targetPos = m_gridPosition + _direction;

	// Check if the space is empty

	// Get list of objects in our target position
	std::vector<GridObject*> targetCellContents = m_level->GetObjectAt(targetPos);

	// Check if any of those objects block movement
	GridObject* blocker = nullptr;
	bool blocked = false;
	for (int i = 0; i < targetCellContents.size(); ++i)
	{
		if (targetCellContents[i]->GetBlocksMovement() == true)
		{
			blocker = targetCellContents[i];
			blocked = true;
		}
	}

	// If empty, move there
	if (blocked == false)
	{
		m_pushSound.play();
		return m_level->MoveObjectTo(this, targetPos);
	}
	else
	{

		Player* ourPlayer = dynamic_cast<Player*>(blocker);
		if (ourPlayer != nullptr)
		{
			m_squashSound.play();
			m_level->ReloadLevel();
			return false;
		}
		Diamond* ourDiamond = dynamic_cast<Diamond*>(blocker);
		if (ourDiamond != nullptr)
		{
			// Attempt to move the box in the given direction

	// Get current position
	// Calculate target position
			sf::Vector2i newtargetPos = m_gridPosition;
			newtargetPos.x = m_gridPosition.x + 1;

			// Check if the space is empty

			// Get list of objects in our target position
			std::vector<GridObject*> targetCellContents = m_level->GetObjectAt(newtargetPos);

			// Check if any of those objects block movement
			blocked = false;
			for (int i = 0; i < targetCellContents.size(); ++i)
			{
				if (targetCellContents[i]->GetBlocksMovement() == true)
				{
					blocked = true;
				}
			}
			if (blocked == false)
			{
				return m_level->MoveObjectTo(this, newtargetPos);
			}
			else
			{
				// Attempt to move the box in the given direction

				// Get current position
				// Calculate target position
				newtargetPos = m_gridPosition;
				newtargetPos.x = m_gridPosition.x - 1;

				// Check if the space is empty

				// Get list of objects in our target position
				std::vector<GridObject*> targetCellContents = m_level->GetObjectAt(newtargetPos);

				// Check if any of those objects block movement
				blocked = false;
				for (int i = 0; i < targetCellContents.size(); ++i)
				{
					if (targetCellContents[i]->GetBlocksMovement() == true)
					{
						blocked = true;
					}
				}
				if (blocked == false)
				{
					return m_level->MoveObjectTo(this, newtargetPos);
				}
			}
		}
	}


	// If movement is blocked, do nothing, return false
	// Default
	return false;
}



