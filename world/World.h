#pragma once

#include <vector>
#include "../math/Vector2.h"
#include "Chunk.h"


/*
    the world class loads and unloads chunks, tiles & entities
*/

class World{
    //variables
    private:
        std::vector<std::vector<Chunk>> chunks;
    //methods
    public:
        Chunk getChunk(Vector2 position);
};