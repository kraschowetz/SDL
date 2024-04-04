#pragma once

#include <SDL2/SDL.h>
#include "../math/Vector2.h"

/*
    a tile is the visual representation of a map piece;
*/

class Tile{
    //variables
    private:
        Vector2 position;
    //methods
    public:
        Tile(Vector2 _pos);
        void render(SDL_Renderer* r);

};