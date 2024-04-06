#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <SDL2/SDL_image.h>
#include "../math/Vector2.h"
#include "../main/Collider.h"
#include "../world/Portal.h"

class World{
    //variables
    private:
        //gfx
        SDL_Renderer *renderer ;
        SDL_Surface *image = nullptr;
        SDL_Texture *texture = nullptr;
        //physics
        std::vector<Collider> collision;
        std::vector<Collider> portals;
        Vector2 offset;
        Vector2 camera;
        //pointers
        Collider *player;

    // methods
    public:
        void setRenderer(SDL_Renderer *r);
        void render();
        void loadWorld(std::string img_p, std::string data_p);
        void interpretPortalPass(int i);
        void initGraphics();
        void setPlayer(Collider *p);
        void setCameraPos(Vector2 pos);
        Vector2 getCamera();
        std::vector<Collider> getCollision();
        std::vector<Collider> getPortals();
        std::vector<std::string> split(std::string in);
};