#include "MoveComponent.h"
#include "Transform2D.h"
#include "Actor.h"
#include "Engine.h"

MoveComponent::MoveComponent(float maxSpeed, Actor* owner) : Component(owner, "MoveComponent")
{
	m_maxSpeed = maxSpeed;
}

void MoveComponent::update(float deltaTime)
{
	MathLibrary::Vector2 position = getOwner()->getTransform()->getLocalPosition();
	MathLibrary::Vector2 facing = getOwner()->getTransform()->getForward();


	if (Engine::getKeyDown(87))
	{
		setVelocity(getVelocity() + MathLibrary::Vector2(1, 0));
	}
	else if (Engine::getKeyDown(83))
	{
		setVelocity(getVelocity() + MathLibrary::Vector2(-.9, 0));
	}

	if (Engine::getKeyDown(65))
	{
		facing = facing + MathLibrary::Vector2(1.1, 0);
	}
	else if (Engine::getKeyDown(68))
	{
		facing = facing + MathLibrary::Vector2(0.9, 0);
	}


	if (getVelocity().getMagnitude() > getMaxSpeed())
	{
		MathLibrary::Vector2 newVelocity = getVelocity().getNormalized() * getMaxSpeed();
		setVelocity(newVelocity);
	}

	position = position + getVelocity() * deltaTime;

	getOwner()->getTransform()->setLocalPosition(position);


}