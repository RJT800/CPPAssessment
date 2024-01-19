#include "LodisScene.h"
#include "TreasureSpawner.h"

void LodisScene::start()
{
	//Example of setting up spawner.

	//You can modify locations like so. You can add as many or as few as needed. You must ensure that the number of locations in the array matches the spawner constructor paremeter.
	MathLibrary::Vector2* spawnLocations = new MathLibrary::Vector2[4]{ {20,20},{600,20},{20,600},{600,600}, };

	TreasureSpawner* spawner = new TreasureSpawner(1, spawnLocations, 4, 1);

	addActor(spawner);
}
