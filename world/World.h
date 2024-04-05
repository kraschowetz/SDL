#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <SDL2/SDL_image.h>
#include "../math/Vector2.h"
#include "../main/Collider.h"

class World{
    //variables
    private:
        //gpx
        SDL_Renderer *renderer ;
        SDL_Surface *image = nullptr;
        SDL_Texture *texture = nullptr;
        //physics
        std::vector<Collider> collision;

    // methods
    public:
        void setRenderer(SDL_Renderer *r);
        void render();
        void loadWorld(std::string img_p, std::string data_p);
        void interpretWorldDataLine(std::string l);
        void initGraphics();
        std::vector<Collider> getCollision();
        std::vector<std::string> split(std::string in);
};