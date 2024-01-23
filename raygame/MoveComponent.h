#pragma once
#include "Component.h"
#include "Transform2D.h"
#include <Vector2.h>
class Actor;

class MoveComponent :
    public Component
{

public:
    //contructor for the movement component
    MoveComponent(float maxSpeed, Actor* owner);
    

    MathLibrary::Vector2 getVelocity() { return m_velocity; }
    void setVelocity(MathLibrary::Vector2 velocity) { m_velocity = velocity; }

    //getting and returning the max speed
    float getMaxSpeed() { return m_maxSpeed; }
    void setMaxSpeed(float maxSpeed) { m_maxSpeed = maxSpeed; }

    //update function
    void update(float deltaTime) override;

private:
    float m_maxSpeed;
    MathLibrary::Vector2 m_velocity;
};

