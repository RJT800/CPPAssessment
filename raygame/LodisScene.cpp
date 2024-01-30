#include "LodisScene.h"
#include "TreasureSpawner.h"
#include "Player.h"
#include "Transform2D.h"
#include "Meteor.h"
#include "MeteorSpawner.h"
#include "MoveComponent.h"
#include "SpriteComponent.h"
#include "CircleCollider.h"

void LodisScene::start()
{
	//Example of setting up spawner.

	//You can modify locations like so. You can add as many or as few as needed. You must ensure that the number of locations in the array matches the spawner constructor paremeter.
	MathLibrary::Vector2* spawnLocations = new MathLibrary::Vector2[25]{ {437,607},{299,674},{413,729},{1316,96},{1070,324},{437,607},{214,789},{285,553},{384,183},{394,208},{1239,713},{339,422},{365,477},{602,76},{1268,502},{1154,487},{1342,237},{216,962},{1048,135},{449,490}, };

	//Add the two spawners for testing.
	TreasureSpawner* spawner = new TreasureSpawner(1, spawnLocations, 25, 2);

	Player* player = new Player();
	player->getTransform()->setLocalPosition({ 500,500 });
	player->addComponent(new SpriteComponent(player, "Images/player.png"));
	player->getTransform()->setScale({ 50, 50 });

	player->addComponent(new MoveComponent(350, player));
	Actor* playerStar = new Actor();
	CircleCollider* collider = new CircleCollider(25, player);
	player->setCollider(collider);

	addActor(player);	
	addActor(spawner);
}
