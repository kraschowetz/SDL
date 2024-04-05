#include "world.h"

/*
    this method loads the map image
*/
void World::initGraphics(SDL_Renderer *r){
    texture = SDL_CreateTextureFromSurface(
        nullptr, image);
}

void World::render(SDL_Renderer* r){
    if(texture == nullptr){
        texture = SDL_CreateTextureFromSurface(
            r, image
        );
    }
    SDL_Rect bounds = {
        0, 0, image->w, image->h
    };
    SDL_RenderCopy(
        r,
        texture, 
        nullptr,
        &bounds
    );
}