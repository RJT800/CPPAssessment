#include "TreasureSpawner.h"
#include "Treasure.h"
#include "Engine.h"
#include "Scene.h"

TreasureSpawner::TreasureSpawner(float spawnDelay, MathLibrary::Vector2* locations, int locationCount, float treasureScaleIncrease) : Spawner(spawnDelay, locations, locationCount, "TreasureSpawner")
{
	//Initialize default values.
	m_spawnDelay = spawnDelay;
	m_locations = locations;
	m_locationCount = locationCount;
	m_treasureScaleIncrease = treasureScaleIncrease;
}

void TreasureSpawner::spawnItem(MathLibrary::Vector2 location)
{
	//Initialize new treasure and add it to the scene.
	Treasure* treasure = new Treasure(m_treasureScaleIncrease, 10, location.x, location.y);
	Engine::getCurrentScene()->addActor(treasure);
}
