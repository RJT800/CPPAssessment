#pragma once
#include "Actor.h"

class Player;
class CircleCollider;

class Enemy : public Actor
{
public:
	Enemy(Player* target, float speed, float x, float y);

	void onCollision(Actor* other) override;
	void update(float deltaTime) override;

private:
	Player* m_target;
	float m_speed;
	CircleCollider* m_collider;
};

