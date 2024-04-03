#pragma once

#include "../math/Vector2.h"
#include <SDL2/SDL.h>

class Entity {

    //variables
    protected:
        float rotation;
        Vector2 position;
        Vector2 size;
        Vector2 velocity;
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