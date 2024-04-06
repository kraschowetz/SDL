#pragma once

#include <SDL2/Sdl.h>
#include <vector>
#include "Entity.h"
#include "../main/InputHandler.h"
#include "../main/Collider.h"
#include "../world/World.h"

class Player : public Entity{
    //functions
    public:
        Player();
        void update(float delta);
        void render(SDL_Renderer* r);
        void move();
        World* world;
    //setters & getters
    public:
        void setInputHandler(InputHandler* in);
        void setWorld(World* w);
        Collider getCol();
    //variables
    private:
        float speed = 320; 
        Vector2 dir;
        InputHandler *inputHandler;
        Collider collider;
};