#pragma once

#include <SDL2/Sdl.h>
#include "Entity.h"

class Player : public Entity{
    public:
        void pollEvents(SDL_Event ev);
        void update(float delta);
        void render(SDL_Renderer* r);
        
};