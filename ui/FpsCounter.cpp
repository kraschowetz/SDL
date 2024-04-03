#include "FpsCounter.h"

#include <iostream>

void FpsCounter::render(SDL_Renderer* r, float delta){
    //open font
    TTF_Font *font = TTF_OpenFont(
        "assets/fonts/FiraCode.ttf", 12);
    //set color
    SDL_Color c_white = {
        255, 255, 255, 255};
        
    // create SDL_Surface from fps string
    SDL_Surface *textSurface = TTF_RenderText_Blended(
        font, std::string("fps " + 
        std::to_string(1.f / delta)).c_str(), c_white);
    // create a texture from surface
    SDL_Texture *text_t = SDL_CreateTextureFromSurface(
        r, textSurface);
    // get surface bounds
    SDL_Rect textBounds = {
        5, 5, textSurface->w, textSurface->h};
    // copy texture to render target(Renderer*)
    SDL_RenderCopy(r, text_t, nullptr, &textBounds);

    // free the surface
    SDL_FreeSurface(textSurface);
    // destroy texture
    SDL_DestroyTexture(text_t);
}