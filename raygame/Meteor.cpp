#include "Meteor.h"
#include "Transform2D.h"
#include <stdlib.h>
#include <time.h>
#include "Player.h"
#include "Engine.h"
#include "CircleCollider.h"
#include "SpriteComponent.h"

Meteor::Meteor(float x, float y, const char* name) : Actor(x,y,name)
{
	srand(time(NULL));

	//Adds a sprite component by default.
	SpriteComponent* spriteComp = new SpriteComponent(this, "Images/meteor.png");
	addComponent(spriteComp);

	//Set the scale to be twice as much as the player. Can be modified.
	getTransform()->setScale({ 100, 100 });

	//Created a default collider.
	CircleCollider* circleCollider = new CircleCollider(80, this);
	setCollider(circleCollider);
}

void Meteor::start()
{
	//Generates a random direction.
	float randX = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
	float randY = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);

	m_direction = MathLibrary::Vector2(randX, randY);
}

void Meteor::update(float deltaTime)
{
	//Constantly moves in the randomly generated direction.
	MathLibrary::Vector2 velocity = m_direction * m_speed * deltaTime;

	MathLibrary::Vector2 position = getTransform()->getWorldPosition() + velocity;

	getTransform()->setLocalPosition(position);
}

void Meteor::onCollision(Actor* other)
{
	Player* player = dynamic_cast<Player*>(other);

	if (player)
		Engine::destroy(player);
}
