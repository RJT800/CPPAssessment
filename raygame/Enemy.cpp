#include "Enemy.h"
#include "Player.h"
#include "Treasure.h"
#include <Vector2.h>
#include "Transform2D.h"
#include "CircleCollider.h"
#include "SpriteComponent.h"
#include "Engine.h"

Enemy::Enemy(Player* target, float speed, float x, float y) : Actor(x,y, "Enemy")
{
	m_target = target;
	m_speed = speed;

	m_collider = new CircleCollider(getTransform()->getScale().x, this);
	setCollider(m_collider);

	SpriteComponent* spriteComp = new SpriteComponent(this, "Images/enemy.png");
	addComponent(spriteComp);

	getTransform()->setScale({ 50,50 });
}

void Enemy::onCollision(Actor* other)
{
	Player* player = dynamic_cast<Player*>(other);

	if (player)
	{
		Engine::destroy(player);
	}
}

void Enemy::update(float deltaTime)
{
	Actor::update(deltaTime);

	if (!m_target)
		return;

	MathLibrary::Vector2 position = getTransform()->getWorldPosition();

	MathLibrary::Vector2 direction = (m_target->getTransform()->getWorldPosition() - position).getNormalized();

	MathLibrary::Vector2 velocity = direction * m_speed;

	if (velocity.getMagnitude() > 0)
		getTransform()->setForward(velocity.getNormalized());

	getTransform()->setLocalPosition(position + velocity);

	m_collider->setCollisionRadius(getTransform()->getScale().x);
}
