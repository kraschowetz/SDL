#pragma once

#include "../math/Vector2.h"
#include <SDL2/SDL.h>

class Entity {

    //variables
    private:
        Vector2 position;
        Vector2 size;
        SDL_Rect rect;
    // functions
    public:
        Entity();
    // getters & setters
    public:
        Vector2 getPosition();
        SDL_Rect& getRect();


};