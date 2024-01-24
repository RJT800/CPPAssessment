#include "LodisScene.h"
#include "TreasureSpawner.h"
#include "Player.h"
#include "Transform2D.h"
#include "Meteor.h"
#include "MeteorSpawner.h"

void LodisScene::start()
{
	//Example of setting up spawner.

	//You can modify locations like so. You can add as many or as few as needed. You must ensure that the number of locations in the array matches the spawner constructor paremeter.
	MathLibrary::Vector2* spawnLocations = new MathLibrary::Vector2[4]{ {20,20},{600,20},{20,600},{600,600}, };

	TreasureSpawner* spawner = new TreasureSpawner(1, spawnLocations, 4, 1);
	MeteorSpawner* meteorSpawner = new MeteorSpawner(2, spawnLocations, 4);

	Player* player = new Player();
	player->getTransform()->setLocalPosition({ 500,500 });

	addActor(player);
	addActor(spawner);
	addActor(meteorSpawner);
}
