#include "Treasure.h"
#include "Player.h"
#include "Transform2D.h"
#include "SpriteComponent.h"
#include "CircleCollider.h"
#include "Engine.h"
#include "Enemy.h"

Treasure::Treasure(float scaleIncrease, float despawnTime, float x, float y) : Actor(x, y, "Treasure")
{
	//Initialize default values.
	m_scaleIncrease = scaleIncrease;
	m_despawnTime = despawnTime;

	//Add a sprite component so the player can see the treasure.
	SpriteComponent* spriteComp = new SpriteComponent(this, "Images/star_gold.png");
	addComponent(spriteComp);
	getTransform()->setScale({ 50,50 });

	//Add a collider so it can be picked up.
	CircleCollider* collider = new CircleCollider(50, this);
	setCollider(collider);
}

void Treasure::onCollision(Actor* other)
{
	//Attempting to place the actor collided with into a player pointer variable.
	Player* player = dynamic_cast<Player*>(other);

	Engine::destroy(this);

	//If the variable isn't null that means the other actor must be a player so...
	if (player)
	{
		//...scale up the player.
		MathLibrary::Vector2 newScale = player->getTransform()->getScale() + MathLibrary::Vector2(m_scaleIncrease, m_scaleIncrease);
		player->getTransform()->setScale(newScale);

		return;
	}

	Enemy* enemy = dynamic_cast<Enemy*>(other);

	//If the variable isn't null that means the other actor must be an enemy so...
	if (enemy)
	{
		//...scale up the enemy.
		MathLibrary::Vector2 newScale = enemy->getTransform()->getScale() + MathLibrary::Vector2(m_scaleIncrease, m_scaleIncrease);
		enemy->getTransform()->setScale(newScale);

		return;
	}
}

void Treasure::update(float deltaTime)
{
	Actor::update(deltaTime);
	//Increase the timer.
	m_currentTime += deltaTime;

	//If enough time has passed....
	if (m_currentTime >= m_despawnTime)
	{
		//...despawn this treasure.
		Engine::destroy(this);
	}
}
