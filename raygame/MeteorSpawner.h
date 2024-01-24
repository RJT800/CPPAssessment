#pragma once
#include "Spawner.h"

class MeteorSpawner : public Spawner
{
public:

	/// <param name="spawnDelay">The amount of time to wait before spawning a new piece of treasure.</param>
	/// <param name="locations">The possible locations in the world that treasure can spawn.</param>
	/// <param name="locationCount">The amount of locations in the location array given.</param>
	MeteorSpawner(float spawnDelay, MathLibrary::Vector2* locations, int locationCount);

	// Inherited via Spawner
	virtual void spawnItem(MathLibrary::Vector2 location) override;

};

