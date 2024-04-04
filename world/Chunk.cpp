#include "chunk.h"

void Chunk::render(SDL_Renderer* r){
    for(Tile tile : tiles){
        tile.render(r);
    }
}