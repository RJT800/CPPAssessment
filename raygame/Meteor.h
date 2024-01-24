#pragma once
#include "Actor.h"
#include <Vector2.h>

class Meteor :
    public Actor
{
public:
    Meteor(float x, float y, const char* name);

    void start() override;

    void update(float deltaTime) override;

    void onCollision(Actor* other) override;

private:
    MathLibrary::Vector2 m_direction;
    float m_speed = 50;
};

