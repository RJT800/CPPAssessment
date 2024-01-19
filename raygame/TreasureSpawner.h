#pragma once
#include "Actor.h"
#include "ActorArray.h"
#include <Vector2.h>

class TreasureSpawner : public Actor
{
public:
	/// <param name="spawnDelay">The amount of time to wait before spawning a new piece of treasure.</param>
	/// <param name="locations">The possible locations in the world that treasure can spawn.</param>
	/// <param name="locationCount">The amount of locations in the location array given.</param>
	/// <param name="treasureScaleIncrease">The amount that the player scale should increase after colliding with treasure.</param>
	TreasureSpawner(float spawnDelay, MathLibrary::Vector2* locations, int locationCount, float treasureScaleIncrease);

	void update(float deltaTime) override;

private:
	float m_spawnDelay;
	float m_currentTime;
	float m_treasureScaleIncrease;
	int m_locationCount;

	MathLibrary::Vector2* m_locations;
};

