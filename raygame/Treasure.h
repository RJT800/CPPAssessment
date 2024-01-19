#pragma once
#include "Actor.h"

class Treasure : public Actor
{
public:
	/// <param name="scaleIncrease">The amount to increase the scale of the player by upon collision.</param>
	/// <param name="despawnTime">The amount of time it takes for a treasure piece to disappear from the level.</param>
	/// <param name="x">The x position in the world for this treasure piece.</param>
	/// <param name="y">The y position in the world for this treasure piece.</param>
	Treasure(float scaleIncrease, float despawnTime, float x, float y);

	void onCollision(Actor* other) override;
	void update(float deltaTime) override;

private:
	float m_scaleIncrease;
	float m_despawnTime;
	float m_currentTime;
};

