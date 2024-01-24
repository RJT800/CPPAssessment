#pragma once
#include "Actor.h"
#include "ActorArray.h"
#include <Vector2.h>

class Spawner : public Actor
{
public:
	/// <param name="spawnDelay">The amount of time to wait before spawning a new piece of treasure.</param>
	/// <param name="locations">The possible locations in the world that treasure can spawn.</param>
	/// <param name="locationCount">The amount of locations in the location array given.</param>
	/// <param name="name">The name of this type of spawner.</param>
	Spawner(float spawnDelay, MathLibrary::Vector2* locations, int locationCount, const char* name);

	void update(float deltaTime) override;

	/// <summary>
	/// Spawns a given item at a location. Meant to be overidden in order to spawn a specific item.
	/// </summary>
	/// <param name="location">The location in the world to spawn the item.</param>
	virtual void spawnItem(MathLibrary::Vector2 location) = 0;

private:
	float m_spawnDelay;
	float m_currentTime;
	int m_locationCount;

	MathLibrary::Vector2* m_locations;
};

