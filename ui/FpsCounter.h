#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

class FpsCounter{   
    //funcitons
    public:
        void render(SDL_Renderer* r, float delta);
};

/*
    TODO:
    learn a bit about bitmap fonts.
    apparently bitmapfonts dont require surface & texture
    clearing every frame
*/