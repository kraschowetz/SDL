#pragma once

#include <vector>
#include <SDL2/SDL_image.h>
#include "../math/Vector2.h"


/*
    TODO:
        -proper file loading
        -world info file
        -world loading / unloading
*/

class World{
    //variables
    private:
        SDL_Surface *image = IMG_Load("res/TestScene.png");
        SDL_Texture *texture;
        // methods
    public:
        void render(SDL_Renderer* r);
        void initGraphics(SDL_Renderer* r);
};