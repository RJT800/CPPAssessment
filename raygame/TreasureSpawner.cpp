#include "TreasureSpawner.h"
#include <stdlib.h>
#include <time.h>
#include "Engine.h"
#include "Scene.h"
#include "Treasure.h"

TreasureSpawner::TreasureSpawner(float spawnDelay, MathLibrary::Vector2* locations, int locationCount, float treasureScaleIncrease) : Actor(0, 0, "TreasureSpawner")
{
	//Initialize default values.
	m_spawnDelay = spawnDelay;
	m_locations = locations;
	m_locationCount = locationCount;
	m_treasureScaleIncrease = treasureScaleIncrease;

	//Seed the random number generator before randomization starts.
	srand(time(NULL));
}

void TreasureSpawner::update(float deltaTime)
{
	Actor::update(deltaTime);

	//Increase the amount of time that has passed.
	m_currentTime += deltaTime;

	//Exit the function if there hasn't been enough time to spawn another treasure piece.
	if (m_currentTime <= m_spawnDelay)
		return;

	//Generate a random number to use for the location index.
	int choice = rand() % m_locationCount;

	//Get a location from the location array using the randomly generated number.
	MathLibrary::Vector2 location = m_locations[choice];

	//Create a new treasure piece and at it to the scene using the random location.
	Treasure* treasure = new Treasure(m_treasureScaleIncrease, location.x, location.y);
	Engine::getCurrentScene()->addActor(treasure);


	//Reset the timer to do it all again.
	m_currentTime = 0;
}
