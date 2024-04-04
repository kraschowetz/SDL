#include "world.h"

Chunk World::getChunk(Vector2 position){
    return chunks.at(position.x).at(position.y);
}