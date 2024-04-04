#pragma once

#include <vector>
#include "Tile.h"

/*
    a chunk is a 16x16 grid that holds its maps pieces
*/

class Chunk{
    //variables
    std::vector<Tile> tiles;
    //methods
    void render(SDL_Renderer* r);
};