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
	// establishes movement
	MathLibrary::Vector2 position = getOwner()->getTransform()->getLocalPosition();
	MathLibrary::Vector2 velocity = getVelocity();

	//controls: when either button is pressesd, apply velocity in that direction and have the ship face that direction.
	//w
	if (Engine::getKeyDown(87))
	{
		setVelocity(getVelocity() + MathLibrary::Vector2(0, -1));
		getOwner()->getTransform()->setForward(MathLibrary::Vector2(0, -1));
	}
	//s
	else if (Engine::getKeyDown(83))
	{
		setVelocity(getVelocity() + MathLibrary::Vector2(0, 1));
		getOwner()->getTransform()->setForward(MathLibrary::Vector2(0, 1));
	}

	//a
	if (Engine::getKeyDown(65))
	{
		setVelocity(getVelocity() + MathLibrary::Vector2(-1, 0));
		getOwner()->getTransform()->setForward(MathLibrary::Vector2(-1, 0));
	}
	//d
	else if (Engine::getKeyDown(68))
	{
		setVelocity(getVelocity() + MathLibrary::Vector2(1, 0));
		getOwner()->getTransform()->setForward(MathLibrary::Vector2(1, 0));
	}


	//if the ship reaches max speed, cap it at the set max speed.
	if (getVelocity().getMagnitude() > getMaxSpeed())
	{
		MathLibrary::Vector2 newVelocity = getVelocity().getNormalized() * getMaxSpeed();
		setVelocity(newVelocity);
	}

	//applies the movement.
	position = position + getVelocity() * deltaTime;
	getOwner()->getTransform()->setLocalPosition(position);

}