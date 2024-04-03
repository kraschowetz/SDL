#pragma once

#include "../math/Vector2.h"
#include <SDL2/SDL.h>

class Entity {

    //variables
    protected:
        Vector2 position;
        Vector2 size;
        SDL_Rect rect;
    // functions
    public:
        Entity();
        void update(float delta);
        void render(SDL_Renderer* r);
        // getters & setters
    public:
        Vector2 getPosition();
        SDL_Rect& getRect();


};