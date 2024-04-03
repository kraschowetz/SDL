#pragma once

#include <SDL2/Sdl.h>
#include <vector>
#include "Entity.h"

class Player : public Entity{
    //functions
    public:
        void pollEvents(SDL_Event ev);
        void update(float delta);
        void render(SDL_Renderer* r);
        void move();
    //variables
    private:
        float speed = 320; 
        std::vector<int> inputStorage;
        Vector2 dir;
};