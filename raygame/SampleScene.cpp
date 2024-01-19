#include "SampleScene.h"
#include "SpriteComponent.h"
#include "MoveComponent.h"
#include "Transform2D.h"
#include "Player.h"

void SampleScene::start()
{
	//This is a better comment
	Actor* test = new Actor(50, 50, "Test");
	test->addComponent(new SpriteComponent(test, "Images/player.png"));
	test->addComponent(new MoveComponent(5, test));
	test->getTransform()->setScale({ 50, 50 });

	addActor(test);
}
