#pragma once
class Transform2D;
class Collider;
class Component;
#include "Actor.h"
#include "raylib.h"
class Player :
    public Actor
{

public:


    void update(float deltaTime);
    
    void draw();

};

