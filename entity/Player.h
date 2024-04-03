#pragma once

#include <SDL2/Sdl.h>
#include <vector>
#include "Entity.h"
#include "../main/InputHandler.h"

class Player : public Entity{
    //functions
    public:
        void update(float delta);
        void render(SDL_Renderer* r);
        void move();
    //setters & getters
    public:
        void setInputHandler(InputHandler* in);
    //variables
    private:
        float speed = 320; 
        std::vector<int> inputStorage;
        Vector2 dir;
        InputHandler *inputHandler;
};