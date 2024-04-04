#include "Tile.h"

Tile::Tile(Vector2 _pos){
    this->position = _pos;
}

void Tile::render(SDL_Renderer* r){
    SDL_Rect rect;
    rect.x = position.x;
    rect.y = position.y;
    rect.w = 32.f;
    rect.h = 32.f;
    SDL_SetRenderDrawColor(r, 255, 255, 255, 255);
    SDL_RenderDrawRect(r, &rect);
}