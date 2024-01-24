#include "MeteorSpawner.h"
#include "Meteor.h"
#include "Engine.h"
#include "Scene.h"

MeteorSpawner::MeteorSpawner(float spawnDelay, MathLibrary::Vector2* locations, int locationCount) : Spawner(spawnDelay, locations, locationCount, "MeteorSpawner")
{
}

void MeteorSpawner::spawnItem(MathLibrary::Vector2 location)
{
	Meteor* meteor = new Meteor(location.x, location.y, "Meteor");
	Engine::getCurrentScene()->addActor(meteor);
}
